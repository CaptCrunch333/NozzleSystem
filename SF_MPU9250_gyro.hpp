#pragma once 

#include "Gyro.hpp"
#include "SparkFunMPU9250-DMP.h"
#include "NineAxisSensor.hpp"

class SFMPU9250_gyro : public Gyro
{
public:

	SFMPU9250_gyro(NineAxisSensor*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();

private:

	NineAxisSensor* _imu;

};