#pragma once 

#include "Mag.hpp"
#include "SparkFunMPU9250-DMP.h"
#include "NineAxisSensor.hpp"

class SFMPU9250_mag : public Mag
{
public:

	SFMPU9250_mag(NineAxisSensor*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();

private:

	NineAxisSensor* _imu;
};