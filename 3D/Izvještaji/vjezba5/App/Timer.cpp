#include"pch.h"
#include<iostream>
#include<sstream>
#include"Timer.h"

using namespace std;

Timer::Timer() : 
	_elapsed{ -1.0f },
	_pausing{ false },
	_period{ 0 }
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	_period = 1.0f/frequency.QuadPart;
}

void Timer::Reset() {
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	_base = counter.QuadPart;
	_last = counter.QuadPart;
	_stop = 0;
	_pausing = false;
}

void Timer::Pause() {
	if (!_pausing) {
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		_stop = counter.QuadPart;
		_pausing = false;
	}
}

void Timer::Resume() {
	if (_pausing) return;
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	_paused += counter.QuadPart - _stop;
	_last = counter.QuadPart;
	_stop = 0;
	_pausing = false;
}

void Timer::Tick() {
	if (_pausing) { _elapsed = 0.0; return; }
	LARGE_INTEGER counter;
	QueryPerformanceCounter(&counter);
	_current = counter.QuadPart;
	_elapsed += (_current - _last ) * _period;
	_last = _current;
	if (_elapsed < 0) { _elapsed= 0.0; }
}

float Timer::GetTotalTime() {
	return _elapsed;
}

string Timer::ToString() const {
	stringstream output;
	output << "Elapsed Time: " << _elapsed << endl
		<< "Period: " << _period << endl
		<< "Base: " << _base << endl
		<< "Stop: " << _stop << endl
		<< "Paused: " << _paused << endl
		<< "Current: " << _current << endl
		<< "Last: " << _last << endl
		<< "Pausing: " << _pausing << endl;

		return output.str();
}