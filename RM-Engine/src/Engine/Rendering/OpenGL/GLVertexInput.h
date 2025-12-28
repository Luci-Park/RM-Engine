/**
 * @file GLVertexInput.h
 * @author sumin.park
 * @brief  OpenGL VertexInput
 * @version 0.1
 * @date 12/28/2025 12:40:54 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Engine/Rendering/RHI/VertexInput.h"
#include <glad/glad.h>

namespace rm
{
	class GLVertexInput final : public VertexInput
	{
    public:
        GLVertexInput(const VertexInputDesc& desc);
        ~GLVertexInput() override;

        GLuint VAO() const { return vao; }

    private:
        GLuint vao = 0;
	};

} // rm namespace