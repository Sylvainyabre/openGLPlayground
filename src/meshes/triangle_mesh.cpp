#include "triangle_mesh.h"

TriangleMesh::TriangleMesh()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Vertex 1 (bottom left)
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // Vertex 2 (bottom right)
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f};  // Vertex 3 (top)
    vertex_count = 3;

    // Generate a Vertex Array Object (VAO) which will store all the state
    // related to vertex attribute configurations. This is necessary to keep track
    // of how vertex data is linked to the shader inputs.
    glGenVertexArrays(1, &VAO);

    // Bind the generated VAO to make it the active one. All vertex configuration calls
    // will now affect this VAO, making it easier to rebind configurations in the future.
    glBindVertexArray(VAO);

    // Generate a Vertex Buffer Object (VBO) that will store the actual vertex data
    // on the GPU. The VBO allows the vertex data to be efficiently passed to the graphics pipeline.
    glGenBuffers(1, &VBO);

    // Bind the VBO to the GL_ARRAY_BUFFER target, which tells OpenGL this buffer will contain vertex data.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Allocate memory and transfer the vertex data from the CPU to the GPU by passing
    // the vertices array into the VBO. We use GL_STATIC_DRAW because the vertex data is not expected to change frequently.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * sizeof(float), vertices, GL_STATIC_DRAW);

    // Define the first attribute pointer (index 0) which tells OpenGL how to interpret
    // the position data stored in the VBO. This links the position data to the shader's input.
    // Parameters:
    // - 0: Attribute location in the shader
    // - 3: Number of components per vertex (x, y, z)
    // - GL_FLOAT: Data type of each component
    // - GL_FALSE: We don't want normalized values
    // - 24: Byte stride between consecutive vertices (each vertex has 6 floats = 24 bytes)
    // - (void*)0: Offset where the position data starts in the buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void *)0);

    // Enable the vertex attribute at index 0 (position), allowing OpenGL to use it during rendering.
    glEnableVertexAttribArray(0);

    // Define the second attribute pointer (index 1) which tells OpenGL how to interpret
    // the color data stored in the VBO. This links the color data to the shader's input.
    // Parameters:
    // - 1: Attribute location in the shader
    // - 3: Number of components per vertex (r, g, b)
    // - GL_FLOAT: Data type of each component
    // - GL_FALSE: We don't want normalized values
    // - 24: Byte stride between consecutive vertices (each vertex has 6 floats = 24 bytes)
    // - (void*)12: Offset where the color data starts in the buffer (after the position data)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void *)12);

    // Enable the vertex attribute at index 1 (color), allowing OpenGL to use it during rendering.
    glEnableVertexAttribArray(1);
};

void TriangleMesh::draw()
{
       // Bind the previously created Vertex Array Object (VAO).
    // This makes it the active VAO, which contains the vertex attribute configurations.
    // This ensures that all subsequent draw calls will use the data stored and referenced by this VAO.
    glBindVertexArray(VAO);

    // Draw the vertices as triangles using the data in the currently bound VAO.
    // Parameters:
    // - GL_TRIANGLES: Specifies that the primitive type to render is triangles (each group of 3 vertices forms a triangle).
    // - 0: Starting index in the vertex array to begin drawing from.
    // - vertex_count: Number of vertices to render. This will draw vertex_count / 3 triangles.
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
};

TriangleMesh::~TriangleMesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}