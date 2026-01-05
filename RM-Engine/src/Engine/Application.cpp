/**
 * @file Application.cpp
 * @author sumin.park
 * @brief The application class that the app will inherit.
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Application.h"
#include "Windows/WinGLFWWindow.h"
#include "Rendering/Renderer.h"

#include "Engine/Events/Event.h"
#include "Engine/Events/WindowEvent.h"

#include "Input/Input.h"


namespace rm
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Init()
	{
		RenderConfig renderConfig = {GraphicsAPI::OpenGL, 4, 6};
		WindowDesc windowDesc = {};
		EngineConfig config = { windowDesc, renderConfig };
		
		window = Window::Create(config);
		window->SetEventCallback([this](Event& e) { OnEvent(e); });

		renderer = std::make_unique<Renderer>(renderConfig, window->GetNativeWindow());

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

			renderer->Render();
		}
	}

    void Application::Shutdown() {
        isRunning = false;

        Input::Shutdown();
        window.reset();
    }

    void Application::OnEvent(Event& e) {
        Input::OnEvent(e);
        EventDispatcher dispatcher(e);

        dispatcher.Dispatch<WindowCloseEvent>(
            [this](WindowCloseEvent& ev) { return OnWindowClose(ev); });
        dispatcher.Dispatch<WindowResizeEvent>(
            [this](WindowResizeEvent& ev) { return OnWindowResize(ev); });
    }

    bool Application::OnWindowClose(class WindowCloseEvent& e) {
        isRunning = false;
        return true;
    }

	bool Application::OnWindowResize(class WindowResizeEvent& e)
	{
		// TODO: Notify the render swapchain, etc.
		LOG_INFO("Resize -> {}x{}", e.GetWidth(), e.GetHeight());
		renderer->OnResize(e.GetWidth(), e.GetHeight());
		return false; // Allow others to react as well
	}
}
