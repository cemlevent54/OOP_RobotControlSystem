/**
 * @file   IRSensor.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the IRSensor class.
 *
 * This class represents an Infrared (IR) sensor system responsible for storing,
 * updating, and managing sensor range data. It provides utilities to access and
 * retrieve distance values and allows index-based access to ranges using operator overloading.
 */

#pragma once

#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include <stdexcept>
using namespace std;

/**
 * @class IRSensor
 * @brief Handles the operations and data management for an IR sensor system.
 */
class IRSensor {
private:
    FestoRobotAPI* robotAPI; /*!< Pointer to the robot API for interfacing with hardware.*/
    double ranges[9];        /*!< Array to store distance values from the sensor.*/

public:
    /**
     * @brief Default constructor.
     * Initializes the ranges array and sets `robotAPI` to nullptr.
     */
    IRSensor();

    /**
     * @brief Parameterized constructor.
     * @param api A pointer to a FestoRobotAPI object for sensor data updates.
     */
    IRSensor(FestoRobotAPI* api);

    /**
     * @brief Updates the range data from the connected IR sensor system.
     * This function interacts with the robot API to refresh the sensor readings.
     */
    void update();

    /**
     * @brief Retrieves the range value at a specific index.
     * @param index The index of the desired range value (0-8).
     * @return The range value at the given index.
     * @throw std::out_of_range If the index is outside the valid range.
     */
    double getRange(int index) const;

    /**
     * @brief Overloaded subscript operator for range access.
     * Provides index-based access to sensor range values.
     * @param index The index of the desired range value (0-8).
     * @return The range value at the given index.
     * @throw std::out_of_range If the index is outside the valid range.
     */
    double operator[](int i) const;
};

