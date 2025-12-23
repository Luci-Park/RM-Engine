/**
 * @file RHIDevice.h
 * @author sumin.park
 * @brief Device interface : creates Resources, submits drawcalls
 * @version 0.1
 * @date 12/23/2025 9:46:36 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include <memory>
#include "RHICommon.h"

namespace rm
{
    class RHIRenderContext;
    class RHIDevice
    {
    public:
        virtual ~RHIDevice() = default;

        virtual std::unique_ptr<RHISwapchain> CreateSwapchain(void* window, const SwapchainDesc& desc) = 0;

        virtual std::unique_ptr<RHICommandList> CreateCommandList() = 0;
        virtual std::unique_ptr<RHIPipeline> CreatePipeline(const PipelineDesc& desc) = 0;
        virtual std::unique_ptr<RHIBuffer> CreateBuffer(const BufferDesc& desc) = 0;

        // Vulkan submits command buffers; OpenGL backend can "execute immediately"
        virtual void Submit(RHICommandList& cmd) = 0;

        static std::unique_ptr<RHIDevice> Create(const DeviceDesc& desc, RHIRenderContext& context);
    };

} // rm namespace