#include "Gyro.hpp"
//TODO remove
Gyro::Gyro()
{
	calibration_offset = 0;
}

sens_type Gyro::getSensType(void)
{
	return GYROSCOPE;
}

void Gyro::resetCalibration(void)
{
	calibration_offset = 0;
	calibration_counter = 0;
}

void Gyro::startCalibration(void)
{
	resetCalibration();
	calibration_flag = true;
}

void Gyro::stopCalibration(void)
{
	calibration_flag = false;
	updateCalibrationTerms();
}

void Gyro::updateCalibrationTerms(void)
{
	calibration_offset = calibration_temp;
}

sen_status Gyro::getSensorStatus(void)
{
	if(calibration_flag)
	{
		return CALIBRATING;
	}
	else
	{
		return CALIBRATED;
	}
}

void Gyro::setSens(float tmp)
{
	sens = tmp * 180.f/M_PI;
}

void Gyro::doCalibrationCycle(void)
{
	float avg_factor = 0;

	if((calibration_counter + 1) > 0)
	{
		avg_factor = (float) (calibration_counter - 1);
		avg_factor = (float) avg_factor/calibration_counter;

		calibration_temp = Vector3D<int>(Vector3D<float>(calibration_temp) * avg_factor + Vector3D<float>(raw) / (float)calibration_counter);
	}
}

Vector3D<float> Gyro::getCalibratedData(void)
{
	raw = getRawData();
	if(calibration_flag) //TODO: raw is int, but the func returns float
	{
		doCalibrationCycle();
		return raw;
	}
	calibrated = Vector3D<float>((raw - calibration_offset)) / sens;

	return calibrated;
}

Vector3D<float> Gyro::getBodyRate(void)
{	
	return getCalibratedData();
}