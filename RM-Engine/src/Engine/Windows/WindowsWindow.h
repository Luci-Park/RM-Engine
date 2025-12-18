/**
 * @file WindowsWindow.h
 * @author sumin.park
 * @brief  Window class for the Windows OS
 * @version 0.1
 * @date 12/18/2025 12:19:10 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Window.h"
class GLFWwindow;

namespace rm
{
	class WindowsWindow final : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		~WindowsWindow() override;

		uint32_t GetWidth() const override { return windowData.Width; }
		uint32_t GetHeight() const override { return windowData.Height; }
		bool GetVsync() const override { return windowData.VSync; }
		
		void SetVsync(bool enable) override;

		void Update() override;

		void* NativeWindow() const override { return window; }

	private:
		void Init(const WindowProps& props);
		void ShutDown();

	private:
		struct WindowData
		{
			std::string Title = "";
			int Width = 0;
			int Height = 0;
			bool VSync = true;
		};

		WindowData windowData;
		GLFWwindow* window = nullptr;
	};

} // rm namespace