#include "config.h"

using namespace std;

// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
// glViewport(0, 0, width, height);
// }

// void processInput(GLFWwindow *window)
// {
// if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
// glfwSetWindowShouldClose(window, true);
// }


int createWindow()
{
    GLFWwindow *window;
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    char windowTitle[] = "Sylvain's Awesome Window";

    if (!glfwInit())
    {
        cout << "Error initializing GLFW \n"
             << endl;
        return -1;
    }
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
    if (!window)
    {
        cout << "Error creating window \n"
             << endl;
        glfwTerminate();
        return -1;
    };
    // glViewport(0, 0, windowWidth, windowHeight);
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    // {
    //     cout << "Failed to initialize GLAD" << endl;
    //     return -1;
    // }
    while (!glfwWindowShouldClose(window))
    {
        // processInput(window);
        glClear(GL_COLOR_BUFFER_BIT);
        //handle double buffer
        glfwSwapBuffers(window);
        //checks if any events are triggered (like keyboard input or mouse movement events),
        glfwPollEvents();
    }
    cout << "Application run" << endl;
    glfwTerminate();
    return 0;
}
int main()
{
    cout << "Starting" << endl;
    
    int result = createWindow();
    return result;
}