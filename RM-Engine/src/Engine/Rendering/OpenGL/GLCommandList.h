/**
 * @file GLCommandList.h
 * @author sumin.park
 * @brief  OpenGL Command list
 * @version 0.1
 * @date 12/27/2025 11:24:11 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "../RHI/CommandList.h"

namespace rm
{
	class GLVertexInput;
	class GLPipeline;

	class GLCommandList final : public CommandList
	{
	public:
		GLCommandList();
		~GLCommandList() override;
		
		void BeginFrame() override;
		void EndFrame() override;

		void SetViewport(uint32_t x, uint32_t y, uint32_t w, uint32_t h) override;
		void ClearScreen(float r, float g, float b, float a) override;
		
		void BindPipeline(Pipeline* pip) override;
		void BindVertexInput(VertexInput* vi) override;
		
		void Draw(uint32_t vertexCount) override;

	private:
		GLPipeline* pipeline = nullptr;
		GLVertexInput* vertexInput = nullptr;
	};

} // rm namespace