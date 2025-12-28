/**
 * @file Swapchain.h
 * @author sumin.park
 * @brief  Set of images for presenting
 * @version 0.1
 * @date 12/27/2025 10:10:45 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once

namespace rm
{
    class Swapchain
    {
    public:
        virtual ~Swapchain() = default;

        virtual void Resize(uint32_t width, uint32_t height) = 0;
        virtual void Present() = 0;
        virtual void SetVSync(bool enabled) = 0;

        virtual uint32_t GetWidth() = 0;
        virtual uint32_t GetHeight() = 0;
    };

} // rm namespace