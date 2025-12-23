/**
 * @file EngineConfic.h
 * @author sumin.park
 * @brief  Configuration for Engine
 * @version 0.1
 * @date 12/23/2025 10:22:40 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Engine/Windows/WindowDesc.h"
#include "Engine/Rendering/RenderConfig.h"
namespace rm
{
	struct EngineConfig
    {
        WindowDesc Window = {};
        RenderConfig Render = {};
    };

} // rm namespace