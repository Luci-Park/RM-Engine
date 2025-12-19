/**
 * @file WinGLFWWindow.cpp
 * @author sumin.park
 * @brief  Window class for the Windows OS
 * @version 0.1
 * @date 12/18/2025 12:19:10 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "WinGLFWwindow.h"

#include <GLFW/glfw3.h>

#include "Engine/Input/Input.h"

namespace rm
{
	WinGLFWwindow::WinGLFWwindow(const WindowProps& props)
	{
		Init(props);
	}

	WinGLFWwindow::~WinGLFWwindow()
	{
		Shutdown();
	}
	void WinGLFWwindow::Init(const WindowProps& props)
	{
		windowData.Title = props.Title;
		windowData.Width = static_cast<int>(props.Width);
		windowData.Height = static_cast<int>(props.Height);
		windowData.VSync = props.VSync;

		RM_ASSERT(glfwInit());

		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(windowData.Width, windowData.Height, windowData.Title.c_str()
			, nullptr, nullptr);

		RM_ASSERT(window);

		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &windowData);

		Input::Init(window);

		SetVsync(windowData.VSync);
		
	}

	void WinGLFWwindow::SetVsync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		windowData.VSync = enable;
	}

	void WinGLFWwindow::Update()
	{
		Input::BeginFrame();

		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WinGLFWwindow::Shutdown()
	{
		Input::Shutdown();

		glfwDestroyWindow(window);
		window = nullptr;
		glfwTerminate();
	}


} // rm namespace