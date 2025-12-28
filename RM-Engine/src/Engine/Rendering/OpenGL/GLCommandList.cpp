/**
 * @file GLCommandList.cpp
 * @author sumin.park
 * @brief  OpenGL Command list
 * @version 0.1
 * @date 12/27/2025 11:24:11 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLCommandList.h"
#include "GLPipeline.h"
#include "GLVertexInput.h"
#include <glad/glad.h>

namespace rm
{
	GLCommandList::GLCommandList()
	{
	}

	GLCommandList::~GLCommandList()
	{
	}

	void GLCommandList::BeginFrame()
	{
	}

	void GLCommandList::EndFrame()
	{
	}

	void GLCommandList::SetViewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
	{
		glViewport(x, y, w, h);
	}

	void GLCommandList::ClearScreen(float r, float g, float b, float a)
	{
		//set clear color state
		glClearColor(r, g, b, a);
		
		//apply state
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GLCommandList::BindPipeline(Pipeline* pip)
	{
		pipeline = static_cast<GLPipeline*>(pip);
		glUseProgram(pipeline ? pipeline->GetProgram() : 0);
	}

	void GLCommandList::BindVertexInput(VertexInput* vi)
	{
		vertexInput = static_cast<GLVertexInput*>(vi);
		glBindVertexArray(vertexInput ? vertexInput->VAO() : 0);
	}

	void GLCommandList::Draw(uint32_t vertexCount)
	{
		if (!pipeline || !vertexInput) return;
		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertexCount);
	}
} // rm namespace