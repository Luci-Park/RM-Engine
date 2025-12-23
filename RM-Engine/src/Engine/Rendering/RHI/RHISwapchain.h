/**
 * @file RHISwapchain.h
 * @author sumin.park
 * @brief  Swapchain interface
 * @version 0.1
 * @date 12/23/2025 9:49:03 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "RHICommon.h"

namespace rm
{
    class RHISwapchain
    {
    public:
        virtual ~RHISwapchain() = default;

        virtual void SetPresentMode(PresentMode mode) = 0;

        // Vulkan-shaped: acquire/present. In OpenGL, Acquire can be a no-op.
        virtual void Acquire() = 0;
        virtual void Present() = 0;

        // Resize hooks later (recreate backbuffer dependent resources)
        virtual void OnResize(uint32_t width, uint32_t height) = 0;
    };
} // rm namespace