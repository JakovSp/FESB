#pragma once
#include<Windows.h>
#include<string>

class Timer {
private:
	double _period, _elapsed;
	__int64 _base, _stop, _paused, _current, _last;
	bool _pausing;
public:
		Timer();
		void Reset();
		void Pause();
		void Resume();
		void Tick();
		float GetElapsedTime() {
			return static_cast<float>(_elapsed);
		}
		float GetTotalTime();
		std::string ToString() const;
};