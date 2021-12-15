
#pragma once

//
//	Cubes.h
//  Defining cubes 
//
//  © VanityXS - DirectX 11.2 Student Engine. Zoraja Consulting d.o.o. All rights reserved.
//	vMay21
//

#include "pch.h"

#include <Utilities.h>
#include <Models/Mesh.h>


namespace vxe {


	template <typename T, typename U>
	class CustomCube : public Mesh<T, U> {};

	template <>
	class CustomCube<DirectX::VertexPositionColor, uint16_t> : public Mesh<DirectX::VertexPositionColor, uint16_t> {
	private:
		float _depth = 1.0f;
		float _height = 1.0f;
		float _width = 1.0f;
		float _red = 1.0f;
	public:
		CustomCube();
		CustomCube(float  d, float h, float w) : _depth{ d }, _height{ h }, _width{ w }{}
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*) override ;

		// Loading from a file
		virtual concurrency::task<void> LoadAsync(_In_ ID3D11Device2*, const std::wstring&) override ;

		// Creating from memory
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*, const std::vector<char>&) override ;
	
	};

	template <>
	class CustomCube<DirectX::VertexPositionNormal, uint16_t> : public Mesh<DirectX::VertexPositionNormal, uint16_t > {
	private:
		float _depth = 1.0f;
		float _height = 1.0f;
		float _width = 1.0f;
	public:
		CustomCube();
		CustomCube(float  d, float h, float w) : _depth{ d }, _height{ h }, _width{ w }{}

		// Vertices are hardcoded
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*) override;

		// Loading from a file
		virtual concurrency::task<void> LoadAsync(_In_ ID3D11Device2*, const std::wstring&) override;

		// Creating from memory
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*, const std::vector<char>&);
	};

	template <>
	class CustomCube<DirectX::VertexPositionNormalTexture, uint16_t> : public Mesh<DirectX::VertexPositionNormalTexture, uint16_t> {
	private:
		float _depth = 1.0f;
		float _height = 1.0f;
		float _width = 1.0f;
	public:
		CustomCube();
		CustomCube(float  d, float h, float w) : _depth{ d }, _height{ h }, _width{ w }{}

		// Vertices are hardcoded
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*) override;

		// Loading from a file
		virtual concurrency::task<void> LoadAsync(_In_ ID3D11Device2*, const std::wstring&) override;

		// Creating from memory
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*, const std::vector<char>&) override;
	};

	template <>
	class CustomCube<DirectX::VertexPositionNormalColor, uint16_t> : public Mesh<DirectX::VertexPositionNormalColor, uint16_t> {
	private:
		float _depth = 1.0f;
		float _height = 1.0f;
		float _width = 1.0f;
		float _red = 0.1f;
		float _green = 0.1f;
		float _blue = 0.1f;
		float _alpha = 1.0f;
	public:
		CustomCube();
		CustomCube(float  d, float h, float w, float  R, float G, float B, float alf) :
			_depth{ d },
			_height{ h },
			_width{ w },
			_red{ R },
			_green{ G },
			_blue{ B },
			_alpha{ alf }
		{}

		// Vertices are hardcoded
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*) override;

		// Loading from a file
		virtual concurrency::task<void> LoadAsync(_In_ ID3D11Device2*, const std::wstring&) override;

		// Creating from memory
		virtual concurrency::task<void> CreateAsync(_In_ ID3D11Device2*, const std::vector<char>&) override;
	};
}