/**
 * @file Device.h
 * @author sumin.park
 * @brief  Resource creation and submission to GPU
 * @version 0.1
 * @date 12/27/2025 10:04:42 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "RenderCommon.h"
#include "Engine/Windows/WindowDesc.h"
#include "../RenderConfig.h"
#include <memory>

namespace rm
{
    class Device
    {
    public:
        virtual ~Device() = default;
        
    	virtual std::unique_ptr<Swapchain> CreateSwapchain(WindowHandle handle) = 0;
        virtual std::unique_ptr<CommandList> CreateCommandList() = 0;

        virtual std::unique_ptr<Pipeline> CreatePipeline(const PipelineDesc&) = 0;
        virtual std::unique_ptr<Buffer> CreateBuffer(const BufferDesc&) = 0;
        virtual std::unique_ptr<VertexInput> CreateVertexInput(const VertexInputDesc&) = 0;

        static std::unique_ptr<Device> Create(GraphicsAPI targetAPI, RenderContext* context);
    };

} // rm namespace