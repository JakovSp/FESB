#include"pch.h"
#include"Camera.h"

using namespace std;
using namespace vxe;
using namespace DirectX;

Camera::Camera() {
	DebugPrint(string("Camera() konstruktor"));
}

void Camera::Initialize(shared_ptr<VanityCore>& VC) {
	auto device = VC->GetD3DDevice();
	_view = make_shared<ViewTransform>(device);
	_view->SetView(XMLoadFloat3(&_eye), XMLoadFloat3(&_lookat), XMLoadFloat3(&_up));
	auto size = VC->GetOutputSize();
	auto r = size.Width / size.Height;
	float fov = 70.0f * XM_PI / 180.0f;
	float n = 0.01f;
	float f = 1000.0f;
	auto orient = VC->GetOrientationTransform3D();
	_projection = make_shared<ProjectionTransform>(device);
	_projection->SetProjection(XMLoadFloat4x4(&orient), fov, r, n, f);
}

void Camera::Bind(shared_ptr<VanityCore>& VC) {
	auto context = VC->GetD3DDeviceContext();
	_view->Update(context);
	auto buffer = _view->GetConstantBuffer();
	buffer->Bind(context, ProgrammableStage::VertexShaderStage, _viewregister);
	_projection->Update(context);
	auto projbuffer = _projection->GetConstantBuffer();
	projbuffer->Bind(context, ProgrammableStage::VertexShaderStage, _projectionregister);
}

void Camera::Release() {
	_view->Reset();
	_projection->Reset();
}