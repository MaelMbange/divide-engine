#include <fstream>
#include "utils/logger.hpp"
#include <GLFW/glfw3.h>
#include <window.hpp>

using namespace divide_engine;

using namespace std::string_literals;
int main()
{
    // GLFWwindow* window;
    //
    // /* Initialize the library */
    // if (!glfwInit())
    //     return -1;
    //
    // /* Create a windowed mode window and its OpenGL context */
    // window = glfwCreateWindow(640, 480, "Divide", NULL, NULL);
    // if (!window)
    // {
    //     glfwTerminate();
    //     return -1;
    // }
    //
    // /* Make the window's context current */
    // glfwMakeContextCurrent(window);
    //
    // /* Loop until the user closes the window */
    // while (!glfwWindowShouldClose(window))
    // {
    //     /* Render here */
    //     glClear(GL_COLOR_BUFFER_BIT);
    //
    //     /* Swap front and back buffers */
    //     glfwSwapBuffers(window);
    //
    //     /* Poll for and process events */
    //     glfwPollEvents();
    // }
    //
    // glfwTerminate();
    // return 0;

    const auto logger = Logger::get_instance(true,true);
    logger->log("Hello world");


    // if (!glfwInit()) {
    //     logger.log("GLFW could not be initialized", LogLevel(LogLevel::Level::ERROR));
    // }
    //
    // Window window;

    return 0;
}