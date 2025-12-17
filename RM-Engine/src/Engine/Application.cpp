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
	Application::Application()
	{
		
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		Log::Init();
		RM_ASSERT(false);

		Log::Shutdown();		
	}
}
