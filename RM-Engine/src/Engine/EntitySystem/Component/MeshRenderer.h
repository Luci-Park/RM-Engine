/**
 * @file MeshRenderer.h
 * @author sumin.park
 * @brief  Renderer Component
 * @version 0.1
 * @date 1/8/2026 11:30:10 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Component.h"
namespace rm {
    class Mesh;
    class Material;

    class MeshRenderer : public Component {
       public:
        MeshRenderer(GameObject* owner);
        ~MeshRenderer() override;

       private:
        void Init() override;
        void Update(float dt) override;
        void LateUpdate(float dt) override;
        void Render() override;

       private:
        Mesh* mesh = nullptr;
        Material* material = nullptr;
    };

}  // namespace rm