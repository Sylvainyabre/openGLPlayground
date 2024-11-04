#include "config.h"
#include <filesystem>


unsigned int make_shader(const string &vertex_filepath, const string &fragment_filepath)
{

    // To store all the shader modules
    vector<unsigned int> modules;

    // Add a vertex shader module
    modules.push_back(make_module(vertex_filepath, GL_VERTEX_SHADER));

    // Add a fragment shader module
    modules.push_back(make_module(fragment_filepath, GL_FRAGMENT_SHADER));
   
    unsigned int shader = 0;
     // Tell opengl to create a shader program

    shader = glCreateProgram();
    for (unsigned int shaderModule : modules)
    {
        // Tell opengl to attach the shader module to the shader program
        // Shader program linking
        
        glAttachShader(shader, shaderModule);
    }
    // Tell opengl to link the modules of the shader program
    glLinkProgram(shader);

    // Check the linking worked
    int success;
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success)
    {
        char errorLog[1024];
        glGetProgramInfoLog(shader, 1024, NULL, errorLog);
        cout << "Shader linking error:\n"
             << errorLog << '\n';
    }

    // Modules are now unneeded and can be freed
    for (unsigned int shaderModule : modules)
    {
         glDeleteShader(shaderModule);
    }

    return shader;
}

unsigned int make_module(const string &filepath, unsigned int module_type)
{

    ifstream file;
    stringstream bufferedLines;
    string line;

    file.open(filepath);
    while (getline(file, line))
    {
       
        bufferedLines << line << '\n';
    }
    string shaderSource = bufferedLines.str();
    const char *shaderSrc = shaderSource.c_str();

    bufferedLines.str();
    file.close();

    //Create a shader module
   unsigned int shaderModule = glCreateShader(module_type);
    glShaderSource(shaderModule, 1, &shaderSrc, NULL);
    // Tell opengl to compile the shader module
    glCompileShader(shaderModule);
    int success;
    glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char errorLog[1024];
        glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
        cout << "Shader Module compilation error:\n"
             << errorLog << endl;
    }

    return shaderModule;
}


void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/**
 * Reads a shader file given its path 
 */
string readShaderFile(const string &path)
{
    ifstream fileStream(path);
    if (!fileStream)
    {
        cout << "Error opening file " << path << endl;
        return "";
    }

    stringstream buffer;
    buffer << fileStream.rdbuf(); // Read the file into the buffer

    // Check for reading errors
    if (fileStream.fail())
    {
        cout << "Error reading file " << path << endl;
        return "";
    }


    // Close the file after reading
    fileStream.close();
    return buffer.str();
};
