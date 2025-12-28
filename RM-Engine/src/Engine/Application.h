/**
 * @file Application.h
 * @author sumin.park
 * @brief The application class that the app will inherit.
 * @version 0.1
 * @date 12/16/2025 3:47:59 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */
#pragma once
#include <memory>

namespace rm
{
	class Window;
	class Event;
	class Renderer;
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Init();
		void Run();
		void Shutdown();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(class WindowCloseEvent& e);
		bool OnWindowResize(class WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> window = nullptr;
		std::unique_ptr<Renderer> renderer = nullptr;
		bool isRunning = false;
	};
	
		
	Application* CreateApplication();
}