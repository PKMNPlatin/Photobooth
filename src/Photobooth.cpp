//
// Created by jona on 7/15/22.
//

#include "Photobooth.h"
#include <Window.h>

#include "Utils.h"


Photobooth::Photobooth(): window(1920, 1080, "Photobooth"), liveView(window), imageGallery("Images/", window) {
    window.initialize();
    gpio.registerGPIOPins();
    imageGallery.initialize();
}

void Photobooth::updateInput() {
    this->gpio.checkPinState(this->window);
    auto *pPrev = this->gpio.getTasterByName("PREV");
    auto *pPrint = this->gpio.getTasterByName("PRINT");
    auto *pNext = this->gpio.getTasterByName("NEXT");
    auto *pCapture = this->gpio.getTasterByName("CAPTURE");

    if(!pPrev && !pPrint && !pNext && !pCapture) {
        this->status_code = 1;
        throw std::runtime_error("Error while initializing Input keys");
    }

    //TODO:
    /*
     * Check if Prev or Next PinButtons are pressed - if Prev is Pressed and currently in Gallery, go one image back, otherwise close the gallery and go back to viewfinder
     * if next is pressed and the gallery is closed, open the gallery with the first image of the folder, otherwise show the next image, if there are not images left, just display the last one
     *
     */

    if(pNext->getState()) {
        if(imageGallery.isActive()) {
            imageGallery.nextImage();
        } else {
            imageGallery.open();
        }
        pNext->disableUntilReactivation();
        return;
    }

    if(pPrev->getState()) {
        if(imageGallery.isActive()) {
            imageGallery.previousImage();
        }
        pPrev->disableUntilReactivation();
        return;
    }

    if(pCapture->getState()) {
        if (this->imageGallery.isActive()) {
            this->imageGallery.close();
        } else {
            const auto path = imageGallery.getRootPath() + getDateString() + ".png";
            this->cameraController.TakePicture(path);
            this->imageGallery.addImageToGallery(path);
        }
        pCapture->disableUntilReactivation();
        return;
    }
}

void Photobooth::update() {
    int windowSize[2];
    this->window.getSize(windowSize);

    glViewport(0, 0, windowSize[0], windowSize[1]);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, windowSize[0], windowSize[1], 0.0f, 0.0f, 1.0f);

    this->imageGallery.update(windowSize);
    this->liveView.update(windowSize);
    if(this->cameraController.IsLiveViewAllowed()) {
        auto preview = this->cameraController.getViewfinderPreviewStream();
        this->liveView.setImage(preview);
        cameraController.EnableAutoFocus();
    }
}

void Photobooth::draw() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    this->liveView.render();
    this->imageGallery.render();
}

void Photobooth::runLoop() {
    while(!this->window.windowShouldClose()) {
        this->updateInput();
        this->update();
        this->draw();
        this->window.swapBuffers();
    }
}

int Photobooth::getShutdownStatusCode() const {
    return this->status_code;
}
