/**
 * @file GLBuffer.cpp
 * @author sumin.park
 * @brief  OpenGL Buffers
 * @version 0.1
 * @date 12/28/2025 12:24:57 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLBuffer.h"

namespace rm
{
	GLBuffer::GLBuffer(const BufferDesc& desc)
	{
		glGenBuffers(1, &name);
		glBindBuffer(GL_ARRAY_BUFFER, name);
		glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)desc.sizeBytes, desc.data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GLBuffer::~GLBuffer()
	{
		if (name) glDeleteBuffers(1, &name);
	}
} // rm namespace