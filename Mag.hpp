#pragma once 

#include "ThreeAxisSensor.hpp"
#include "CompassProvider.hpp"

class Mag : public ThreeAxisSensor, public CompassProvider
{
public:

	Mag();

	sens_type getSensType();
	void startCalibration();
	void stopCalibration();
	void resetCalibration();
	sen_status getSensorStatus();
	Vector3D<float> getCalibratedData(); 
	Vector3D<float> GetCompass(); 

	virtual void setSettings(setting_type, float) = 0;

protected:

	void setSens(float);

	virtual Vector3D<int> getRawData() = 0;

private:

	float sens;

	Vector3D<int> raw;
	Vector3D<int> calibration_offset; 
	Vector3D<float> calibration_scale;
	Vector3D<float> calibrated;

	bool calibration_flag = false;
	int calibration_counter;
	Vector3D<int> calibration_temp;

	void doCalibrationCycle();
	void updateCalibrationTerms(); 
	
};