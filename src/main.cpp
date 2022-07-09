#include <iostream>
#include <csignal>
#include "GPIO.h"

#include <gphoto2pp/helper_widgets.hpp>
#include <gphoto2pp/exceptions.hpp>
#include <gphoto2pp/camera_wrapper.hpp>
#include <gphoto2pp/window_widget.hpp>
#include <gphoto2pp/camera_widget_wrapper.hpp>
#include <gphoto2pp/value_widget_base.hpp>

#include "Window.h"
#include "Texture.h"
//
//void GLFWWindow_Resized(GLFWwindow* window, int width, int height) {
//    glViewport(0, 0, width, height);
//}

int main(int argc, char *argv[]) {
    gphoto2pp::CameraWrapper camera;
    std::cout << camera.getModel() << std::endl;
    std::cout << camera.getSummary() << std::endl;

    photobooth::GPIO GPIO;
    GPIO.registerGPIOPins();

    Window window(1920, 1080, "Photobooth");
    window.initialize();
//    glfwSetWindowSizeCallback(window.getHandle(), &GLFWWindow_Resized);
    window.centerWindow();

    int captures = 0;
    while (!window.windowShouldClose()) {
        GPIO.checkPinState(window);

        int windowSize[2];
        window.getSize(windowSize);
        glViewport(0, 0, windowSize[0], windowSize[1]);

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        auto preview = camera.capturePreview();

        auto captureTaster = GPIO.getTasterByName("CAPTURE");
        if(captureTaster) {
            if(captureTaster->getState()) {
                captureTaster->disableUntilReactivation();
            }
        }

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

        window.swapBuffers();
    }
    return 0;
}

//cameraFile.save("my-gphoto2pp-test.jpg");
