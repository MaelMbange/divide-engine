#include <window.hpp>
#include <GLFW/glfw3.h>
#include "utils/logger.hpp"

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
    if (!glfwInit())
        return -1;

    Window window(640, 480, "Divide");
    // window.set_resizable(false);
    // window.set_visible(false);
    // window.set_decorated(false);
    // window.set_focused(false);
    // window.set_auto_iconify(true);
    // window.set_floating(false);
    window.open();
    glfwTerminate();

    return 0;
}