#pragma once

#include "Actuator.hpp"
#include <Servo.h>


class Arduserv : public Actuator { 
private:
    Servo servo;
    int _pin;
    int m_bias;
    bool m_dir = false;
public:
    bool initialize(){};
    void applyCommand(int command);
    Arduserv(int pin, bool, int initial_pos);
};