#include"pch.h"
#include<iostream>
#include<thread>
#include<chrono>
#include"Renderer.h"

using namespace std;

Renderer::Renderer(uint32_t processingtime, uint32_t renderingtime) :
_processingtime{processingtime}, _renderingtime{renderingtime}
{ _framecount = _elapsedtime = 0; }

void Renderer::ProcessMessages() {
	this_thread::sleep_for(chrono::milliseconds(_processingtime));
}

void Renderer::Render() {
	unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
	_generator.seed(seed);
	this_thread::sleep_for(chrono::milliseconds(_distribution(_generator)));
}

void Renderer::CalculateStatistics(Timer& timer) {
	_framecount++;
	_elapsedtime += timer.GetElapsedTime();
	if (_elapsedtime > 1.0) {
		float fps = _framecount / _elapsedtime;
		float mspf = _elapsedtime / _framecount;
		//std::wostringstream ss;
		//ss << L"fps: " << fps << L" | mspf: " << mspf << endl;
		//OutputDebugStringW(ss.str().c_str());
		_elapsedtime = 0;
		_framecount = 0;
	}
}
