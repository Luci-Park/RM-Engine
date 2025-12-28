/**
 * @file GLRenderContext.h
 * @author sumin.park
 * @brief  OpenGLRenderContext
 * @version 0.1
 * @date 12/27/2025 11:04:48 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "../RHI/RenderContext.h"

struct GLFWwindow;

namespace rm
{
	class GLRenderContext final : public RenderContext
	{
	public:
		GLRenderContext(const WindowHandle& handle);
		~GLRenderContext() override = default;
		void SetAsCurrent() override;

	private:
		GLFWwindow* window;
	};

} // rm namespace