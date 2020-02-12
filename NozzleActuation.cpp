#include "NozzleActuation.hpp"

//2nd constructor, first in header
NozzleActuation::NozzleActuation(Actuator* t_vrtcl, Actuator* t_hrzntl)
{
    vrtcl = t_vrtcl;
    hrzntl = t_hrzntl;
}

void NozzleActuation::receive_msg_data(DataMessage* t_msg)
{
    if(t_msg->getType() == msg_type::CONTROLLEROUTPUTMSG)
    {
        ControllerOutputMsg* control_system_msg = (ControllerOutputMsg*)t_msg;
         if(control_system_msg->getSource() == control_system::pitch)
        {
            actuate(vrtcl, (int) (control_system_msg->getControlSignal() * 180.f/M_PI));
            //Logger::getAssignedLogger()->log("Pitch Motor ",LoggerLevel::Warning);
        }
        else if(control_system_msg->getSource() == control_system::yaw)
        {
            actuate(hrzntl, (int) (control_system_msg->getControlSignal() * 180.f/M_PI));
            //Logger::getAssignedLogger()->log("Yaw Motor ",LoggerLevel::Warning);
        }
    }
}

void NozzleActuation::actuate(Actuator* t_actuator, int val)
{
    if(val > _max)
    {
        t_actuator->applyCommand(_max);
    }
    else if(val < _min)
    {
        t_actuator->applyCommand(_min);
    }
    else
    {
        t_actuator->applyCommand(val);
    }
}

void NozzleActuation::scan(void) //TODO: revise implementaton
{
//     for (int j=this->_min; j<this->_max; j++){

//         for (int i=this->_min; i<this->_max; i++){

//             this->_vrtclCMD = i;
//             this->actuate();
//         }

//         this->_hrzntlCMD = j;
//         this->actuate();

//         for (int i=this->_max; i>this->_min; i--){

//             this->_vrtclCMD = i;
//             this->actuate();
//         }
//     }

//     for (int j=this->_max; j<this->_max; j--){

//         for (int i=this->_min; i<this->_max; i++){

//             this->_vrtclCMD = i;
//             this->actuate();
//         }

//         this->_hrzntlCMD = j;
//         this->actuate();
        
//         for (int i=this->_max; i>this->_min; i--){

//             this->_vrtclCMD = i;
//             this->actuate();
//         }
//     }
}

int NozzleActuation::setRange(int min_value, int max_value)
{
    _min = min_value;
    _max = max_value;
}