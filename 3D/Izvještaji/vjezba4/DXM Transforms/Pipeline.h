#pragma once
#include<DirectXMath.h>
#include"Vertex.h"
#include"Model.h"

Model Transform(Model& model, DirectX::CXMMATRIX& transform) {
	Model tfmodel = model;
	for (int i = 0; i < model.GetVertexCount(); i++) {
			DirectX::XMStoreFloat4(
				&(tfmodel.GetVerticesAddress(i)->position),
				DirectX::XMVector3Transform(
					DirectX::XMLoadFloat4(&(tfmodel.GetVerticesAddress(i)->position)),
					transform)
			);
	}
	return tfmodel;
}

inline Model PerspectiveDivide(Model& model) {
	Model projmodel = model;
	for (int i = 0; i < model.GetVertexCount(); i++) {
		float w = projmodel.GetVerticesAddress(i)->position.w;
		DirectX::XMStoreFloat4(
			&(projmodel.GetVerticesAddress(i)->position),
			DirectX::XMVectorDivide(
				DirectX::XMLoadFloat4(&(projmodel.GetVerticesAddress(i)->position)),
				DirectX::XMVECTOR{ w,w,w,w }
			)
		);
	}
	return projmodel;
}