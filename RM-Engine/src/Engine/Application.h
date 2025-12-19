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
#include "Engine/Windows/Window.h"
#include <memory>

namespace rm
{
	class Application
	{
	public:
		Application() = default;
		virtual ~Application() = default;
		void Init();
		void Run();
		void Shutdown();

	private:
		std::unique_ptr<Window> window;
		bool isRunning = false;
	};
	
		
	Application* CreateApplication();
}