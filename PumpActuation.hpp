#pragma once

#include "ActuationSystem.hpp"
#include "logger.hpp"

// TODO make defines in constructor
class PumpActuation : public ActuationSystem
{
private:

    Actuator* m_pump;
    void actuate(Actuator*, int);
    
public:
    void receive_msg_data(DataMessage* t_msg);
    PumpActuation(Actuator*);
};