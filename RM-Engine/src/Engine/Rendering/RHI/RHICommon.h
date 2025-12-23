/**
 * @file RHICommon.h
 * @author sumin.park
 * @brief  Collection of RHI infos
 * @version 0.1
 * @date 12/23/2025 9:53:24 AM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#pragma once
#include "Engine/Rendering/RenderConfig.h"
namespace rm
{

	enum class PrimitiveTopology
	{
		Triangles,
		Lines,
		Points,
	};

	enum class BufferUsage
	{
		Vertex,
		Index,
		Uniform
	};

	enum class PresentMode
	{
		VSync,
		Immediate,
	};

	struct DeviceDesc
	{
		GraphicsAPI api = GraphicsAPI::OpenGL;
	};

	struct SwapchainDesc
	{
		PresentMode presentMode = PresentMode::VSync;
	};

	struct VertexAttribute
	{
		uint32_t location = 0;
		uint32_t components = 0;
		uint32_t offsetBytes = 0;
	};

	struct VertexLayout
	{
		uint32_t strideBytes = 0;
		const VertexAttribute* attributes = nullptr;
		uint32_t attributeCount = 0;
	};

	struct ShaderSource
	{
		std::string_view vertexShader;
		std::string_view fragmentShader;
	};

	struct PipelineDesc
	{
		ShaderSource shaders{};
		VertexLayout vertexLayout{};
		PrimitiveTopology topology = PrimitiveTopology::Triangles;
				
		bool enableAlphaBlend = false;
	};

	struct BufferDesc
	{
		BufferUsage usage = BufferUsage::Vertex;
		size_t sizeBytes = 0;
		size_t strideBytes = 0;
		const void* initialData = nullptr;
	};

	class RHIDevice;
	class RHISwapchain;
	class RHICommandList;
	class RHIPipeline;
	class RHIBuffer;
} // rm namespace