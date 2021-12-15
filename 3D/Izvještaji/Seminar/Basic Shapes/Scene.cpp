#include"pch.h"
#include"Scene.h"
#include"Models/Mesh.h"
//#include<Models/Basic Shapes/Cubes.h>
#include"CustomCube.h"
#include<Scene/Input/Input Controller.h>

using namespace std;
using namespace vxe;
using namespace concurrency;
using namespace DirectX;

Scene::Scene() {
	DebugPrint(string("\nScene()"));
}

void Scene::LoadAssets(std::vector<concurrency::task<void>>& tasks, std::shared_ptr<VanityCore>& VC) {
	auto device = VC->GetD3DDevice();
	float models[2][3] = { {2, 1, 3}, {1, 3, 2} };

	for (int i = 0; i < 2; i++) {
		_objects.push_back(make_shared<SceneObject<VertextType_t, IndexType_t>>());
		shared_ptr<Mesh<VertextType_t, IndexType_t>> mesh;
		mesh = make_shared<CustomCube<VertextType_t, IndexType_t>>(models[i][0], models[i][1], models[i][2]);
		tasks.push_back(mesh->CreateAsync(device));
		//_textures.Load(tasks, VC);
		auto world = make_shared<WorldTransforms>(device);
		_objects.back()->SetMesh(mesh);
		_objects.back()->SetWorld(world);

		_positions.push_back(XMFLOAT3(0, 0, 0));
		_orients.push_back(XMFLOAT3(0, 0, 0));
	}
	_positions[0] = XMFLOAT3(1, 0, 0);
	_positions[1] = XMFLOAT3(-1, 0, 0);

	_initial[0] = _positions;
	_initial[1] = _orients;
}

void Scene::SetCamera(std::shared_ptr<VanityCore>& VC) {
	_camera.Initialize(VC);
	_camera.Bind(VC);
}

void Scene::SetTexture(std::shared_ptr<VanityCore>& VC) {
	_textures.Initialize(VC);
	_textures.Bind(VC);
}

void Scene::Update(const DX::StepTimer& timer, InputController^ IC) {

	if (IC->IsKeyDown(Windows::System::VirtualKey::Control)) {
		_prevpointer = _currpointer;
		_currpointer = IC->GetPointerPosition();
		
		for (int i = 0; i < _objects.size(); i++) {
			_orients[i].x -= (_currpointer.y - _prevpointer.y) * 0.01;
			_orients[i].y -= (_currpointer.x - _prevpointer.x) * 0.01;
		}
	}
	_currpointer = IC->GetPointerPosition();
	
	if (IC->IsKeyDown(Windows::System::VirtualKey::W)) {
		for (int i = 0; i < _objects.size(); i++) {
			_positions[i].z -= 0.1;
		}
	}
	if (IC->IsKeyDown(Windows::System::VirtualKey::S)) {
		for (int i = 0; i < _objects.size(); i++) {
			_positions[i].z += 0.1;
		}
	}
	if (IC->IsKeyDown(Windows::System::VirtualKey::D)) {
		for (int i = 0; i < _objects.size(); i++) {
			_positions[i].x -= 0.1;
		}
	}
	if (IC->IsKeyDown(Windows::System::VirtualKey::A)) {
		for (int i = 0; i < _objects.size(); i++) {
			_positions[i].x += 0.1;
		}
	}
	if (IC->IsKeyDown(Windows::System::VirtualKey::R)) {
		for (int i = 0; i < _objects.size(); i++) {
			_objects[i]->GetMesh()->GetVertices()->color.x = 0;
		}
	}
	if (IC->IsKeyDown(Windows::System::VirtualKey::Home)) {
		_positions = _initial[0];
		_orients = _initial[1];
	}

	for (int i = 0; i < _objects.size(); i++) {
		_objects[i]->GetWorld()->ScaleAndRotateAndTranslate(XMFLOAT3(1, 1, 1), _orients[i], _positions[i]);
	}
}

void Scene::Render(std::shared_ptr<VanityCore>& VC) {
	Draw(VC, true);
}
void Scene::Draw(std::shared_ptr<VanityCore>& VC, bool) {

	auto DC = VC->GetD3DDeviceContext();
	for (int i = 0; i < _objects.size(); i++) {
		_objects[i]->Bind(DC);
		_objects[i]->Draw(DC);
	}
}
void Scene::Release() {
	for (int i = 0; i < _objects.size(); i++) {
		_objects[i]->Release();
	}
	_camera.Release();
	_textures.Release();
}