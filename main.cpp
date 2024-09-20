#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

void createObj(){
    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600

    //create object
    unsigned int objectId = 0;
    glGenObject(1,&objectId);

    //bind object to context
    glBindObject(GL_WINDOW_TARGET,objectId);
    //set options of object currently bound to GL_WINDOW_TARGET
    glSetObjectOption(GL_WINDOW_TARGET,GL_OPTION_WINDOW_WIDTH,windowWidth);
    glSetObjectOption(GL_WINDOW_TARGET,GL_OPTION_WINDOW_WIDTH,windowHeight);

    //Set context back to default
    glBindObject(GL_WINDOW_TARGET,0)



}

int  main(){
    cout<<"Hello world \n";
    return 0;
}