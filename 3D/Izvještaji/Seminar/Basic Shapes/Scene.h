#pragma once
#include"pch.h"
#include<Third Party/DirectX Tool Kit/VertexTypes.h>
#include<Scene/Scene Object.h>
#include"Animation.h"
#include"Camera.h"
#include"Textures.h"
#include"Scene/Input/Input Controller.h"

namespace vxe {
	class Scene {
		using VertextType_t = DirectX::VertexPositionColor;
		using IndexType_t = uint16_t;

	private:
		std::vector<std::shared_ptr<SceneObject<VertextType_t, IndexType_t>>> _objects;
		Animation _animation;
		Camera _camera;
		Textures _textures;
		std::vector<DirectX::XMFLOAT3> _positions;
		std::vector<DirectX::XMFLOAT3> _orients;
		std::vector<DirectX::XMFLOAT3> _initial[2];
		DirectX::XMFLOAT2 _prevpointer{ 0,0 };
		DirectX::XMFLOAT2 _currpointer{ 0,0 };
		DirectX::XMFLOAT2 _diff{ 0,0 };

	
	public:
		Scene();

		void LoadAssets(std::vector<concurrency::task<void>>& tasks, std::shared_ptr<VanityCore>& VC);
		void SetCamera(std::shared_ptr<VanityCore>& VC);
		void SetTexture(std::shared_ptr<VanityCore>& VC);
		void Update(DX::StepTimer const&, InputController^);
		void Render(std::shared_ptr<VanityCore>& VC);
		void Draw(std::shared_ptr<VanityCore>& VC, bool = false);
		void Release();

	};
}