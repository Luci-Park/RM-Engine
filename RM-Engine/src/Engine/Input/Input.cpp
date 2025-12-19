/**
 * @file Input.cpp
 * @author rahul
 * @brief Static interface system for querying keyboard and mouse input state.
 * @version 0.1
 * @date 12/18/2025 12:28:54 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Input.h"

#include <GLFW/glfw3.h>

namespace rm
{
	Input::State& Input::GetState()
	{
		static State s_State{};
		return s_State;
	}

	void Input::Init(GLFWwindow* window)
	{
		RM_ASSERT(window != nullptr);

		auto& s = GetState();
		s.window = window;
		s.initialized = true;

		// Seed mouse position so first frame isn't (0,0)
		double x = 0.0, y = 0.0;
		glfwGetCursorPos(window, &x, &y);
		s.mouseX = static_cast<float>(x);
		s.mouseY = static_cast<float>(y);

		// --- Callbacks ---

		glfwSetKeyCallback(window, [](GLFWwindow* /*w*/, int key, int /*scancode*/, int action, int /*mods*/)
			{
				auto& state = Input::GetState();
				if (key < 0 || key >= State::MaxKeys) return;

				if (action == GLFW_PRESS)         state.keys[key] = true;
				else if (action == GLFW_RELEASE)  state.keys[key] = false;
				else if (action == GLFW_REPEAT)   state.keys[key] = true;
			});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* /*w*/, int button, int action, int /*mods*/)
			{
				auto& state = Input::GetState();
				if (button < 0 || button >= State::MaxMouseButtons) return;

				if (action == GLFW_PRESS)         state.mouse[button] = true;
				else if (action == GLFW_RELEASE)  state.mouse[button] = false;
			});

		glfwSetCursorPosCallback(window, [](GLFWwindow* /*w*/, double xPos, double yPos)
			{
				auto& state = Input::GetState();
				state.mouseX = static_cast<float>(xPos);
				state.mouseY = static_cast<float>(yPos);
			});

		glfwSetScrollCallback(window, [](GLFWwindow* /*w*/, double /*xOffset*/, double yOffset)
			{
				auto& state = Input::GetState();
				state.scrollDeltaY += static_cast<float>(yOffset);
			});

		LOG_INFO("Input layer initialized (GLFW callbacks registered).");
	}

	void Input::Shutdown()
	{
		auto& s = GetState();
		s = State{};
		LOG_INFO("Input layer shutdown.");
	}

	void Input::BeginFrame()
	{
		auto& s = GetState();
		RM_ASSERT(s.initialized && "Input::Init must be called before BeginFrame.");

		std::memcpy(s.prevKeys, s.keys, sizeof(s.keys));
		std::memcpy(s.prevMouse, s.mouse, sizeof(s.mouse));

		s.scrollDeltaY = 0.0f;
	}

	// --- Keyboard Queries ---

	bool Input::IsKeyDown(int key)
	{
		const auto& s = GetState();
		return key >= 0 && key < State::MaxKeys && s.keys[key];
	}

	bool Input::IsKeyPressed(int key)
	{
		const auto& s = GetState();
		return key >= 0 && key < State::MaxKeys && s.keys[key] && !s.prevKeys[key];
	}

	bool Input::IsKeyReleased(int key)
	{
		const auto& s = GetState();
		return key >= 0 && key < State::MaxKeys && !s.keys[key] && s.prevKeys[key];
	}

	// --- Mouse Button Queries ---

	bool Input::IsMouseDown(int button)
	{
		const auto& s = GetState();
		return button >= 0 && button < State::MaxMouseButtons && s.mouse[button];
	}

	bool Input::IsMousePressed(int button)
	{
		const auto& s = GetState();
		return button >= 0 && button < State::MaxMouseButtons && s.mouse[button] && !s.prevMouse[button];
	}

	bool Input::IsMouseReleased(int button)
	{
		const auto& s = GetState();
		return button >= 0 && button < State::MaxMouseButtons && !s.mouse[button] && s.prevMouse[button];
	}

	// --- Mouse State ---

	float Input::GetMouseX() { return GetState().mouseX; }
	float Input::GetMouseY() { return GetState().mouseY; }

	std::pair<float, float> Input::GetMousePosition()
	{
		const auto& s = GetState();
		return { s.mouseX, s.mouseY };
	}

	float Input::GetScrollDeltaY() { return GetState().scrollDeltaY; }

	// --- Internal setters ---

	void Input::SetKey(int key, bool down)
	{
		auto& s = GetState();
		if (key < 0 || key >= State::MaxKeys) return;
		s.keys[key] = down;
	}

	void Input::SetMouseButton(int button, bool down)
	{
		auto& s = GetState();
		if (button < 0 || button >= State::MaxMouseButtons) return;
		s.mouse[button] = down;
	}

	void Input::SetMousePos(float x, float y)
	{
		auto& s = GetState();
		s.mouseX = x;
		s.mouseY = y;
	}

	void Input::AddScroll(float yOffset)
	{
		auto& s = GetState();
		s.scrollDeltaY += yOffset;
	}
}