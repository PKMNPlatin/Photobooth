#include <iostream>
#include <csignal>
#include <chrono>
#include "GPIO.h"

#include "CameraController.h"
#include "Window.h"
#include "Texture.h"
//
//void GLFWWindow_Resized(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}

using sysclock_t = std::chrono::system_clock;

const std::string CAPTURE_FILE_PATH = "Captures/";

std::string getDateString()
{
    std::time_t now = sysclock_t::to_time_t(sysclock_t::now());

    char buf[16] = { 0 };
    std::strftime(buf, sizeof(buf), "%Y-%m-%d_%H:%M:%S", std::localtime(&now));

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

    cameraController.Focus();

    while (!window.windowShouldClose()) {
        GPIO.checkPinState(window);

        auto pin = GPIO.getTasterByName("CAPTURE");
        if(pin) {
            if(pin->getState()) {
                //TODO: Get Main path from later GalleryComponent
                cameraController.TakePicture(getDateString() + ".png");
                pin->disableUntilReactivation();
            }
        }

        auto nextTaster = GPIO.getTasterByName("NEXT");
        if(nextTaster) {
            if(nextTaster->getState()) {
                cameraController.UpdateWidgets();
                nextTaster->disableUntilReactivation();
//                cameraController.Focus(focus);
            }
        }

        int windowSize[2];
        window.getSize(windowSize);
        glViewport(0, 0, windowSize[0], windowSize[1]);

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        if(cameraController.IsLiveViewAllowed()) {
            auto preview = cameraController.getViewfinderPreviewStream();
            Texture texture(preview);

            int quadSize = 1;

            texture.bind(0);
            glBegin(GL_QUADS);
            glTexCoord2d(0, 0);
            glVertex2d(-quadSize, -quadSize);
            glTexCoord2d(0, 1);
            glVertex2d(-quadSize, quadSize);
            glTexCoord2d(1, 1);
            glVertex2d(quadSize, quadSize);
            glTexCoord2d(1, 0);
            glVertex2d(quadSize, -quadSize);
            glEnd();
            texture.unbind();
        }

        window.swapBuffers();
    }
    return 0;
}

//cameraFile.save("my-gphoto2pp-test.jpg");
