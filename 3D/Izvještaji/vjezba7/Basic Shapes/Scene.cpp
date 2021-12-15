#include"pch.h"
#include"Scene.h"
#include"Models/Mesh.h"
#include<Models/Basic Shapes/Pyramids.h>

using namespace std;
using namespace vxe;
using namespace concurrency;
using namespace DirectX;

Scene::Scene() {
	DebugPrint(string("\nScene()"));
}

void Scene::LoadAssets(std::vector<concurrency::task<void>>& tasks, std::shared_ptr<VanityCore>& VC) {
	auto device = VC->GetD3DDevice();
	_object = make_shared<SceneObject<VertextType_t, IndexType_t>>();
	shared_ptr<Mesh<VertextType_t, IndexType_t>> mesh;
		mesh= make_shared<Pyramid<VertextType_t, IndexType_t>>();
	tasks.push_back(mesh->CreateAsync(device));
	auto world = make_shared<WorldTransforms>(device);
	_object->SetMesh(mesh);
	_object->SetWorld(world);
}

void Scene::SetCamera(std::shared_ptr<VanityCore>& VC) {
	_camera.Initialize(VC);
	_camera.Bind(VC);
}
void Scene::Update(const DX::StepTimer& timer) {
	float angle = _animation.Angle(timer.GetElapsedSeconds());
	_object->GetWorld()->RotateY(angle);
}
void Scene::Render(std::shared_ptr<VanityCore>& VC) {
	Draw(VC, true);
}
void Scene::Draw(std::shared_ptr<VanityCore>& VC, bool) {
	auto DC = VC->GetD3DDeviceContext();
	_object->Bind(DC);
	_object->Draw(DC);
}
void Scene::Release() {
	_object->Release();
	_camera.Release();
}