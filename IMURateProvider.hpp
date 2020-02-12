#pragma once
#include "Provider.hpp"
#include "ThreeAxisSensorMsg.hpp"
#include "BodyRateProvider.hpp"
#include "TimedBlock.hpp"

// #include "Arduino.h"
// #undef max
// #undef min

class IMURateProvider : public Provider, public TimedBlock
{

private:

    ThreeAxisSensorMsg m_data;
    BodyRateProvider* m_rate_prov;

    Vector3D<float> getBodyRate();

public:

    IMURateProvider(BodyRateProvider* , block_frequency);
    void loopInternal();

};