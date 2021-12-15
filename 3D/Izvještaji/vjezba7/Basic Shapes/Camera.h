#pragma once
#include"pch.h"
#include<Scene/Transforms/View Transform.h>
#include<Scene/Transforms/Projection Transform.h>

namespace vxe {

	class Camera {
	private:
		DirectX::XMFLOAT3 _eye{ 0,0,3 };
		DirectX::XMFLOAT3 _lookat{ 0,0,0 };
		DirectX::XMFLOAT3 _up{ 0,1,0 };
		std::shared_ptr<ViewTransform> _view;
		std::shared_ptr<ProjectionTransform> _projection;
		uint32_t _viewregister{ 1 };
		uint32_t _projectionregister{ 2 };
	public:
		Camera();
		void Initialize(std::shared_ptr<VanityCore>& VC);
		void Bind(std::shared_ptr<VanityCore>& VC);
		void Release();
	};


}