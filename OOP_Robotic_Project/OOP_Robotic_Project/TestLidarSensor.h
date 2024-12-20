/**
 * @file   LidarSensorTest.h
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Header file for testing the LidarSensor class.
 *
 * Declares the LidarSensorTest class with test methods to ensure the
 * functionality of the LidarSensor class.
 */

#pragma once
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "LidarSensor.h"

 /**
  * @class LidarSensorTest
  * @brief A test class to validate the functionality of LidarSensor.
  *
  * This class contains methods to test various features of the LidarSensor class.
  */
class LidarSensorTest {
private:
    LidarSensor* lidarSensor; /*!< Pointer to a LidarSensor object for testing. */
    FestoRobotAPI* api;       /*!< Pointer to a FestoRobotAPI object for testing. */
    FestoRobotAPI* createDummyAPI();
public:
    /**
     * @brief Constructor for LidarSensorTest.
     *
     * Initializes the test environment with necessary components.
     */
    LidarSensorTest();

    /**
     * @brief Destructor for LidarSensorTest.
     *
     * Cleans up dynamically allocated resources.
     */
    ~LidarSensorTest();

    /**
     * @brief Runs all test cases for the LidarSensor class.
     */
    void runTests();

    /**
     * @brief Tests the constructor of LidarSensor.
     */
    void testConstructor();

    /**
     * @brief Tests the `update` function of LidarSensor.
     */
    void testUpdate();

    /**
     * @brief Tests the `getRange` function of LidarSensor.
     */
    void testGetRange();

    /**
     * @brief Tests the `getMin` function of LidarSensor.
     */
    void testGetMin();

    /**
     * @brief Tests the `getMax` function of LidarSensor.
     */
    void testGetMax();

    /**
     * @brief Tests the overloaded `operator[]` function of LidarSensor.
     */
    void testOperatorOverloading();

    /**
     * @brief Tests the `getAngle` function of LidarSensor.
     */
    void testGetAngle();
};
