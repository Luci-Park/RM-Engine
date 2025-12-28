/**
 * @file CommandList.h
 * @author sumin.park
 * @brief  Sequence of instructions for the GPU
 * @version 0.1
 * @date 12/27/2025 10:14:11 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "RenderCommon.h"
namespace rm
{
    class CommandList
    {
    public:
        virtual ~CommandList() = default;
        
        virtual void BeginFrame() = 0;
        virtual void EndFrame() = 0;

        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h) = 0;
        virtual void ClearScreen(float r, float g, float b, float a) = 0;
        virtual void BindPipeline(Pipeline* pipeline) = 0;
        virtual void BindVertexInput(VertexInput* vertex) = 0;

    	virtual void Draw(uint32_t vertexCount) = 0;
    };

} // rm namespace