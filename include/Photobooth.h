//
// Created by jona on 7/15/22.
//

#ifndef PHOTOBOOTH_PHOTOBOOTH_H
#define PHOTOBOOTH_PHOTOBOOTH_H


#include "Window.h"
#include "ImageView.h"
#include "GPIO.h"
#include "CameraController.h"
#include "ImageGallery.h"

class Photobooth {

    int status_code = 0;

    Window window;
    ImageView liveView;
    ImageGallery imageGallery;

    CameraController cameraController;
    GPIO gpio;

    void update();
    void updateInput();
    void draw();

public:

    Photobooth();
    void runLoop();

    int getShutdownStatusCode() const;

};


#endif //PHOTOBOOTH_PHOTOBOOTH_H
