//
// Created by jona on 7/15/22.
//

#include "Photobooth.h"

#include "Utils.h"


Photobooth::Photobooth(): window(1920, 1080, "Photobooth"), imageView(window) {
    window.initialize();
    gpio.registerGPIOPins();
    cameraController.InitializeWidgets();
}

void Photobooth::update() {
    int windowSize[2];
    this->window.getSize(windowSize);

    glViewport(0, 0, windowSize[0], windowSize[1]);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(.0f, windowSize[0], windowSize[1], 0.0f, 0.0f, 1.0f);

    this->imageView.update(windowSize);
    if(cameraController.IsLiveViewAllowed()) {
        auto preview = cameraController.getViewfinderPreviewStream();
        imageView.setImage(preview);
    }
}

void Photobooth::updateInput() {
    this->gpio.checkPinState(this->window);
    auto prev = this->gpio.getTasterByName("PREV");
    auto print = this->gpio.getTasterByName("PRINT");
    auto next = this->gpio.getTasterByName("NEXT");
    auto capture = this->gpio.getTasterByName("CAPTURE");

    if(!prev && !print && !next && !capture) {
        throw std::runtime_error("Error while initializing Input keys");
    }

    if(capture->getState()) {
        this->cameraController.TakePicture("Photos/" + getDateString() + ".png");
        capture->disableUntilReactivation();
    }
}

void Photobooth::draw() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    imageView.render();
}

void Photobooth::runLoop() {
    while(!window.windowShouldClose()) {
        this->updateInput();
        this->update();
        this->draw();
        this->window.swapBuffers();
    }
}

int Photobooth::getShutdownStatusCode() const {
    return this->status_code;
}
