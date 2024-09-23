# Project Notes

## How to build and link GLFW from source on MAC OS
Even if you clone this repository with the GLFW header files and the static library `glfw3.a`, there is a chance that these will not work with your system. To compile these from source and link them on your MAC, follow these teps:
Before following these steps, make sure to install `cmake` by running `brew install cmake`.

1. Clone the repository by running `git clone https://github.com/glfw/glfw.git`
cmd+Shift+B to build.
2. Navigate into the cloned folder by running `cd glfw``
3. Create a directory where the build artifacts will go by running `mkdir build``
4. Navigate into the build folder `cd build``
5. Run `cmake .. -DBUILD_SHARED_LIBS=OFF`to configures the project to build static libraries by generating necessary build files (e.g., Makefile).
6. Run `make -j4`to compiles the code into binaries using 4 cores/threads based on the generated Makefile
7. In the cloned glfw project, open the "include" folder  and copy the subfolder "GLFW" into `dependencies/include`
8. There should now be a file names `glfw3.a`under `glfw/build/src`; copy that file and paste into your project directory `dependencies/libs/`
9. Once you complete the above steps, run `cmd+Shift+P`to bring up the vs code command palette. Search for Cmake and click `Cmake: configure`. Your project must be ready to be run at this point

For ease of running, do not forget to install the following vs code extensions: `CMake Tools`. There should now be a play symbol button at the bottom left of vs code that can be clicked to run the project

If encountering issues building, consider deleting `CMakeCache.txt`and redo step **9** above.

## Diagram of the Graphics Pipeline
![Graphics Pipeline](./src/assets/graphics_pipeline.png)


## New Concepts

- **Rasterization**:  
  Rasterization is the process of converting vector graphics (which use mathematical equations to represent images) into a raster image (a grid of pixels). This is essential for displaying images on screens, as it transforms shapes and colors into a format that can be rendered by your display device.

- **Shaders**:  
  Shaders are small programs that run on the GPU (Graphics Processing Unit) to control the rendering of graphics. They allow developers to define how objects appear on the screen by manipulating pixels and vertices. There are different types of shaders, including vertex shaders and fragment shaders, each serving a specific purpose in the graphics pipeline.

- **Double Buffer**:  
  Double buffering is a technique used to reduce flickering and tearing in graphics rendering. It involves using two buffers: one for displaying the current frame (the front buffer) and another for preparing the next frame (the back buffer). When the next frame is ready, the buffers are swapped, ensuring a smooth visual experience.

- **Primitives**:  
  Primitives are the basic building blocks of 3D graphics. They typically include simple shapes such as points, lines, and triangles. These shapes can be combined and manipulated to create more complex objects in a scene.

- **Vertex**:  
  A vertex is a point in 3D space that defines the corners of a primitive shape. Each vertex has properties like position, color, texture coordinates, and normal vectors, which are used to determine how the vertex interacts with light and texture in the scene.

- **Vertex Shader**:  
  A vertex shader is a type of shader that processes each vertex's data before it is rasterized. It takes input data (such as vertex positions and attributes), applies transformations (like rotation and scaling), and outputs the final vertex position and any additional data needed for the next stage of rendering.

- **Fragment**:
  A fragment in OpenGL is all the data required for OpenGL to render a single pixel

- **Vertex Buffer Objects (VBO)**:
  Vertex Buffer Objects (VBOs) are OpenGL objects that store vertex data in the GPU’s memory for efficient rendering. They allow developers to send large amounts of vertex data (like positions, colors, and texture coordinates) to the GPU in a single call, reducing the overhead of multiple draw calls. VBOs improve performance by minimizing data transfer between the CPU and GPU, making it easier to render complex 3D scenes smoothly.