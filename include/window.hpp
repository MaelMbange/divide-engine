//
// Created by @IceCurim on 16/09/2024.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>
#include <utils/logger.hpp>


namespace divide_engine {
    class Window {
        GLFWwindow* window = nullptr;
        std::shared_ptr<Logger> logger;

    public:
        Window();
        ~Window();

        [[nodiscard]] bool is_created() const;
        void close() const;
    };
}

#endif //WINDOW_HPP
