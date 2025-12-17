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
#include "Engine/Logging/Assert.h"

namespace rm
{

	void Application::Run() 
	{
		Log::Init();

		LOG_WARN("Easy padding in numbers like {:08d}", 12);
		LOG_CRITICAL("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
		LOG_INFO("Support for floats {:03.2f}", 1.23456);
		LOG_INFO("Positional args are {1} {0}..", "too", "supported");
		LOG_INFO("{:>8} aligned, {:<8} aligned", "right", "left");
		Log::Shutdown();		
		while (true);
	}
}
