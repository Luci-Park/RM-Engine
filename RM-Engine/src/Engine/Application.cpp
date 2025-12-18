/**
 * @file Application.cpp
 * @author sumin.park
 * @brief The application class that the app will inherit.
 * @version 0.1
 * @date 12/16/2025 3:47:59 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Application.h"
#include <GLFW/glfw3.h>

namespace rm
{
	GLFWwindow* window = nullptr;
	void Application::Init()
	{
		RM_ASSERT(glfwInit());
		
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);\

		window = glfwCreateWindow(
			1280,
			720,
			"GLFW Window (No OpenGL)",
			nullptr,
			nullptr
		);
	}

	void Application::Run() 
	{
		RM_ASSERT(window != nullptr);
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
	}

	void Application::Shutdown()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}
