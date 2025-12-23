/**
 * @file WindowDesc.h
 * @author sumin.park
 * @brief  Description of target window
 * @version 0.1
 * @date 12/23/2025 10:23:43 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include <string>
namespace rm
{
	struct WindowDesc
	{
		std::string Title = "RM-Engine";
		uint32_t Width = 1600;
		uint32_t Height = 900;
		bool Resizable = true;
		bool VSync = true;
	};
} // rm namespace