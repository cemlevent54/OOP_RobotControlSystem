/**
 * @file   LidarSensor.cpp
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Implementation file for the LidarSensor class.
 *
 * This file contains the implementation of the LidarSensor class, which represents
 * a Lidar sensor system responsible for storing, updating, and managing distance
 * measurements from the Lidar. It provides utilities for retrieving specific
 * ranges, finding minimum and maximum ranges, and accessing sensor data via
 * the overloaded subscript operator.
 */

#include "LidarSensor.h"
#include <limits>
#include <stdexcept>
#undef max

 /**
  * @brief Constructor for LidarSensor.
  *
  * Initializes the LidarSensor object with the specified robot API and number
  * of range values. Allocates memory for storing range values and initializes them
  * to zero.
  *
  * @param api A pointer to a FestoRobotAPI object for interacting with the sensor.
  * @param numRanges The number of ranges to be stored in the sensor.
  */
LidarSensor::LidarSensor(FestoRobotAPI* api, int numRanges)
    : robotAPI(api), rangeNumber(numRanges) {
    ranges = new double[rangeNumber];
    for (int i = 0; i < rangeNumber; ++i) {
        ranges[i] = 0.0;
    }
}

/**
 * @brief Destructor for LidarSensor.
 *
 * Frees the dynamically allocated memory for the `ranges` array.
 */
LidarSensor::~LidarSensor() {
    delete[] ranges;

}

/**
 * @brief Updates the Lidar range data.
 *
 * Retrieves the latest Lidar measurements from the robot API and stores them
 * in the `ranges` array.
 */
void LidarSensor::update() {
    if (!robotAPI) {
        throw std::runtime_error("robotAPI is not initialized.");
    }

    float tempRange = 0.0f; // Geçici deðiþken tanýmlanýyor

    for (int i = 0; i < rangeNumber; ++i) {
        robotAPI->getLidarRange(&tempRange); // Sensörden veri alýnýyor
        ranges[i] = static_cast<double>(tempRange); // Alýnan veri diziye aktarýlýyor
    }
}


/**
 * @brief Retrieves a specific range value.
 *
 * Provides access to a specific Lidar range measurement by index.
 *
 * @param index The index of the desired range value.
 * @return The range value at the given index.
 * @throw std::out_of_range If the index is not in the valid range [0, rangeNumber-1].
 */
double LidarSensor::getRange(int index) const {
    if (index >= 0 && index < rangeNumber) {
        return ranges[index];
    }
    throw std::out_of_range("Index out of bounds in getRange.");
}

/**
 * @brief Retrieves the minimum range value.
 *
 * Finds the minimum distance measured by the Lidar and returns the corresponding
 * range value along with its index.
 *
 * @param index Reference to store the index of the minimum range.
 * @return The minimum range value.
 */
double LidarSensor::getMin(int& index) const {
    double minVal = INFINITY; // En büyük baþlangýç deðeri
    index = -1;

    for (int i = 0; i < rangeNumber; ++i) {
        if (ranges[i] < minVal) {
            minVal = ranges[i];
            index = i;
        }
    }

    return minVal;
}

/**
 * @brief Retrieves the maximum range value.
 *
 * Finds the maximum distance measured by the Lidar and returns the corresponding
 * range value along with its index.
 *
 * @param index Reference to store the index of the maximum range.
 * @return The maximum range value.
 */
double LidarSensor::getMax(int& index) const {
    double maxVal = std::numeric_limits<double>::lowest();
    index = -1;
    for (int i = 0; i < rangeNumber; ++i) {
        if (ranges[i] > maxVal) {
            maxVal = ranges[i];
            index = i;
        }
    }
    return maxVal;
}

/**
 * @brief Overloaded subscript operator for range access.
 *
 * Allows access to the Lidar range values using the subscript operator.
 *
 * @param i The index of the desired range value.
 * @return The range value at the given index.
 * @throw std::out_of_range If the index is out of bounds.
 */
double LidarSensor::operator[](int i) const {
    return getRange(i);
}

/**
 * @brief Retrieves the angle corresponding to a specific range.
 *
 * Calculates and returns the angle corresponding to a specific range value.
 *
 * @param i The index of the desired range.
 * @return The angle corresponding to the specified range.
 */
double LidarSensor::getAngle(int i) const {
    if (i >= 0 && i < rangeNumber) {
        return i * (360.0 / rangeNumber);
    }
    return -1.0;
}
