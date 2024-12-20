/**
 * @file   IRSensor.cpp
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Implementation of the IRSensor class.
 *
 * This file contains the implementation of the IRSensor class, including constructors,
 * getter and setter methods, overloaded operators, and utility methods for handling infrared sensor data.
 */



#include "IRSensor.h"


 /*
  * @brief Constructor for the IRSensor class.
   *
   * Initializes the IRSensor object and sets the default range values to 0.0.
 */
IRSensor::IRSensor() {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = 0.0;
    }
}


/**
 * @brief Constructor for the IRSensor class.
 *
 * Initializes the IRSensor object and sets the default range values to 0.0.
 * @param api Pointer to the FestoRobotAPI used to retrieve sensor data.
 */
IRSensor::IRSensor(FestoRobotAPI* api) : robotAPI(api) {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = 0.0; ///< Initialize all range values to 0.0
    }
}

/**
 * @brief Updates the range values of the infrared sensors.
 *
 * Fetches the latest range data for each sensor from the robot API
 * and updates the internal array of sensor ranges.
 */
void IRSensor::update() {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = robotAPI->getIRRange(i); /*!< Retrieve range value for sensor i */
    }
}

/**
 * @brief Retrieves the range value of a specific infrared sensor.
 *
 * Provides the distance measured by the specified infrared sensor.
 * @param index Index of the sensor (0 to 8).
 * @return The range value of the specified sensor. Returns -1.0 if the index is invalid.
 */
double IRSensor::getRange(int index) const {
    if (index >= 0 && index < 9) {
        return ranges[index];
    }
    return -1.0; /*!< Return - 1.0 for invalid indices */
}

/**
 * @brief Overloaded subscript operator to access sensor range values.
 *
 * Allows using array-style indexing to retrieve sensor range values.
 * @param index Index of the sensor (0 to 8).
 * @return The range value of the specified sensor. Returns -1.0 if the index is invalid.
 */
double IRSensor::operator[](int i) const {
    return getRange(i);
}
