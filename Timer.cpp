#include "Timer.hpp"

Timer::Timer()
{
    
}

void Timer::tick()
{
    m_time_milli = millis();
    m_time_micro = micros();
}

int Timer::tockMicroSeconds()
{
    return (micros() - m_time_micro);
}

int Timer::tockMilliSeconds()
{
    return (millis() - m_time_milli);
}