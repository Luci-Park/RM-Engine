/**
 * @file GLSwapchain.cpp
 * @author sumin.park
 * @brief  OpenGL Swapchain
 * @version 0.1
 * @date 12/27/2025 11:55:03 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLSwapchain.h"

#include <GLFW/glfw3.h>

namespace rm
{
	GLSwapchain::GLSwapchain(GLFWwindow* window)
		:window(window)
	{
	}

	void GLSwapchain::Resize(uint32_t width, uint32_t height)
	{
		this->width = width;
		this->height = height;
	}

	void GLSwapchain::Present()
	{
		glfwSwapBuffers(window);
	}

	void GLSwapchain::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
	}
} // rm namespace