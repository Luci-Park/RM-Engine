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

#include "Input/Input.h"

namespace rm
{
	GLFWwindow* window = nullptr;
	void Application::Init()
	{
		window = Window::Create();
		isRunning = true;
	}

	void Application::Run() 
	{
		while (isRunning)
		{
			window->Update();
			if (Input::IsKeyPressed(GLFW_KEY_SPACE))
			{
				LOG_INFO("Space bar is pressed.");
			}
		}
	}

	void Application::Shutdown()
	{
	}
}
