#include"pch.h"
#include"Renderer.h"


using namespace vxe;
using namespace std;
using namespace concurrency;

Renderer::Renderer() {
	DebugPrint(std::string("Renderer() "));
}

void Renderer::CreateDeviceResources() {
	DebugPrint(string("Creating Device Resources"));
	vector<task<void>> tasks;
	when_all(tasks.begin(), tasks.end()).then([this]() {
		DebugPrint(string("Loading complete"));
		_loadingcomplete = true;
		});
	DebugPrint(string("Creating Device Resources"));
}

void Renderer::CreateWindowResources() {
	DebugPrint(string("Create Window Resources"));
	auto info = _vanitycore->GetOutputSize();
	DebugPrint(string("Count " + to_string(info.Width) + to_string(info.Height)));
}

void Renderer::Update(DX::StepTimer const& timer) {
	auto count = timer.GetFrameCount();
	if (count % 30) {
		return;
	}
	auto time = timer.GetTotalSeconds();
	auto frames = timer.GetElapsedTicks();
	auto fps = timer.GetFramesPerSecond();
}
void Renderer::Render() {
	if (_loadingcomplete)
		return;

	DebugPrint(string("Loading Complete"));
}

void Renderer::ReleaseDeviceResources() {
	DebugPrint(string("Releasing Device Resources"));
	_loadingcomplete = false;
}