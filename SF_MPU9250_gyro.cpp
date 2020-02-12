#include "SF_MPU9250_gyro.hpp"

SFMPU9250_gyro::SFMPU9250_gyro(NineAxisSensor* tmp)
{
	_imu = tmp;
}

void SFMPU9250_gyro::setSettings(setting_type setting_name, float setting_val)
{
	if(setting_name == SENS)
	{
		setSens(setting_val);
	}
}

Vector3D<int> SFMPU9250_gyro::getRawData()
{
	_imu->updateReadings();
	Vector3D<int> tmp = _imu->getGyroReadings();
	Vector3D<int> ret_val;
	ret_val.x = tmp.y;
	ret_val.y = tmp.x;
	ret_val.z = tmp.z;
	return ret_val;
}