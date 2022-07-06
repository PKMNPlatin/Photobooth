#include <iostream>
#include "GPIO.h"
#include "gphoto2pp/camera_wrapper.hpp"
#include "gphoto2pp/camera_file_wrapper.hpp"
#include "gphoto2pp/helper_camera_wrapper.hpp"

int main(int argc, char *argv[]) {
    gphoto2pp::CameraWrapper camera;
    std::cout << camera.getModel() << std::endl;
    std::cout << camera.getSummary() << std::endl;
    photobooth::GPIO GPIO;
    GPIO.registerGPIOPins();
    int i = 0;
    while (true) {
        GPIO.checkPinState();

        auto capturePin = GPIO.getTasterByPin(5);
        if (capturePin && capturePin->getState()) {
            gphoto2pp::CameraFileWrapper fileWrapper;
            gphoto2pp::helper::capture(camera, fileWrapper);
            fileWrapper.save("Test"+ std::to_string(i)+".png");
        }
    }
    return 0;
}
//cameraFile.save("my-gphoto2pp-test.jpg");
