/**
 * @file GLDevice.h
 * @author sumin.park
 * @brief  OpenGL Device
 * @version 0.1
 * @date 12/27/2025 11:05:02 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once

#include "../RHI/Device.h"

namespace rm
{
	class GLRenderContext;

	class GLDevice final : public Device
	{
	public:
		GLDevice(GLRenderContext* renderContext);

		~GLDevice() override = default;
		std::unique_ptr<Swapchain> CreateSwapchain(WindowHandle handle) override;
		std::unique_ptr<CommandList> CreateCommandList() override;
		std::unique_ptr<Pipeline> CreatePipeline(const PipelineDesc&) override;
		std::unique_ptr<Buffer> CreateBuffer(const BufferDesc&) override;
		std::unique_ptr<VertexInput> CreateVertexInput(const VertexInputDesc&) override;

	private:
		GLRenderContext* renderContext;
	};

} // rm namespace