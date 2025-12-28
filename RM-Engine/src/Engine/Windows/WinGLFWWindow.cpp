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

namespace rm
{
	WinGLFWwindow::WinGLFWwindow(const EngineConfig& config)
	{
		Init(config);
	}

	WinGLFWwindow::~WinGLFWwindow()
	{
		Shutdown();
	}

	void WinGLFWwindow::Init(const EngineConfig& config)
	{
		RM_ASSERT(glfwInit());

		SetWindowDesc(config.Window);
		SetRenderConfig(config.Render);

		GLFWwindow* window = glfwCreateWindow(windowData.width, windowData.height, windowData.Title.c_str()
		                          , nullptr, nullptr);

		RM_ASSERT(window);

		windowHandle.type = WindowType::GLFW;
		windowHandle.window = window;

		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &windowData);

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
				data.width = width;
				data.height = height;

				WindowResizeEvent e(static_cast<uint32_t>(width), static_cast<uint32_t>(height));
				if (data.EventCallback) data.EventCallback(e);
			});

		glfwSetWindowFocusCallback(window, [](GLFWwindow* w, int focused)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				if (!data.EventCallback) return;

				if (focused)
				{
					rm::WindowFocusEvent e;
					data.EventCallback(e);
				}
				else
				{
					rm::WindowLostFocusEvent e;
					data.EventCallback(e);
				}
			});



		// ----- Input events + polling state -----

		glfwSetKeyCallback(window, [](GLFWwindow* w, int key, int /*scancode*/, int action, int /*mods*/)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				Key k = GLFWInputMapper::ToKey(key);

				if (k == Key::Unknown) return;

				if (action == GLFW_PRESS)
				{
					KeyPressedEvent e(k, 0);
					if (data.EventCallback) data.EventCallback(e);
				}
				else if (action == GLFW_RELEASE)
				{
					KeyReleasedEvent e(k);
					if (data.EventCallback) data.EventCallback(e);
				}
				else if (action == GLFW_REPEAT)
				{
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
					MouseButtonPressedEvent e(b);
					if (data.EventCallback) data.EventCallback(e);
				}
				else if (action == GLFW_RELEASE)
				{
					MouseButtonReleasedEvent e(b);
					if (data.EventCallback) data.EventCallback(e);
				}
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* w, double xPos, double yPos)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				float x = static_cast<float>(xPos);
				float y = static_cast<float>(yPos);

				MouseMovedEvent e(x, y);
				if (data.EventCallback) data.EventCallback(e);
			});

		glfwSetScrollCallback(window, [](GLFWwindow* w, double xOffset, double yOffset)
			{
				auto& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(w));
				float xo = static_cast<float>(xOffset);
				float yo = static_cast<float>(yOffset);

				MouseScrolledEvent e(xo, yo);
				if (data.EventCallback) data.EventCallback(e);
			});

		SetVsync(windowData.vSync);
		
	}

	void WinGLFWwindow::SetWindowDesc(const WindowDesc& desc)
	{
		windowData.Title = desc.Title;
		windowData.width = static_cast<int>(desc.Width);
		windowData.height = static_cast<int>(desc.Height);
		windowData.vSync = desc.VSync;

		glfwWindowHint(GLFW_RESIZABLE, desc.Resizable ? GLFW_TRUE : GLFW_FALSE);
	}

	void WinGLFWwindow::SetRenderConfig(const RenderConfig& render)
	{
		int api;
		switch (render.api)
		{
			case GraphicsAPI::OpenGL: api = GLFW_OPENGL_API; break;
		}
		glfwWindowHint(GLFW_CLIENT_API, api);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, render.apiMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, render.apiMinor);
	}

	void WinGLFWwindow::SetVsync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		windowData.vSync = enable;
	}

	void WinGLFWwindow::PollEvents()
	{
		glfwPollEvents();
	}

	void WinGLFWwindow::Shutdown()
	{
		glfwDestroyWindow(static_cast<GLFWwindow*>(windowHandle.window));
		windowHandle.window = nullptr;
		glfwTerminate();
	}


} // rm namespace