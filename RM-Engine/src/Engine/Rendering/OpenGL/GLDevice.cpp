/**
 * @file GLDevice.cpp
 * @author sumin.park
 * @brief  OpenGL Device
 * @version 0.1
 * @date 12/27/2025 11:05:02 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "GLDevice.h"
#include "GLRenderContext.h"
#include "GLSwapchain.h"
#include "GLCommandList.h"
#include "GLPipeline.h"
#include "GLBuffer.h"
#include "GLVertexInput.h"

namespace rm
{
	GLDevice::GLDevice(GLRenderContext* renderContext)
		:renderContext(renderContext)
	{
		renderContext->SetAsCurrent();
	}

	std::unique_ptr<Swapchain> GLDevice::CreateSwapchain(WindowHandle handle)
	{
		if (handle.type != WindowType::GLFW || ! handle.window)
		{
			LOG_CRITICAL("[RHI][GL] CreateSwapchain: invalid surface\n");
			return nullptr;
		}
		return std::make_unique<GLSwapchain>(static_cast<GLFWwindow*>(handle.window));
	}

	std::unique_ptr<CommandList> GLDevice::CreateCommandList()
	{
		return std::make_unique<GLCommandList>();
	}

	std::unique_ptr<Pipeline> GLDevice::CreatePipeline(const PipelineDesc& desc)
	{
		return std::make_unique<GLPipeline>(desc);
	}

	std::unique_ptr<Buffer> GLDevice::CreateBuffer(const BufferDesc& desc)
	{
		return std::make_unique<GLBuffer>(desc);
	}

	std::unique_ptr<VertexInput> GLDevice::CreateVertexInput(const VertexInputDesc& desc)
	{
		return std::make_unique<GLVertexInput>(desc);
	}
} // rm namespace