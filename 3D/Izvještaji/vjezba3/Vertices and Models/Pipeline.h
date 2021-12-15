#pragma once
#include"../Vectors and Matrices/Matrix4x4.h"
#include"../Vertices and Models/Vertex.h"
#include"../Vertices and Models/Model.h"

Model Transform(Model& model, float4x4& transform) {
	Model tfmodel = model;
	for (int i = 0; i < model.GetVertexCount(); i++) {
		tfmodel.GetVerticesAddress(i)->position = (*(model.GetVerticesAddress(i))).position * transform;
	}
	return tfmodel;
}

inline Model PerspectiveDivide(Model& model) {
	Model projmodel = model;
	for (int i = 0; i < model.GetVertexCount(); i++) {
		projmodel.GetVerticesAddress(i)->position = (*(model.GetVerticesAddress(i))).position / (*(model.GetVerticesAddress(i))).position.w;
	}
	return projmodel;
}