#include"pch.h"
#include"Pipeline.h"

using namespace std;
using namespace vxe;
using namespace concurrency;
using namespace DirectX;

Pipeline::Pipeline() {

}

void Pipeline::LoadShaders(std::vector<concurrency::task<void>>& tasks, std::shared_ptr<VanityCore>& VC){
	auto device = VC->GetD3DDevice();
	_vertexshader = make_shared<VertexShader<VertexType_t>>();
	tasks.push_back(_vertexshader->CreateAsync(device, L"VertexShader.cso"));
	_pixelshader = make_shared<PixelShader>();
	tasks.push_back(_pixelshader->CreateAsync(device, L"PixelShader.cso"));
}
void Pipeline::BindShaders(std::shared_ptr<VanityCore>& VC) {
	auto context = VC->GetD3DDeviceContext();
	_vertexshader->Bind(context);
	_pixelshader->Bind(context);
}

void Pipeline::Release() {
	_vertexshader->Reset();
	_pixelshader->Reset();
}

