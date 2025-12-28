/**
 * @file RenderContext.h
 * @author sumin.park
 * @brief  Graphic API initialization and validation
 * @version 0.1
 * @date 12/27/2025 10:03:18 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Engine/EngineConfig.h"

namespace rm
{
    class RenderContext
    {
    public:
        virtual ~RenderContext() = default;
        virtual void SetAsCurrent() = 0;

        static std::unique_ptr<RenderContext> Create(GraphicsAPI targetAPI, const WindowHandle& window);
    };

} // rm namespace