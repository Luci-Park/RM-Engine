/**
 * @file RenderFactory.cpp
 * @author sumin.park
 * @brief  RHI component factory;
 * @version 0.1
 * @date 12/27/2025 11:02:26 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "RenderContext.h"
#include "Device.h"

#include "../OpenGL/GLDevice.h"
#include "../OpenGL/GLRenderContext.h"

namespace rm
{
	std::unique_ptr<RenderContext> RenderContext::Create(GraphicsAPI targetAPI, const WindowHandle& window)
	{
		switch (targetAPI)
		{
			case GraphicsAPI::OpenGL: return std::make_unique<GLRenderContext>(window);
		}
		return nullptr;
	}

	std::unique_ptr<Device> Device::Create(GraphicsAPI targetAPI, RenderContext* context)
	{
		switch (targetAPI)
		{
			case GraphicsAPI::OpenGL: return std::make_unique<GLDevice>(static_cast<GLRenderContext*>(context));
		}
		return nullptr;
	}
} // rm namespace