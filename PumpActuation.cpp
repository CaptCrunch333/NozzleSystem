#include "PumpActuation.hpp"

//2nd constructor, first in header
PumpActuation::PumpActuation(Actuator* t_pump) {
    m_pump = t_pump;
}

void PumpActuation::receive_msg_data(DataMessage* t_msg) {
    if(t_msg->getType() == msg_type::CONTROLLEROUTPUTMSG) {
        ControllerOutputMsg* control_system_msg = (ControllerOutputMsg*)t_msg;
        if(control_system_msg->getSource() == control_system::pump)         {
            actuate(m_pump, (int) (control_system_msg->getControlSignal()));
        }
    }
}

void PumpActuation::actuate(Actuator* t_actuator, int val) {
    t_actuator->applyCommand(val);
}