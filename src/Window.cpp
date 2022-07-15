//
// Created by jona on 7/9/22.
//

#include <stdexcept>
#include <iostream>
#include "Window.h"

Window::Window(int width_, int height_, const std::string &title_) : width(width_), height(height_)
{
};

Window::~Window() {
    if(this->window) {
        this->destroy();
    }
};

void Window::getSize(int result[2]) {
    glfwGetWindowSize(this->window, &result[0], &result[1]);
};

void Window::initialize()
{
    if(!glfwInit()) {
        return;
    }
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!this->window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW Window " + title);
    }
    this->centerWindow();
    glfwMakeContextCurrent(this->window);
    glfwShowWindow(this->window);
    std::cout << glGetString(GL_VERSION) << std::endl;
};

void Window::centerWindow()
{
    int windowSize[2];
    glfwGetWindowSize(this->window, &windowSize[0], &windowSize[1]);
    const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(this->window, (vidMode->width - windowSize[0]), (vidMode->height - windowSize[1]));
};

void Window::destroy()
{
    glfwDestroyWindow(this->window);
    this->window = nullptr;
};

GLFWwindow* Window::getHandle() {
    return this->window;
}

bool Window::windowShouldClose()
{
    return glfwWindowShouldClose(this->window);
};

void Window::swapBuffers()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
};