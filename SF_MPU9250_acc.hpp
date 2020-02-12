#pragma once 

#include "Acc.hpp"
#include "SparkFunMPU9250-DMP.h"
#include "NineAxisSensor.hpp"

class SFMPU9250_acc : public Acc
{
public:

	SFMPU9250_acc(NineAxisSensor*);
	void setSettings(setting_type, float);

protected:

	Vector3D<int> getRawData();
	
private:

	NineAxisSensor* _imu;
	
};