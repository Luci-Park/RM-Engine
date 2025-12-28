/**
 * @file RenderCommon.h
 * @author sumin.park
 * @brief  Header for rendering
 * @version 0.1
 * @date 12/27/2025 10:08:12 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once

namespace rm
{
	class Device;
	class RenderContext;
	class Swapchain;
	class Pipeline;
	class CommandList;
	class Buffer;
	class VertexInput;
	
	struct BufferDesc
	{
		const void* data;
		size_t sizeBytes;
	};


	struct VertexAttribute
	{
		uint32_t location = 0;      // layout(location=N)
		uint32_t components = 0;    // 1..4
		uint32_t offsetBytes = 0;   // offset into vertex struct
	};

	struct VertexInputDesc
	{
		Buffer* vertexBuffer = nullptr;
		uint32_t strideBytes = 0;
		const VertexAttribute* attributes = nullptr;
		uint32_t attributeCount = 0;
	};

	struct PipelineDesc
	{
		std::string_view vertex;
		std::string_view fragment;
	};

} // rm namespace