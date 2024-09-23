#pragma once 

#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector> 
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

unsigned int make_module(const string& filepath, unsigned int module_type);
unsigned int make_shader(const string& vertex_filepath, const string& fragment_filepath);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
string readShaderFile(const string &path);