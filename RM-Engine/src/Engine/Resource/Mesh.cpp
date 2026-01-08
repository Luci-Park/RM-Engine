/**
 * @file Mesh.cpp
 * @author sumin.park
 * @brief  Mesh class which has geometric info
 * @version 0.1
 * @date 1/8/2026 12:48:36 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Mesh.h"

namespace rm
{
    Mesh* Mesh::CreateTriangleMesh() {
        Vertex vertices[] =
            {
            {-0.5f, -0.5f},
            {0.5f, -0.5f},
            {0.0f, 0.5f}
        };

        unsigned int indices[] ={
            0, 1, 2
        };
        Mesh mesh;
        mesh.indexCount = 3;
        glGenVertexArrays(1, &mesh.vao);
        glBindVertexArray(mesh.vao);

        glGenBuffers(1, &mesh.vbo);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &mesh.ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // position attribute (location = 0)
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,  // location
                              2,  // vec2
                              GL_FLOAT,
                              GL_FALSE,
                              sizeof(Vertex2D),
                              (void*) 0);

        glBindVertexArray(0);
        return mesh;
    }
} // rm namespace