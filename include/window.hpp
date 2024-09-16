//
// Created by @IceCurim on 16/09/2024.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <GLFW/glfw3.h>
#include <utils/logger.hpp>

namespace divide_engine{
    /**
     * @class Window
     * @brief Manages the creation and handling of a window.
     */
    class Window{
    private:
     std::shared_ptr<Logger> logger = Logger::get_instance();
     /**
     * @brief Window parameters
     * @param width : window width
     * @param height : window height
     * @param title : window title
     * @param window : window object that will be created by GLFW
     */
     int width = 0;
     int height = 0;
     std::string title;
     GLFWwindow* window = nullptr;

    public:
     Window(int width, int height, std::string title);
     ~Window();

     void open();

     /**
      * @brief Checks if the @window is created (open).
      * @return true if the @window is created (open), false otherwise.
      */
     [[nodiscard]] bool is_created()const;

     /**
      * @brief Sets default window parameters.
      */
     void set_defaults() const;

     /**
      * @brief Sets whether the window is resizable.
      * This is ignored for full screen windows and undecorated window (when @set_decorated is set to false).
      * @param resizable : true if the window should be resizable, false otherwise. By default, is true.
      */
     void set_resizable(bool resizable) const;

     /**
      * @brief Sets the visibility of the window.
      * This is ignored for full screen windows.
      * @param visible : true if the window should be visible, false otherwise. By default, is true.
      */
     void set_visible(bool visible) const;

     /**
      * @brief Sets whether the window is decorated (has borders and controls).
      * This is ignored for full screen windows.
      * @param decorated : true if the window should be decorated, false otherwise. By default, is true.
      */
     void set_decorated(bool decorated) const;

     /**
      * @brief Sets whether the window is focused.
      * This is ignored for full screen windows.
      * @param focused : true if the window should be focused, false otherwise. By default, is true.
      */
     void set_focused(bool focused) const;

     /**
      * @brief Sets whether the window is floating. Will the window be minimized when it loses focus?
      * This is ignored for windowed windows.
      * @param auto_iconify : true if the window should be minimized, false otherwise. By default, is false.
      */
     void set_auto_iconify(bool auto_iconify) const;

     /**
     * @brief Sets whether the window is floating above other windows (top-most or always-on-top).
     * This is ignored for full screen windows.
     * @param floating : true if the window should be floating, false otherwise. By default, is false.
     */
     void set_floating(bool floating) const;

    };
}

#endif //ENGINE_HPP
