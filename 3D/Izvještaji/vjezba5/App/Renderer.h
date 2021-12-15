#pragma once
#include"pch.h"
#include<random>
#include"Timer.h"

class Renderer {
private:
	std::default_random_engine _generator;
	std::uniform_int_distribution<int> _distribution{ 50,150 };
	uint32_t _processingtime, _renderingtime, _framecount;
	float _elapsedtime;
public:
	Renderer(uint32_t processingtime, uint32_t renderingtime);
	void ProcessMessages();
	void Render();
	void CalculateStatistics(Timer&);
};