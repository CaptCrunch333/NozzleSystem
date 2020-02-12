#include "SF_MPU9250_sensor.hpp"

SFMPU9250_sensor::SFMPU9250_sensor() //TODO: we need to add a logger for imu fail!!!
{
	if(_imu.begin() != INV_SUCCESS)
	{
		delay(1000);
	}
}

Acc* SFMPU9250_sensor::getAcc()
{
	return (Acc*) _acc;
}

Gyro* SFMPU9250_sensor::getGyro()
{
	return (Gyro*) _gyro;
}

Mag* SFMPU9250_sensor::getMag()
{
	return (Mag*) _mag;
}

void SFMPU9250_sensor::updateReadings()
{
	if(_imu.dataReady())
	{
		_imu.update();
	}
}

Vector3D<int> SFMPU9250_sensor::getAccelReadings()
{
	Vector3D<int> temp;

	temp.x = _imu.ax;
	temp.y = _imu.ay;
	temp.z = _imu.az;

	return temp;
}

Vector3D<int> SFMPU9250_sensor::getGyroReadings()
{
	Vector3D<int> temp;

	temp.x = _imu.gx;
	temp.y = _imu.gy;
	temp.z = _imu.gz;

	return temp;
}

Vector3D<int> SFMPU9250_sensor::getMagReadings()
{
	Vector3D<int> temp;

	temp.x = _imu.mx;
	temp.y = _imu.my;
	temp.z = _imu.mz;

	return temp;
}

void SFMPU9250_sensor::setSettings(sens_type sensor_name, setting_type setting_name, int val)
{
	if(setting_name == LPF) //TODO: add a warning here that it effects all sensors
	{
		_imu.setLPF(val);
		_acc->setSettings(setting_name, _imu.getLPF());
		_gyro->setSettings(setting_name, _imu.getLPF());
		_mag->setSettings(setting_name, _imu.getLPF());
	}
	else if(setting_name == FSR)
	{
		if(sensor_name == ACCELEROMETER)
		{
			_imu.setAccelFSR(val);
			_acc->setSettings(SENS, _imu.getAccelSens());
			_acc->setSettings(FSR, val);
		}
		else if(sensor_name == GYROSCOPE)
		{
			_imu.setGyroFSR(val);
			_gyro->setSettings(SENS, _imu.getGyroSens());
		}
		else if(sensor_name == MAGNETOMETER)
		{
			//TODO: add a warning here, since it is fixed for this type of sensors
		}
	}
	else if(setting_name == SAMPLERATE)
	{
		if(sensor_name == ACCELEROMETER || sensor_name == GYROSCOPE) //TODO: add a warning here that they are coupled
		{
			_imu.setSampleRate(val);
			_acc->setSettings(setting_name, _imu.getSampleRate());
			_gyro->setSettings(setting_name, _imu.getSampleRate());
		}
		else if(sensor_name == MAGNETOMETER)
		{
			_imu.setCompassSampleRate(val);
			_mag->setSettings(setting_name, _imu.getCompassSampleRate());
		}
	}
}