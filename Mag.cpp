#include "Mag.hpp"

Mag::Mag()
{
	calibration_offset = 0;
	calibration_scale = 1.f;
}

sens_type Mag::getSensType(void)
{
	return MAGNETOMETER;
}

void Mag::resetCalibration(void)
{
	calibration_offset = 0;
	calibration_scale = 1.f;
	calibration_counter = 0;
}

void Mag::startCalibration(void)
{
	resetCalibration();
	calibration_flag = true;
}

void Mag::stopCalibration(void)
{
	calibration_flag = false;
	updateCalibrationTerms();
}

void Mag::updateCalibrationTerms(void)
{
	//TODO: implement
}

sen_status Mag::getSensorStatus(void)
{
	//TODO: implement
	if(calibration_flag)
	{
		return CALIBRATING;
	}
	else
	{
		return CALIBRATED;
	}
}

void Mag::doCalibrationCycle(void)
{
	//TODO: implement
}

void Mag::setSens(float tmp)
{
	sens = tmp;
}

Vector3D<float> Mag::getCalibratedData()
{
	raw = getRawData();
	if(calibration_flag) //TODO: raw is int, but the func returns float
	{
		doCalibrationCycle();
		return raw;
	}
	calibrated = (Vector3D<float>((raw - calibration_offset)) * calibration_scale) / sens;
	return calibrated;
}

Vector3D<float> Mag::GetCompass()
{
	return getCalibratedData();
}