#include"pch.h"
#include"Rendering.h"
#include"Pipeline.h"

using namespace std;
using namespace vxe;
using namespace concurrency;
using namespace DirectX;
using namespace Windows::Foundation;

Renderer::Renderer() {
	_scene = make_shared<Scene>();
	_pipeline = make_shared<Pipeline>();
	_inputcontroller = ref new InputController();
}

void Renderer::CreateDeviceResources() {
	vector<task<void>> tasks;
	_scene->LoadAssets(tasks, _vanitycore);
	_pipeline->LoadShaders(tasks, _vanitycore);
	when_all(tasks.begin(), tasks.end()).then([this]() {
		DebugPrint(string("Loading complete"));
		_loadingcomplete = true;
		});
}

void Renderer::CreateWindowResources() {
	//_scene->SetTexture(_vanitycore);
	_scene->SetCamera(_vanitycore);

}

void Renderer::Render() {
	if (!_loadingcomplete) return;
	_pipeline->BindShaders(_vanitycore);
	_scene->Render(_vanitycore);
	_vanitycore->SetRasterizerState();
}

void Renderer::Update(DX::StepTimer const& timer) {
	_scene->Update(timer, _inputcontroller);
}
void Renderer::ReleaseDeviceResources(){
	_loadingcomplete = false;
	_scene->Release();
	_pipeline->Release();
}