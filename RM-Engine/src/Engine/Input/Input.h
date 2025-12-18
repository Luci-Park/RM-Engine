/**
 * @file Input.h
 * @author rahul
 * @brief // TODO: Add a brief description of this header
 * @version 0.1
 * @date 12/18/2025 12:28:54 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include<utility>

struct GLFWwindow; // Forward declaration

namespace rm
{
	class Input
	{
	public:
		// Only to be called after creation of GLFWwindow*
		static void Init(GLFWwindow* window);

		static voic Shutdown();

		static void BeginFrame();

		// --- Keyboard ---

		// Using GLFW key codes (e.g. GLFW_KEY_A)
		static bool IsKeyDown(int key);
		static bool IsKeyPressed(int key);
		static bool IsKeyReleased(int key);

		// --- Mouse Buttons ---

		// Using GLFW mouse codes (e.g. GLFW_MOUSE_BUTON_LEFT)
		static bool IsMouseDown(int button);
		static bool IsMousePressed(int button);
		static bool IsMouseReleased(int button);

		// --- Mouse State ---

		static float GetMouseX();
		static float GetMouseY();
		static std::pair<float, float> GetMousePosition();

		// Per-frame scroll delta (Y), resets each BeginFrame()
		static float GetScrollDeltaY();

	private:
		Input() = delete;

		struct State
		{
			// WISH: RME-23 making input system data driven
			static constexpr int MaxKeys = 512;
			static constexpr int MaxMouseButtons = 16;

			bool keys[MaxKeys]{};
			bool prevKeys[MaxKeys]{};

			bool mouse[MaxMouseButtons]{};
			bool prevMouse[MaxMouseButtons]{};

			float mouseX = 0.0f;
			float mouseY = 0.0f;

			float scrollDeltaY = 0.0f;

			GLFWwindow* window = nullptr;
			bool initialized = false;
		};

		static State& GetState();

		// GLFW callback handlers (registered in Init)
		static void SetKey(int key, bool down);
		static void SetMouseButton(int button, bool down);
		static void SetMousePos(float x, float y);
		static void AddScroll(float yOffset);
	};

} // rm namespace