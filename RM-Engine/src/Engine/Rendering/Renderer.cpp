/**
 * @file Renderer.cpp
 * @author sumin.park
 * @brief  The main rendering system
 * @version 0.1
 * @date 12/23/2025 2:24:59 PM
 *
 * @copyright Copyright (c) 2025 - RM Engine
 *
 */

#include "pch.h"
#include "Renderer.h"

#include "RHI/CommandList.h"
#include "RHI/Device.h"
#include "RHI/RenderContext.h"
#include "RHI/Swapchain.h"
#include "RHI/Pipeline.h"
#include "RHI/Buffer.h"
#include "RHI/VertexInput.h"

namespace rm
{
	static const char* kVS = R"(
#version 330 core
layout(location=0) in vec2 aPos;
layout(location=1) in vec3 aCol;
out vec3 vCol;
void main(){ vCol=aCol; gl_Position=vec4(aPos,0,1); }
)";

	static const char* kFS = R"(
#version 330 core
in vec3 vCol;
out vec4 FragColor;
void main(){ FragColor=vec4(vCol,1); }
)";

	struct V { float x, y, r, g, b; };


	Renderer::Renderer(const RenderConfig& config, const WindowHandle& window)
	{
		context = RenderContext::Create(config.api, window);
		device = Device::Create(config.api, context.get());

		swapchain = device->CreateSwapchain(window);
		swapchain->SetVSync(true);

		commandList = device->CreateCommandList();

		V tri[3] = {
			 { -0.6f, -0.4f, 1,0,0 },
			 {  0.6f, -0.4f, 0,1,0 },
			 {  0.0f,  0.6f, 0,0,1 },
		};

		vertexBuffer = device->CreateBuffer({ tri, sizeof(tri) });
		
		VertexAttribute attrs[] = {
		{ 0, 2, 0 },
		{ 1, 3, sizeof(float) * 2 }
		};

		vertexInput = device ->CreateVertexInput({
			.vertexBuffer = vertexBuffer.get(),
			.strideBytes = sizeof(V),
			.attributes = attrs,
			.attributeCount = 2
			});

		pipeline = device ->CreatePipeline({ kVS, kFS });
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::OnResize(uint32_t width, uint32_t height)
	{
		commandList->SetViewport(0, 0, width, height);
	}

	void Renderer::Render()
	{
		context->SetAsCurrent();

		commandList->BeginFrame();
		commandList->ClearScreen(0.2f, 0.3f, 0.3f, 1.0f);

		commandList->BindPipeline(pipeline.get());
		commandList->BindVertexInput(vertexInput.get());
		commandList->Draw(3);
		
		commandList->EndFrame();

		swapchain->Present();
	}
} // rm namespace