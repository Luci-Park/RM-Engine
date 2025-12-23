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

#include "Windows/WinGLFWWindow.h"

#include "Engine/Events/WindowEvent.h"
#include "Engine/Events/Event.h"

#include "Input/Input.h"


namespace rm
{
	void Application::Init()
	{
		window = Window::Create();
		window->SetEventCallback([this](Event& e) { OnEvent(e); });

		Input::Init();

		isRunning = true;
	}

	void Application::Run()
	{
		while (isRunning)
		{
			// Clear "pressed/released this frame" BEFORE glfwPollEvents fires callbacks
			Input::BeginFrame();
			window->PollEvents();

			if (Input::IsKeyPressed(Key::Space))
			{
				LOG_INFO("SPACE PRESSED");
			}

			if (Input::IsKeyDown(Key::Space))
			{
				LOG_INFO("SPACE HELD");
			}

			if (Input::IsKeyReleased(Key::Space))
			{
				LOG_INFO("SPACE RELEASED");
			}
		}
	}

	void Application::Shutdown()
	{
		isRunning = false;

		Input::Shutdown();
		window.reset();
	}

	void Application::OnEvent(Event& e)
	{
		Input::OnEvent(e);
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& ev)
			{
				return OnWindowClose(ev);
			});
		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& ev)
			{
				return OnWindowResize(ev);
			});
	}

	bool Application::OnWindowClose(class WindowCloseEvent& e)
	{
		isRunning = false;
		return true;
	}

	bool Application::OnWindowResize(class WindowResizeEvent& e)
	{
		// TODO: Notify the render swapchain, etc.
		LOG_INFO("Resize -> {}x{}", e.GetWidth(), e.GetHeight());
		return false; // Allow others to react as well
	}
}
