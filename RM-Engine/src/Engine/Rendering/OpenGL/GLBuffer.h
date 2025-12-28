/**
 * @file GLBuffer.h
 * @author sumin.park
 * @brief  OpenGL Buffers
 * @version 0.1
 * @date 12/28/2025 12:24:57 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Engine/Rendering/RHI/Buffer.h"
#include <glad/glad.h>

namespace rm
{
	class GLBuffer final : public Buffer
	{
	public:
		GLBuffer(const BufferDesc& desc);
		~GLBuffer() override;

		GLuint GetName() const { return name; }

	private:
		GLuint name = 0;
	};

} // rm namespace