#include <iostream>
#include <csignal>
#include "GPIO.h"
#include "gphoto2pp/camera_wrapper.hpp"

int main(int argc, char *argv[]) {
    gphoto2pp::CameraWrapper camera;
    std::cout << camera.getModel() << std::endl;
    std::cout << camera.getSummary() << std::endl;
    photobooth::GPIO GPIO;
    GPIO.registerGPIOPins();
    while (true) {
        GPIO.checkPinState();

        auto capturePin = GPIO.getTasterByPin(5);
        if (capturePin && capturePin->getState()) {

        }
        sleep(3);

    }
    return 0;
}
//cameraFile.save("my-gphoto2pp-test.jpg");
