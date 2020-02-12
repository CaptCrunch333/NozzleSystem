#pragma once 

#include "NineAxisSensor.hpp"
#include "SparkFunMPU9250-DMP.h"
#include "SF_MPU9250_acc.hpp"
#include "SF_MPU9250_gyro.hpp"
#include "SF_MPU9250_mag.hpp"

class SFMPU9250_sensor : public NineAxisSensor
{
public:

	SFMPU9250_sensor();

	Acc* getAcc();
	Gyro* getGyro();
	Mag* getMag();
	void updateReadings();
	Vector3D<int> getAccelReadings();
	Vector3D<int> getGyroReadings();
	Vector3D<int> getMagReadings();
	void setSettings(sens_type, setting_type, int);
	

private:

	MPU9250_DMP _imu;
	ThreeAxisSensor* _acc = new SFMPU9250_acc((NineAxisSensor*)this);
	ThreeAxisSensor* _gyro = new SFMPU9250_gyro((NineAxisSensor*)this);
	ThreeAxisSensor* _mag = new SFMPU9250_mag((NineAxisSensor*)this);
};