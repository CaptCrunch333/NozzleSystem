#include "SF_MPU9250_acc.hpp"

SFMPU9250_acc::SFMPU9250_acc(NineAxisSensor* tmp)
{
	_imu = tmp;
}

void SFMPU9250_acc::setSettings(setting_type setting_name, float setting_val)
{
	if(setting_name == SENS)
	{
		setSens(setting_val);
	}
	if(setting_name == FSR)
	{
		setCalibCoeff(setting_val/16.f);
		setgWorkingRange(32768.f/setting_val);
	}
}

Vector3D<int> SFMPU9250_acc::getRawData()
{
	_imu->updateReadings();
	Vector3D<int> tmp = _imu->getAccelReadings();
	Vector3D<int> ret_val;
	ret_val.x = -1 * tmp.y;
	ret_val.y = tmp.x;
	ret_val.z = tmp.z;
	return ret_val;
}