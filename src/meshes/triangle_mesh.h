#include <config.h>


class TriangleMesh{
    public:
        TriangleMesh();
        void draw();
        ~TriangleMesh();
    private:
        unsigned int vertex_count;
        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;

};