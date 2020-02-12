#include "looper.hpp"

Looper* Looper::_instance_ptr = NULL;
Timer* Looper::m_10_loop_timer = NULL;
Timer* Looper::m_100_loop_timer = NULL;
Timer* Looper::m_1k_loop_timer = NULL;

Looper::Looper()
{
    _instance_ptr = this;
    _instance_ptr->m_10_loop_timer = new Timer();
    _instance_ptr->m_100_loop_timer = new Timer();
    _instance_ptr->m_1k_loop_timer = new Timer();
    _instance_ptr->m_10_loop_timer->tick();
    _instance_ptr->m_100_loop_timer->tick();
    _instance_ptr->m_1k_loop_timer->tick();
}

void Looper::Loop10Hz() 
{
    if(_instance_ptr->m_10_loop_timer->tockMicroSeconds() >= Loop10Hz_dt)
    {   
        for (TimedBlock* const& i : _instance_ptr->_timed_blocks)
        {
            if(i->getLoopTime() == block_frequency::hz10)
            {
                //Logger::getAssignedLogger()->log("called 10 hz", LoggerLevel::Error);
                i->loopInternal();
            }
        }
        _instance_ptr->m_10_loop_timer->tick();
    }
} 

void Looper::Loop100Hz() 
{ 
    if(_instance_ptr->m_100_loop_timer->tockMicroSeconds() >= Loop100Hz_dt)
    {
        for (TimedBlock* const& i : _instance_ptr->_timed_blocks)
        {
            if(i->getLoopTime() == block_frequency::hz100)
            {
                i->loopInternal();
            }
        }
        _instance_ptr->m_100_loop_timer->tick();
    }
} 

void Looper::Loop1KHz() 
{  
    if(_instance_ptr->m_1k_loop_timer->tockMicroSeconds() >= Loop1KHz_dt)
    { 
        for (TimedBlock* const& i : _instance_ptr->_timed_blocks)
        {
            if(i->getLoopTime() == block_frequency::hz1000)
            {
                i->loopInternal();
            }
        }
        _instance_ptr->m_1k_loop_timer->tick();
    }
} 

void Looper::Loop()
{
    _instance_ptr->Loop10Hz();
    _instance_ptr->Loop100Hz();
    //_instance_ptr->Loop1KHz();
}

void Looper::addTimedBlock(TimedBlock* t_cs)
{
    _timed_blocks.push_back(t_cs);
}
