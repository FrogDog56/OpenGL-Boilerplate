#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <Windows.h>

const unsigned int width = 1600;
const unsigned int height = 900;
const char* title = "Frog2D";

//gets windows screen res
void getDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;

   const HWND hDesktop = GetDesktopWindow();

   GetWindowRect(hDesktop, &desktop);

   horizontal = desktop.right;
   vertical = desktop.bottom;
}

int main()
{
    //glfw boilerplate
    glfwInit();

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //glfwWindowHint(GLFW_DECORATED, GLFW_FALSE); //borderless

    int horizontal = 0;
    int vertical = 0;
    getDesktopResolution(horizontal, vertical);

    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    //sets window to center of screen 
    glfwSetWindowPos(window, horizontal / 2 - width / 2, vertical / 2 - height / 2);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, width, height);

    //main loop
    while (!glfwWindowShouldClose(window)) 
    {
        glClearColor(0.17f, 0.13f, 0.17f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //close window
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}