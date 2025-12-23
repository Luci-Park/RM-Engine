/**
 * @file RHICommandList.h
 * @author sumin.park
 * @brief  Draw command list interface
 * @version 0.1
 * @date 12/23/2025 11:41:46 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "RHICommon.h"

namespace rm
{
    class RHICommandList
    {
    public:
        virtual ~RHICommandList() = default;

        virtual void Begin() = 0;
        virtual void End() = 0;

        virtual void BeginBackbufferPass(float r, float g, float b, float a) = 0;
        virtual void EndBackbufferPass() = 0;

        virtual void BindPipeline(RHIPipeline* pipeline) = 0;
        virtual void BindVertexBuffer(RHIBuffer* vertexBuffer) = 0;

        virtual void Draw(uint32_t vertexCount, uint32_t firstVertex = 0) = 0;
    };

} // rm namespace