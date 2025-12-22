/**
 * @file InputService.cpp
 * @author rahul
 * @brief // Centralized, platform-independent input service providing frame-based input queries.
 * @version 0.1
 * @date 12/22/2025 7:03:47 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "InputService.h"

namespace rm
{
    InputService::State& InputService::GetState()
    {
        static State s{};
        return s;
    }

    int InputService::KeyIndex(Key key)
    {
        auto v = static_cast<int>(key);
        if (v <= 0 || v >= State::MaxKeys) return -1;
        return v;
    }

    int InputService::MouseIndex(MouseButton button)
    {
        int v = (button == MouseButton::Unknown) ? -1 : static_cast<int>(button);
        if (v < 0 || v >= State::MaxMouseButtons) return -1;
        return v;
    }

    void InputService::Init()
    {
        auto& s = GetState();
        s = State{};
        s.initialized = true;
        LOG_INFO("InputService initialized.");
    }

    void InputService::Shutdown()
    {
        auto& s = GetState();
        s = State{};
        LOG_INFO("InputService shutdown.");
    }

    void InputService::BeginFrame()
    {
        auto& s = GetState();
        RM_ASSERT(s.initialized && "InputService::Init must be called before BeginFrame.");

        std::memcpy(s.prevKeys, s.keys, sizeof(s.keys));
        std::memcpy(s.prevMouse, s.mouse, sizeof(s.mouse));
        s.scrollDeltaY = 0.0f;
    }

    // -------- Queries --------
    bool InputService::IsKeyDown(Key key)
    {
        const auto& s = GetState();
        int i = KeyIndex(key);
        return i >= 0 && s.keys[i];
    }

    bool InputService::IsKeyPressed(Key key)
    {
        const auto& s = GetState();
        int i = KeyIndex(key);
        return i >= 0 && s.keys[i] && !s.prevKeys[i];
    }

    bool InputService::IsKeyReleased(Key key)
    {
        const auto& s = GetState();
        int i = KeyIndex(key);
        return i >= 0 && !s.keys[i] && s.prevKeys[i];
    }

    bool InputService::IsMouseDown(MouseButton button)
    {
        const auto& s = GetState();
        int i = MouseIndex(button);
        return i >= 0 && s.mouse[i];
    }

    bool InputService::IsMousePressed(MouseButton button)
    {
        const auto& s = GetState();
        int i = MouseIndex(button);
        return i >= 0 && s.mouse[i] && !s.prevMouse[i];
    }

    bool InputService::IsMouseReleased(MouseButton button)
    {
        const auto& s = GetState();
        int i = MouseIndex(button);
        return i >= 0 && !s.mouse[i] && s.prevMouse[i];
    }

    float InputService::GetMouseX() { return GetState().mouseX; }
    float InputService::GetMouseY() { return GetState().mouseY; }

    std::pair<float, float> InputService::GetMousePosition()
    {
        const auto& s = GetState();
        return { s.mouseX, s.mouseY };
    }

    float InputService::GetScrollDeltaY() { return GetState().scrollDeltaY; }

    // -------- Event sinks (called by platform) --------
    void InputService::OnKey(Key key, bool down)
    {
        auto& s = GetState();
        int i = KeyIndex(key);
        if (i < 0) return;
        s.keys[i] = down;
    }

    void InputService::OnMouseButton(MouseButton button, bool down)
    {
        auto& s = GetState();
        int i = MouseIndex(button);
        if (i < 0) return;
        s.mouse[i] = down;
    }

    void InputService::OnMouseMove(float x, float y)
    {
        auto& s = GetState();
        s.mouseX = x;
        s.mouseY = y;
    }

    void InputService::OnScroll(float yOffset)
    {
        auto& s = GetState();
        s.scrollDeltaY += yOffset;
    }
} // rm namespace