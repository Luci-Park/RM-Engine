/**
 * @file GLVertexInput.cpp
 * @author sumin.park
 * @brief  OpenGL VertexInput
 * @version 0.1
 * @date 12/28/2025 12:40:54 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLVertexInput.h"
#include "GLBuffer.h"

namespace rm
{
	GLVertexInput::GLVertexInput(const VertexInputDesc& desc)
	{
        auto* glBuf = static_cast<GLBuffer*>(desc.vertexBuffer);

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, glBuf ? glBuf->GetName() : 0);

        for (uint32_t i = 0; i < desc.attributeCount; ++i)
        {
            const auto& a = desc.attributes[i];
            glEnableVertexAttribArray(a.location);
            glVertexAttribPointer(
                a.location,
                (GLint)a.components,
                GL_FLOAT,
                GL_FALSE,
                (GLsizei)desc.strideBytes,
                (const void*)(uintptr_t)a.offsetBytes
            );
        }

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GLVertexInput::~GLVertexInput()
	{
        if (vao) glDeleteVertexArrays(1, &vao);
	}
} // rm namespace