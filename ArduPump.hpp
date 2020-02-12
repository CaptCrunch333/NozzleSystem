#pragma once

#include "Actuator.hpp"
#include <Arduino.h>
#undef max
#undef min

enum class RelayType {NC, NO};

class ArduPump : public Actuator { 
private:
    int m_pin;
    bool m_normallyClosed = false;
public:
    bool initialize(){};
    void applyCommand(int);
    ArduPump(int, RelayType = RelayType::NO);
};