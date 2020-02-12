#pragma once

#include "Actuator.hpp"
#include "ActuationSystem.hpp"
#include <vector>
#include <math.h>
#include "logger.hpp"

// TODO make defines in constructor
class NozzleActuation : public ActuationSystem
{
private:

    int _min, _max, _vrtclCMD, _hrzntlCMD;
    Actuator* hrzntl;
    Actuator* vrtcl;
    void actuate(Actuator*, int);
    
public:
    void receive_msg_data(DataMessage* t_msg);
    void scan(void);
    int setRange(int, int);
    NozzleActuation(Actuator*, Actuator*);
};