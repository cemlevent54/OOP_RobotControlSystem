
#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

class SensorInterface
{
protected:
	std::string sensorType;
public:
	SensorInterface(std::string _sensorType) : sensorType(_sensorType) {}
	virtual void updateSensor() = 0;
	std::string getSensorType() { return sensorType; }
	virtual std::string getSensorValue() = 0;
	virtual void print() = 0;
};
#endif