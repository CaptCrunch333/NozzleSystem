#include "Arduserv.hpp"

Arduserv::Arduserv(int pin, bool t_dir, int initial_pos)
{
    this->_pin = pin;
    m_dir = t_dir;
    this->servo.attach(this->_pin);
    m_bias = 0;
    this->applyCommand(initial_pos);
    m_bias = initial_pos;
}

void Arduserv::applyCommand(int command)
{
    if(m_dir)
    {
        servo.write(-1*(command + m_bias));
    }
    else
    {
        servo.write(command + m_bias);
    }
}