/**
 * @file Renderer.h
 * @author sumin.park
 * @brief  The main rendering system
 * @version 0.1
 * @date 12/23/2025 2:24:59 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include <memory>
#include "RenderConfig.h"
#include "Engine/Windows/WindowDesc.h"
#include "RHI/RenderCommon.h"

namespace rm
{
	class Renderer
	{
	public:
		Renderer(const RenderConfig& config, const WindowHandle& window);
		~Renderer();
		void OnResize(uint32_t width, uint32_t height);
		void Render();
	private:
		std::unique_ptr<RenderContext> context;
		std::unique_ptr<Device> device;
		std::unique_ptr<Swapchain> swapchain;
		std::unique_ptr<CommandList> commandList;
		std::unique_ptr<VertexInput> vertexInput;
		std::unique_ptr<Buffer> vertexBuffer;
		std::unique_ptr<Pipeline> pipeline;
	};

} // rm namespace