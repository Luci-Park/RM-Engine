/**
 * @file RHIRenderContext.h
 * @author sumin.park
 * @brief  The interface for graphics API connection
 * @version 0.1
 * @date 12/23/2025 11:49:01 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "RHICommon.h"
#include <memory>
namespace rm
{
    class RHIRenderContext
    {
    public:
        virtual ~RHIRenderContext() = default;


        virtual GraphicsAPI GetAPI() const = 0;

        // Ensures this context is current on the calling thread (important for OpenGL)
        virtual void MakeCurrent() = 0;

        // Optional: useful for resize; GL backend can call glViewport here
        virtual void OnResize(uint32_t width, uint32_t height) = 0;

        // Native handles (backend-specific use). Keep RHI clean:
        virtual void* GetNativeContextHandle() const = 0; // e.g. could be HGLRC / VkInstance wrapper etc.
        virtual void* GetNativeWindowHandle() const = 0;

        std::unique_ptr<RHIRenderContext> Create(GraphicsAPI api, void* nativeWindowHandle);
    };

} // rm namespace