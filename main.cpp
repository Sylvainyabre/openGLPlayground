#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

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
    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
    if (!window)
    {
        cout << "Error creating window \n"
             << endl;
        glfwTerminate();
        return -1;
    };

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
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