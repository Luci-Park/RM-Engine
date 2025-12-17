/**
 * @file Application.cpp
 * @author rahul
 * @brief Includes frequently used includes in a desirable configuration for all projects.
 * @version 0.1
 * @date 12/16/2025 3:11:45 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Application.h"

#include <spdlog/fmt/bundled/format.h>

namespace rm
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		Log::Init();
		int* ptr = nullptr;
		Log::Shutdown();		
	}
}
