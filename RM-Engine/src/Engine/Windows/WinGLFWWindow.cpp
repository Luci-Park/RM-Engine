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

#include "GLFWInputMapper.h"
#include "Engine/Input/InputService.h"

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

		InputService::Init();

		// GLFW callbacks owned by the window (platform-owned)
		glfwSetKeyCallback(window, [](GLFWwindow* /*w*/, int key, int /*scancode*/, int action, int /*mods*/)
			{
				Key k = GLFWInputMapper::ToKey(key);
				if (k == Key::Unknown) return;

				if (action == GLFW_PRESS)         InputService::OnKey(k, true);
				else if (action == GLFW_RELEASE)  InputService::OnKey(k, false);
				else if (action == GLFW_REPEAT)   InputService::OnKey(k, true);
			});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* /*w*/, int button, int action, int /*mods*/)
			{
				MouseButton b = GLFWInputMapper::ToMouseButton(button);
				if (b == MouseButton::Unknown) return;

				if (action == GLFW_PRESS)         InputService::OnMouseButton(b, true);
				else if (action == GLFW_RELEASE)  InputService::OnMouseButton(b, false);
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* /*w*/, double xPos, double yPos)
			{
				InputService::OnMouseMove(static_cast<float>(xPos), static_cast<float>(yPos));
			});

		glfwSetScrollCallback(window, [](GLFWwindow* /*w*/, double /*xOffset*/, double yOffset)
			{
				InputService::OnScroll(static_cast<float>(yOffset));
			});

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
		InputService::BeginFrame();

		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WinGLFWwindow::Shutdown()
	{
		InputService::Shutdown();

		glfwDestroyWindow(window);
		window = nullptr;
		glfwTerminate();
	}


} // rm namespace