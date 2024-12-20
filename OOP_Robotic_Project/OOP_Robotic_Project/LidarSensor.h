/**
 * @file   LidarSensor.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the LidarSensor class.
 *
 * This file contains the definition of the LidarSensor class, which represents
 * a Lidar sensor system responsible for storing, updating, and managing distance
 * measurements from the Lidar. It provides utilities for retrieving specific
 * ranges, finding minimum and maximum ranges, and accessing sensor data via
 * the overloaded subscript operator.
 */

#pragma once

#include "../../oop_project/Project_Packet/FestoRobotAPI.h"

 /**
  * @class LidarSensor
  * @brief Represents a Lidar sensor system for distance measurement.
  *
  * The LidarSensor class interacts with a robot API to retrieve and store Lidar
  * range data. It supports functionality for getting range values, finding the
  * minimum and maximum ranges, and accessing the data via the subscript operator.
  */
class LidarSensor {
private:
    double* ranges;           /*!< Array to dynamically store Lidar range values. */
    int rangeNumber;          /*!< Number of ranges measured by the Lidar sensor. */
    FestoRobotAPI* robotAPI;  /*!< Pointer to the robot API for hardware interaction. */

public:
    //! Constructor
    /*!
     * Initializes the LidarSensor object with the specified robot API and
     * number of range values.
     * @param api A pointer to a FestoRobotAPI object for interacting with the sensor.
     * @param numRanges The number of ranges to be stored in the sensor.
     */
    LidarSensor(FestoRobotAPI* api, int numRanges);

    //! Destructor
    /*!
     * Frees dynamically allocated memory for the ranges array.
     */
    ~LidarSensor();

    //! Updates the Lidar range data
    /*!
     * Retrieves the latest Lidar measurements from the robot API and stores them
     * in the `ranges` array.
     */
    void update();

    //! Retrieves a specific range value
    /*!
     * Provides access to a specific Lidar range measurement by index.
     * @param index The index of the desired range value.
     * @return The range value at the given index.
     * @throw std::out_of_range If the index is not in the valid range [0, rangeNumber-1].
     */
    double getRange(int index) const;

    //! Retrieves the minimum range value
    /*!
     * Finds the minimum distance measured by the Lidar and returns the corresponding
     * range value along with its index.
     * @param index Reference to store the index of the minimum range.
     * @return The minimum range value.
     */
    double getMin(int& index) const;

    //! Retrieves the maximum range value
    /*!
     * Finds the maximum distance measured by the Lidar and returns the corresponding
     * range value along with its index.
     * @param index Reference to store the index of the maximum range.
     * @return The maximum range value.
     */
    double getMax(int& index) const;

    //! Overloaded subscript operator for range access
    /*!
     * Allows access to the Lidar range values using the subscript operator.
     * @param index The index of the desired range value.
     * @return The range value at the given index.
     * @throw std::out_of_range If the index is out of bounds.
     */
    double operator[](int i) const;

    //! Retrieves the angle corresponding to a specific range
    /*!
     * Calculates and returns the angle corresponding to a specific range value.
     * @param index The index of the desired range.
     * @return The angle corresponding to the specified range.
     */
    double getAngle(int i) const;
};
