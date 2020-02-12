#include "ArduPump.hpp"

ArduPump::ArduPump(int pin, RelayType t_relayType)
{
    this->m_pin = pin;
    pinMode(m_pin, OUTPUT);
    if(t_relayType == RelayType::NO) {
        m_normallyClosed = false;
        digitalWrite(m_pin, LOW);
    }
    else {
        m_normallyClosed = true;
        digitalWrite(m_pin, HIGH);
    }
}

void ArduPump::applyCommand(int command)
{
    if(command == 0) {
        if(m_normallyClosed) {
            digitalWrite(m_pin, HIGH);
        }
        else {
            digitalWrite(m_pin, LOW);
        }
    }
    else {
        if(m_normallyClosed) {
            digitalWrite(m_pin, LOW);
        }
        else {
            digitalWrite(m_pin, HIGH);
        }
    }
}