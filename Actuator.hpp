#pragma once

#include "DataMessage.hpp"
#include "MsgEmitter.hpp"
#include "MsgReceiver.hpp"
#include "ControllerOutputMsg.hpp"

class  Actuator {
    public:
        virtual bool initialize() = 0;
        virtual void applyCommand(int command) = 0;

        Actuator() {};
};