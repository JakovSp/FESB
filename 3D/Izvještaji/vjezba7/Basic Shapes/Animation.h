#pragma once
#include"pch.h"

namespace vxe {
	class Animation {
	private:
		float _rps{ DirectX::XM_PI / 6 };
		float _angle{ 0.0f };

	public:
		float Angle(float time) {
			return _angle += time * _rps;
		}
	};
}