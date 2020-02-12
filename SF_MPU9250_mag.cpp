#include "SF_MPU9250_mag.hpp"

SFMPU9250_mag::SFMPU9250_mag(NineAxisSensor* tmp)
{
	_imu = tmp;
	setSens(0.15);
}

void SFMPU9250_mag::setSettings(setting_type setting_name, float setting_val)
{
	if(setting_name == SENS)
	{
		setSens(setting_val);
	}
}

Vector3D<int> SFMPU9250_mag::getRawData()
{
	_imu->updateReadings();
	Vector3D<int> tmp = _imu->getMagReadings();
	Vector3D<int> ret_val;
	ret_val.x = -1 * tmp.x;
	ret_val.y = tmp.y;
	ret_val.z = -1 * tmp.z;
	return ret_val;
}