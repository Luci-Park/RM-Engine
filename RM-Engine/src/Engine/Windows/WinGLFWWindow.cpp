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
#include "Engine/Events/InputEvent.h"
#include "Engine/Events/WindowEvent.h"
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

		Input::Init();

		// ----- Window events -----

		glfwSetWindowCloseCallback(window, [](GLFWwindow* w)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				WindowCloseEvent e;
				if (data.EventCallback) data.EventCallback(e);
			});

		glfwSetWindowSizeCallback(window, [](GLFWwindow* w, int width, int height)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				data.Width = width;
				data.Height = height;

				WindowResizeEvent e(static_cast<uint32_t>(width), static_cast<uint32_t>(height));
				if (data.EventCallback) data.EventCallback(e);
			});

		// ----- Input events + polling state -----

		glfwSetKeyCallback(window, [](GLFWwindow* w, int key, int /*scancode*/, int action, int /*mods*/)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				Key k = GLFWInputMapper::ToKey(key);
				if (k == Key::Unknown) return;

				if (action == GLFW_PRESS)
				{
					Input::OnKey(k, true);
					KeyPressedEvent e(k, 0);
					if (data.EventCallback) data.EventCallback(e);
				}
				else if (action == GLFW_RELEASE)
				{
					Input::OnKey(k, false);
					KeyReleasedEvent e(k);
					if (data.EventCallback) data.EventCallback(e);
				}
				else if (action == GLFW_REPEAT)
				{
					Input::OnKey(k, true);
					KeyPressedEvent e(k, 1);
					if (data.EventCallback) data.EventCallback(e);
				}
			});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* w, int button, int action, int /*mods*/)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				MouseButton b = GLFWInputMapper::ToMouseButton(button);
				if (b == MouseButton::Unknown) return;

				if (action == GLFW_PRESS)
				{
					Input::OnMouseButton(b, true);
					MouseButtonPressedEvent e(b);
					if (data.EventCallback) data.EventCallback(e);
				}
				else if (action == GLFW_RELEASE)
				{
					Input::OnMouseButton(b, false);
					MouseButtonReleasedEvent e(b);
					if (data.EventCallback) data.EventCallback(e);
				}
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* w, double xPos, double yPos)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				float x = static_cast<float>(xPos);
				float y = static_cast<float>(yPos);

				Input::OnMouseMove(x, y);
				MouseMovedEvent e(x, y);
				if (data.EventCallback) data.EventCallback(e);
			});

		glfwSetScrollCallback(window, [](GLFWwindow* w, double xOffset, double yOffset)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				float xo = static_cast<float>(xOffset);
				float yo = static_cast<float>(yOffset);

				Input::OnScroll(yo);
				MouseScrolledEvent e(xo, yo);
				if (data.EventCallback) data.EventCallback(e);
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