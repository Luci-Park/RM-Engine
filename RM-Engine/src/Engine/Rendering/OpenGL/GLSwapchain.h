/**
 * @file GLSwapchain.h
 * @author sumin.park
 * @brief  OpenGL Swapchain
 * @version 0.1
 * @date 12/27/2025 11:55:03 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Engine/Rendering/RHI/Swapchain.h"

struct GLFWwindow;

namespace rm
{
	class GLSwapchain final : public Swapchain
	{
	public:
		GLSwapchain(GLFWwindow* window);
		~GLSwapchain() override = default;
		void Resize(uint32_t width, uint32_t height) override;
		void Present() override;
		void SetVSync(bool enabled) override;

		uint32_t GetWidth() override { return width; }
		uint32_t GetHeight() override { return height; }

	private:
		GLFWwindow* window;
		uint32_t width = 0, height = 0;
	};

} // rm namespace