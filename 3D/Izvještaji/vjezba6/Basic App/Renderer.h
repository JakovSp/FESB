#pragma once
#include"pch.h"
#include<Core/Content/RendererBase3D.h>

namespace vxe {
	class Renderer : public RendererBase3D {
	public:
		Renderer();
		virtual void CreateDeviceResources() override;
		virtual void CreateWindowResources() override;
		virtual void Update(DX::StepTimer const&) override;
		virtual void Render() override;
		virtual void ReleaseDeviceResources() override;
	};
}