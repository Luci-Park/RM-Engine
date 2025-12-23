/**
 * @file Window.cpp
 * @author sumin.park
 * @brief The interface representing the window.
 * @version 0.1
 * @date 12/18/2025 12:19:58 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Window.h"

#include "WinGLFWwindow.h"

namespace rm
{
	std::unique_ptr<Window> Window::Create(const WindowProps& props)
	{
		return std::make_unique<WinGLFWwindow>(props);
	}
} // rm namespace