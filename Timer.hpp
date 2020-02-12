#pragma once

#include <Arduino.h>
#undef max
#undef min

class Timer
{

public: //timer in milliseconds

	Timer();
	
	void tick();
	int tockMicroSeconds();
	int tockMilliSeconds();

private:

	int m_time_milli;
	int m_time_micro;
};