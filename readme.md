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
