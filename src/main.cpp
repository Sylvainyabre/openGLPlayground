#include "config.h"
#include "triangle_mesh.h"

using namespace std;


int createWindow()
{
    GLFWwindow *window;
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;
    char windowTitle[] = "Sylvain's Awesome Window";
    string vertexShaderFile = "./shaders/vertex.txt";
    string fragmentShaderFile = "./shaders/fragment.txt";

    if (!glfwInit())
    {
        cout << "Error initializing GLFW \n"
             << endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
    if (!window)
    {
        cout << "Error creating window \n"
             << endl;
        glfwTerminate();
        return -1;
    };

    glfwMakeContextCurrent(window);
    // This should always come before any gl function is called
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }
    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    //Read shader files
    string vertexShaderSource = readShaderFile(vertexShaderFile);
    string fragmentShaderSource = readShaderFile(fragmentShaderFile);
    


    unsigned int shader = make_shader(
		"../src/shaders/vertex.txt", 
		"../src/shaders/fragment.txt"
	);
    TriangleMesh * triangle = new TriangleMesh();
    while (!glfwWindowShouldClose(window))
    {
        // checks if any events are triggered (like keyboard input or mouse movement events),
        glfwPollEvents();
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        triangle->draw();

        // handle double buffer
        glfwSwapBuffers(window);
       
       
        
        
    }
    


    

    

   
    glDeleteProgram(shader);
	delete triangle;

    cout << "Window Closed" << endl;
    glfwTerminate();
    return 0;
}
int main()
{
    cout << "Starting" << endl;
    // Define an array of vertices for a triangle.
    // Each vertex has 3 coordinates: x, y, and z.

    int result = createWindow();
    return result;
}