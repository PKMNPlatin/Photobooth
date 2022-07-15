#include <iostream>
#include <csignal>
#include <chrono>
#include "GPIO.h"

#include "CameraController.h"
#include "Window.h"
#include "Texture.h"
#include "ImageView.h"
//
//void GLFWWindow_Resized(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}

using sysclock_t = std::chrono::system_clock;

std::string getDateString()
{
    std::time_t now = sysclock_t::to_time_t(sysclock_t::now());

    char buf[32] = { 0 };
    std::strftime(buf, sizeof(buf), "%Y-%m-%d_%H-%M-%S", std::localtime(&now));

    return std::string(buf);
}

int main(int argc, char *argv[]) {
    CameraController cameraController;
    cameraController.InitializeWidgets();
    photobooth::GPIO GPIO;
    GPIO.registerGPIOPins();

    Window window(1920, 1080, "Photobooth");
    window.initialize();
    window.centerWindow();
    ImageView imageView(window);

    cameraController.EnableAutoFocus();

    while (!window.windowShouldClose()) {
        GPIO.checkPinState(window);

        auto pPinCapture = GPIO.getTasterByName("CAPTURE");
        if(pPinCapture && pPinCapture->getState()) {
            //TODO: Get Main path from later GalleryComponent
            std::cout << getDateString() << std::endl;
            cameraController.TakePicture(getDateString() + ".png");
            pPinCapture->disableUntilReactivation();
            continue;
        }

        auto nextTaster = GPIO.getTasterByName("NEXT");
        if(nextTaster && nextTaster->getState()) {
                cameraController.UpdateWidgets();
                nextTaster->disableUntilReactivation();
//                cameraController.EnableAutoFocus(focus);
        }

        int windowSize[2];
        window.getSize(windowSize);
        glViewport(0, 0, windowSize[0], windowSize[1]);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(.0f, windowSize[0], windowSize[1], 0.0f, 0.0f, 1.0f);
        imageView.update(windowSize);

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        if(cameraController.IsLiveViewAllowed()) {
            auto preview = cameraController.getViewfinderPreviewStream();
            imageView.setImage(preview);
        }
        imageView.render();
        window.swapBuffers();
    }
    return 0;
}

//cameraFile.save("my-gphoto2pp-test.jpg");
