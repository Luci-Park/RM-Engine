/**
 * @file RenderConfig.h
 * @author sumin.park
 * @brief  Render config
 * @version 0.1
 * @date 12/23/2025 10:20:19 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once

namespace rm
{
	enum class GraphicsAPI
	{
		OpenGL,
	};

    struct RenderConfig {
        GraphicsAPI Api = GraphicsAPI::OpenGL;
        int GLMajor = 4;
        int GLMinor = 6;
    };

} // rm namespace