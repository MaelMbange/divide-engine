//
// Created by @IceCurim on 16/09/2024.
//
#include "window.hpp"


using namespace divide_engine;

Window::Window() : logger(Logger::get_instance(true,true)){
}

Window::~Window() {
}

bool Window::is_created() const{
    return true;
}

void Window::close() const {
    glfwDestroyWindow(window);
}
