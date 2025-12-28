/**
 * @file GLPipeline.h
 * @author sumin.park
 * @brief  OpenGL pipeline
 * @version 0.1
 * @date 12/28/2025 12:37:24 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Engine/Rendering/RHI/Pipeline.h"
#include <glad/glad.h>

namespace rm
{
	class GLPipeline final : public Pipeline
	{
	public:
		GLPipeline(const PipelineDesc& desc);
		~GLPipeline() override;

		GLuint GetProgram() const { return program; }

	private:
		GLuint program = 0;
	};

} // rm namespace