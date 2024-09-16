//
// Created by @IceCurim on 16/09/2024.
//

#include "window.hpp"

#include <cmath>
#include <GLFW/glfw3.h>
#include <utility>

using namespace divide_engine;
using namespace std::string_literals;

Window::Window(const int width, const int height, std::string title) : width(width), height(height), title(std::move(title)) {
        logger->log("Window created", LogLevel(LogLevel::Level::SUCCESS));
}

Window::~Window() {
    if(is_created()) {
        glfwDestroyWindow(window);
        logger->log("Window destroyed", LogLevel(LogLevel::Level::TERMINATED));
    }
}

void Window::open() {
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(is_created()) {
        logger->log("Window opened", LogLevel(LogLevel::Level::SUCCESS));

        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        logger->log("Window closed", LogLevel(LogLevel::Level::CLOSED));
    }else {
        logger->log("Window failed to open", LogLevel(LogLevel::Level::ERROR));
    }
}

bool Window::is_created() const {
    return window != nullptr;
}

void Window::set_defaults() const {
    if(!is_created()) {
        glfwDefaultWindowHints();
        logger->log("Set window defaults", LogLevel(LogLevel::Level::INFO));
    }else{
        logger->log("Set window defaults failed", LogLevel(LogLevel::Level::ERROR));
    }
}

void Window::set_resizable(const bool resizable) const{
    if(!is_created()) {
        glfwWindowHint(GLFW_RESIZABLE, resizable? GLFW_TRUE : GLFW_FALSE);
        logger->log("Set window hint: __resizable__", LogLevel(LogLevel::Level::INFO));
    }else{
        logger->log("Set window hint: __resizable__, must be set before creating the window (open)", LogLevel(LogLevel::Level::ERROR));
    }
}

void Window::set_visible(const bool visible) const {
    if(!is_created()) {
        glfwWindowHint(GLFW_VISIBLE, visible? GLFW_TRUE : GLFW_FALSE);
        logger->log("Set window hint: __visible__"s.append(" = ").append(visible?"TRUE":"FALSE"), LogLevel(LogLevel::Level::INFO));
    }else{
        logger->log("Set window hint: __visible__, must be set before creating the window (open)", LogLevel(LogLevel::Level::ERROR));
    }
}

void Window::set_decorated(const bool decorated) const {
    if(!is_created()) {
        glfwWindowHint(GLFW_DECORATED, decorated? GLFW_TRUE : GLFW_FALSE);
        logger->log("Set window hint: __decorated__"s.append(" = ").append(decorated?"TRUE":"FALSE"), LogLevel(LogLevel::Level::INFO));
    }else{
        logger->log("Set window hint: __decorated__, must be set before creating the window (open)", LogLevel(LogLevel::Level::ERROR));
    }
}

void Window::set_focused(const bool focused) const {
    if(!is_created()) {
        glfwWindowHint(GLFW_FOCUSED, focused? GLFW_TRUE : GLFW_FALSE);
        logger->log("Set window hint: __focused__"s.append(" = ").append(focused?"TRUE":"FALSE"), LogLevel(LogLevel::Level::INFO));
    }else{
        logger->log("Set window hint: __focused__, must be set before creating the window (open)", LogLevel(LogLevel::Level::ERROR));
    }
}

void Window::set_auto_iconify(const bool auto_iconify) const {
    if(!is_created()) {
        glfwWindowHint(GLFW_AUTO_ICONIFY, auto_iconify? GLFW_TRUE : GLFW_FALSE);
        logger->log("Set window hint: __auto_iconify__"s.append(" = ").append(auto_iconify?"TRUE":"FALSE"), LogLevel(LogLevel::Level::INFO));
    }else{
        logger->log("Set window hint: __auto_iconify__, must be set before creating the window (open)", LogLevel(LogLevel::Level::ERROR));
    }
}

void Window::set_floating(const bool floating) const {
    if(!is_created()) {
        glfwWindowHint(GLFW_FLOATING, floating? GLFW_TRUE : GLFW_FALSE);
        logger->log("Set window hint: __floating__"s.append(" = ").append(floating?"TRUE":"FALSE"), LogLevel(LogLevel::Level::INFO));
    }else{
        logger->log("Set window hint: __floating__, must be set before creating the window (open)", LogLevel(LogLevel::Level::ERROR));
    }
}
