#pragma once
#include"pch.h"
#include<Third Party/DirectX Tool Kit/VertexTypes.h>
#include<Pipeline Stages/Shaders/Vertex Shader.h>
#include<Pipeline Stages/Shaders/Pixel Shader.h>

namespace vxe {
	class Pipeline {
	public:
		std::shared_ptr<VertexShader<DirectX::VertexPositionColor>> _vertexshader;
		std::shared_ptr<PixelShader> _pixelshader;
	public:
		Pipeline();
		void LoadShaders(std::vector<concurrency::task<void>>& tasks, std::shared_ptr<VanityCore>& VC);
		void BindShaders(std::shared_ptr<VanityCore>& VC);
		void Release();
	};
}