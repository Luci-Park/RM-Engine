/**
 * @file Window.h
 * @author sumin.park
 * @brief The interface representing the window.
 * @version 0.1
 * @date 12/18/2025 11:37:10 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include <memory>
#include "Engine/Events/Event.h"
#include "Engine/EngineConfig.h"

namespace rm
{

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual bool GetVsync() const = 0;

		virtual void SetVsync(bool enable) = 0;

		virtual void PollEvents() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual void* NativeWindow() const = 0;

		static std::unique_ptr<Window> Create(const EngineConfig& config = {});

	protected:
		Window() = default;
	};

} // rm namespace