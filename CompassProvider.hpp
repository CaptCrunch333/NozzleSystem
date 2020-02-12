#pragma once 

#include "Vector3D.hpp"

class CompassProvider
{
public:

	virtual Vector3D<float> GetCompass() = 0;

};