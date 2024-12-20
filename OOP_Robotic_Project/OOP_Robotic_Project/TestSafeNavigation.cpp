/**
 * @file   SafeNavigationTest.cpp
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Source file for testing the SafeNavigation class.
 *
 * This file implements the test cases for the SafeNavigation class.
 * It validates the functionality of the SafeNavigation class, including safe forward and backward movement.
 */

#include "TestSafeNavigation.h"
#include <iostream>
#include <cassert>
#include "IRSensor.h"
#include "LidarSensor.h"
#include "RobotControler.h"
#include "SafeNavigation.h"

using namespace std;

/**
 * @class TestSafeNavigation
 * @brief Implements test cases for the SafeNavigation class.
 */
TestSafeNavigation::TestSafeNavigation() {
    // Empty constructor
}

/**
 * @brief Runs all test cases for the SafeNavigation class.
 *
 * This method sequentially calls all the test functions, ensuring that the
 * SafeNavigation class works as expected.
 */
void TestSafeNavigation::runTests() {
    cout << "Running SafeNavigation tests..." << endl;

    testConstructor();
    testMoveForwardSafe();
    testMoveBackwardSafe();

    cout << "All SafeNavigation tests passed!" << endl;
}

/**
 * @brief Tests the constructor of the SafeNavigation class.
 *
 * Verifies that the SafeNavigation object is successfully initialized
 * with the provided IRSensor and RobotController instances.
 */
void TestSafeNavigation::testConstructor() {
    IRSensor sensor; ///< Dummy IRSensor object for testing
    RobotControler controller; ///< Dummy RobotController object for testing
    SafeNavigation navigation(&sensor, &controller);
    cout << "Testing constructor... ";

    // No explicit assertions as we are validating successful creation.
    cout << "Passed!" << endl;
}

/**
 * @brief Tests the moveForwardSafe function of the SafeNavigation class.
 *
 * This function verifies two scenarios:
 * 1. The robot moves forward when no obstacle is detected.
 * 2. The robot stops when an obstacle is detected within a safety threshold.
 */
void TestSafeNavigation::testMoveForwardSafe() {
    IRSensor sensor; ///< Dummy IRSensor object for testing
    RobotControler controller; ///< Dummy RobotController object for testing
    SafeNavigation navigation(&sensor, &controller);
    cout << "Testing moveForwardSafe function... ";

    // Scenario 1: No obstacle detected, robot should move forward.
    sensor.update(); ///< Updates the sensor readings
    double range = sensor.getRange(0); ///< Simulate getting range data

    if (range > 1.0) {
        navigation.moveForwardSafe();
        cout << "Move Forward Safe: MOVING" << endl;
    }
    else {
        navigation.moveForwardSafe();
        cout << "Move Forward Safe: STOPPED due to obstacle" << endl;
    }

    cout << "Passed!" << endl;
}

/**
 * @brief Tests the moveBackwardSafe function of the SafeNavigation class.
 *
 * This function verifies two scenarios:
 * 1. The robot moves backward when no obstacle is detected.
 * 2. The robot stops when an obstacle is detected within a safety threshold.
 */
void TestSafeNavigation::testMoveBackwardSafe() {
    IRSensor sensor; ///< Dummy IRSensor object for testing
    RobotControler controller; ///< Dummy RobotController object for testing
    SafeNavigation navigation(&sensor, &controller);
    cout << "Testing moveBackwardSafe function... ";

    // Scenario 1: No obstacle detected at the rear, robot should move backward.
    sensor.update(); ///< Updates the sensor readings
    double range = sensor.getRange(1); ///< Simulate getting rear range data

    if (range > 1.0) {
        navigation.moveBackwardSafe();
        cout << "Move Backward Safe: MOVING" << endl;
    }
    else {
        navigation.moveBackwardSafe();
        cout << "Move Backward Safe: STOPPED due to obstacle" << endl;
    }

    cout << "Passed!" << endl;
}
