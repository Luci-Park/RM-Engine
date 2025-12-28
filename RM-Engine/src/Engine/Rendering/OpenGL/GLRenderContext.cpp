/**
 * @file GLRenderContext.cpp
* @author sumin.park
 * @brief  OpenGLRenderContext
 * @version 0.1
 * @date 12/27/2025 11:04:48 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLRenderContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace rm
{
	static void APIENTRY GLDebugCallback(
		GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar* message, const void*)
	{
		LOG_INFO("[GL DEBUG] {}", message);
	}

	GLRenderContext::GLRenderContext(const WindowHandle& handle)
	{
		if (handle.type != WindowType::GLFW || !handle.window)
		{
			LOG_CRITICAL("[RHI][GL] Invalid surface (expected GLFWwindow*)");
			return;
		}

		window = static_cast<GLFWwindow*>(handle.window);

		bool ok = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if (!ok)
			LOG_CRITICAL("Failed to initialize GLAD");

		if (glDebugMessageCallback)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(GLDebugCallback, nullptr);
		}
	}

	void GLRenderContext::SetAsCurrent()
	{
		glfwMakeContextCurrent(window);
	}
} // rm namespace