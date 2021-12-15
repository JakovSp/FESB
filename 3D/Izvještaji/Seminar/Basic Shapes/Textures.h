#pragma once
#include<../Engine/Pipeline Resources/Textures/Texture Base.h>
#include<../Engine/Pipeline Resources/Textures/Texture2D.h>
#include"pch.h"

namespace vxe
{
	class Textures
	{
	private:
		std::shared_ptr<Texture2D> _texture;
		std::wstring _texturefilename = L"Assets/Wall.dds";

		uint32_t _samplerregister = 0;
		uint32_t _textureregister = 0;

	public:
		Textures();
		void Load(std::vector < concurrency::task<void>>&, std::shared_ptr<VanityCore>&);
		void Initialize(std::shared_ptr<VanityCore>&);
		void Bind(std::shared_ptr<VanityCore>&);

		void Release();
	};
}