#pragma once
#include"pch.h"
#include"Core/Content/RendererBase3D.h"
#include"Scene.h"
#include"Pipeline.h"

namespace vxe {
	class Renderer : public RendererBase3D {
	private:
		std::shared_ptr<Scene> _scene;
		std::shared_ptr<Pipeline> _pipeline;
	public:
		Renderer();
		virtual void CreateDeviceResources() override;
		virtual void CreateWindowResources() override;
		virtual void Update(DX::StepTimer const&) override;
		virtual void Render() override;
		virtual void ReleaseDeviceResources() override;
	};
}