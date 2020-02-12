#pragma once 

#include "Acc.hpp"
#include "Gyro.hpp"
#include "Mag.hpp"

class NineAxisSensor
{
public:

	virtual Acc* getAcc() = 0;
	virtual Gyro* getGyro() = 0;
	virtual Mag* getMag() = 0;
	virtual void updateReadings() = 0;
	virtual Vector3D<int> getAccelReadings() = 0;
	virtual Vector3D<int> getGyroReadings() = 0;
	virtual Vector3D<int> getMagReadings() = 0;
	virtual void setSettings(sens_type, setting_type, int) = 0;

};