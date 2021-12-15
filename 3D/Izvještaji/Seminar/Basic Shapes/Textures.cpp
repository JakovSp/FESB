#include"pch.h"
#include"Textures.h"

using namespace std;
using namespace vxe;
using namespace DirectX;
using namespace concurrency;

Textures::Textures()
{
	DebugPrint(string("\t Textures::Konstuktor...\n"));
}

void Textures::Load(vector<task<void>>& tasks, shared_ptr<VanityCore>& vanitycore)
{
	DebugPrint(string("\t Textures::Load...\n"));
	auto device = vanitycore->GetD3DDevice();
	auto context = vanitycore->GetD3DDeviceContext();

	_texture = make_shared<Texture2D>(device, DXGI_FORMAT_R8G8B8A8_UNORM);
	tasks.push_back(_texture->CreateDDSAsync(context, _texturefilename));
}

void Textures::Initialize(shared_ptr<VanityCore>& vanitycore)
{
	DebugPrint(string("\t Textures::Initialize...\n"));

	_texture->CreateSamplerState();
	_texture->CreateShaderResourceView();
}
void Textures::Bind(shared_ptr<VanityCore>& vanitycore)
{
	auto context = vanitycore->GetD3DDeviceContext();

	_texture->BindSamplerState(context, _samplerregister);
	_texture->BindShaderResourceView(context, ProgrammableStage::PixelShaderStage, _textureregister);
}

void Textures::Release()
{
	_texture->Reset();
}