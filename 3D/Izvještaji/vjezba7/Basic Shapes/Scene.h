#pragma once
#include"pch.h"
#include<Third Party/DirectX Tool Kit/VertexTypes.h>
#include<Scene/Scene Object.h>
#include"Animation.h"
#include"Camera.h"

namespace vxe {
	class Scene {
		using VertextType_t = DirectX::VertexPositionColor;
		using IndexType_t = uint16_t;

	private:
		std::shared_ptr<SceneObject<VertextType_t, IndexType_t>> _object;
		Animation _animation;
		Camera _camera;
	public:
		Scene();
		void LoadAssets(std::vector<concurrency::task<void>>& tasks, std::shared_ptr<VanityCore>& VC);
		void SetCamera(std::shared_ptr<VanityCore>& VC);
		void Update(const DX::StepTimer&);
		void Render(std::shared_ptr<VanityCore>& VC);
		void Draw(std::shared_ptr<VanityCore>& VC, bool=false);
		void Release();
	};
}