/**
 * @file WindowsWindow.cpp
 * @author sumin.park
 * @brief  Window class for the Windows OS
 * @version 0.1
 * @date 12/18/2025 12:19:10 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "WindowsWindow.h"

#include <GLFW/glfw3.h>

namespace rm
{
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}
	void WindowsWindow::Init(const WindowProps& props)
	{
		windowData.Title = props.Title;
		windowData.Width = static_cast<int>(props.Width);
		windowData.Height = static_cast<int>(props.Height);
		windowData.VSync = props.VSync;

		RM_ASSERT(glfwInit());

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str()
			, nullptr, nullptr);

		RM_ASSERT(window);

		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &windowData);

		SetVsync(windowData.VSync);
		
	}

	void WindowsWindow::SetVsync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		windowData.VSync = enable;
	}

	void WindowsWindow::Update()
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(window);
		window = nullptr;
		glfwTerminate();
	}


} // rm namespace