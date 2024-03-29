//
// Created by jona on 7/9/22.
//

#ifndef PHOTOBOOTH_WINDOW_H
#define PHOTOBOOTH_WINDOW_H

#include "GLFW/glfw3.h"

#include <string>

class Window
{
    GLFWwindow *window;
    int width;
    int height;
    std::string title;
    float delta;
    float frameTime;

public:
    Window(int width_, int height_, std::string title_);
    ~Window();
    void getSize(int result[2]);
    void initialize();
    void centerWindow();

    GLFWwindow* getHandle();

    void destroy();
    bool windowShouldClose();
    void swapBuffers();

};


#endif //PHOTOBOOTH_WINDOW_H
