#pragma once

#include "Timer.hpp"
#include "logger.hpp"
#include "TimedBlock.hpp"
#include <vector>
#include "logger.hpp"
//TODO: make superclass "looper"
const int hardwareLoop1KHz_dt = 1000; //in us
const int Loop10Hz_dt = 100000; //in us
const int Loop100Hz_dt = 10000; //in us
const int Loop1KHz_dt = 1000; //in us

//TODO: pass _dt to reflect looping rate!!!
class Looper
{
    //TODO convert to singleton
    //TODO create Timed Block as parent of ControlSystem

    private:

        std::vector<TimedBlock*> _timed_blocks;
        static Looper* _instance_ptr;
        static Timer* m_10_loop_timer;
        static Timer* m_100_loop_timer;
        static Timer* m_1k_loop_timer;

        static void Loop10Hz();
        static void Loop100Hz();
        static void Loop1KHz();

    public:

        static void Loop();
        void addTimedBlock(TimedBlock*);

        Looper();
};