/**
 * @file Transform.cpp
 * @author sumin.park
 * @brief  Transform Component
 * @version 0.1
 * @date 1/8/2026 7:06:27 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Transform.h"

namespace rm {
    Transform::Transform(GameObject* owner) 
    : Component(owner),
        position(0), scale(1), rotation(0) {
    }

    Transform& Transform::operator=(const Transform& other) {
        if (this == &other)
            return *this;
        position = other.position;
        rotation = other.rotation;
        scale = other.scale;
        return *this;
    }

    void Transform::Init() {
    }

    void Transform::Update(float dt) {
    }

    void Transform::LateUpdate(float dt) {
    }

    void Transform::Render() {
    }
}  // namespace rm