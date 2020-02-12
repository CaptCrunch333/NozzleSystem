#pragma once 

#include "ThreeAxisSensor.hpp"
#include "BodyAccProvider.hpp"

class Acc : public ThreeAxisSensor, public BodyAccProvider
{
public:

	Acc();

	sens_type getSensType();
	void startCalibration();
	void stopCalibration();
	void resetCalibration();
	sen_status getSensorStatus();
	Vector3D<float> getCalibratedData();
	Vector3D<float> getBodyAcceleration();

	virtual void setSettings(setting_type, float) = 0;

protected:

	void setSens(float);
	void setCalibCoeff(float);
	void setgWorkingRange(float);
	virtual Vector3D<int> getRawData() = 0;


private:

	Vector3D<int> raw;
	Vector3D<int> calibration_offset;
	Vector3D<float> calibrated;

	float sens;
	float conv_coef = 1;
	float g_in_working_range = 0;

	bool calibration_flag = false;
	int calibration_counter;
	Vector3D<int> calibration_temp;

	void doCalibrationCycle();
	void updateCalibrationTerms();

};