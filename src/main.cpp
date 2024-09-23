#include "config.h"


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

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // handle double buffer
        glfwSwapBuffers(window);
        // checks if any events are triggered (like keyboard input or mouse movement events),
        glfwPollEvents();
    }
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // Vertex 1 (bottom left)
        0.5f, -0.5f, 0.0f,  // Vertex 2 (bottom right)
        0.0f, 0.5f, 0.0f};  // Vertex 3 (top)

    // Declare an unsigned integer to hold the buffer ID.
    unsigned int VBO;

    // Generate one buffer and store its ID in VBO.
    glGenBuffers(1, &VBO);

    // Bind the VBO to the GL_ARRAY_BUFFER target. This makes the VBO the active buffer,
    // so all subsequent operations (like uploading vertex data) will affect this buffer.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Upload the vertex data to the GPU.
    // GL_STATIC_DRAW indicates that the data will not change, allowing for optimization.
    // GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
    // GL_STATIC_DRAW: the data is set only once and used many times.
    // GL_DYNAMIC_DRAW: the data is changed a lot and used many times
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    //Read shader files
    string vertexShaderSource = readShaderFile(vertexShaderFile);
    string fragmentShaderSource = readShaderFile(fragmentShaderFile);
    


    unsigned int shader = make_shader(
		"../src/shaders/vertex.txt", 
		"../src/shaders/fragment.txt"
	);

    glDeleteProgram(shader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);

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