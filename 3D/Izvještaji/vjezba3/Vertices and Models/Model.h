#pragma once
#include<sstream>
#include<vector>
#include"Vertex.h"

class Model {
private:
	std::vector<Vertex> _vertices;
public:
	Model() {}
	Model(	const Vertex& vtx1,
			const Vertex& vtx2,
			const Vertex& vtx3,
			const Vertex& vtx4) 
	{
		_vertices.push_back(vtx1);
		_vertices.push_back(vtx2);
		_vertices.push_back(vtx3);
		_vertices.push_back(vtx4);
	}

	std::string ToString() const {
		std::stringstream info;
		info << std::endl;
		for (auto it = begin(_vertices); it < end(_vertices); ++it) {
			info << it.operator*().ToString() << std::endl;
		}
		return info.str();
	}

	void AddVertex(const Vertex& vertex) {
		_vertices.push_back(vertex);
	}
	Vertex* GetVerticesAddress(uint32_t i) {
		return &(this->_vertices[i]);
	}
	uint32_t GetVertexCount() {
		return _vertices.size();
	}
};