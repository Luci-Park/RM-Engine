/**
 * @file MeshRenderer.cpp
 * @author sumin.park
 * @brief  Renderer Component
 * @version 0.1
 * @date 1/8/2026 11:30:10 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "MeshRenderer.h"
#include "Engine/Resource/Mesh.h"
#include "Engine/Resource/Material.h"

namespace rm
{
    MeshRenderer::MeshRenderer(GameObject* owner)
        :Component(owner){
    }

    MeshRenderer::~MeshRenderer() {
        //Todo: mesh and material should be controlled by resource mananger
        if (mesh != nullptr) {
            delete mesh;
            mesh = nullptr;
        }

        if (material != nullptr) {
            delete material;
            material = nullptr;
        }
    }

    void MeshRenderer::Init() {
    }

    void MeshRenderer::Update(float dt) {
    }

    void MeshRenderer::LateUpdate(float dt) {
    }

    void MeshRenderer::Render() {
    }
} // rm namespace