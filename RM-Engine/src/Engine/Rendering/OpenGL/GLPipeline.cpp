/**
 * @file GLPipeline.cpp
 * @author sumin.park
 * @brief  OpenGL pipeline
 * @version 0.1
 * @date 12/28/2025 12:37:24 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLPipeline.h"

#include "GLUtil.h"

namespace rm
{
	GLPipeline::GLPipeline(const PipelineDesc& desc)
	{
		auto vs = CompileShader(GL_VERTEX_SHADER, desc.vertex);
		auto fs = CompileShader(GL_FRAGMENT_SHADER, desc.fragment);
		program = (GLuint)LinkProgram(vs, fs);
	}

	GLPipeline::~GLPipeline()
	{
		if (program) glDeleteProgram(program);
	}
} // rm namespace