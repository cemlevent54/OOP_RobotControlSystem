/**
 * @file   TestSafeNavigation.h
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Header file for testing the SafeNavigation class.
 *
 * Contains the TestSafeNavigation class for testing SafeNavigation functionality.
 */

#pragma once

#include "SafeNavigation.h"

 /**
  * @class TestSafeNavigation
  * @brief Class for testing the functionality of the SafeNavigation class.
  *
  * This class contains test functions for verifying the behavior of the
  * SafeNavigation class, including constructor and movement functions.
  */
class TestSafeNavigation {
public:
    /**
     * @brief Default constructor for TestSafeNavigation.
     */
    TestSafeNavigation();

    /**
     * @brief Runs all test cases for the SafeNavigation class.
     *
     * Calls each individual test function in sequence.
     */
    void runTests();

private:
    /**
     * @brief Tests the constructor of SafeNavigation.
     *
     * Ensures that the SafeNavigation object initializes correctly.
     */
    void testConstructor();

    /**
     * @brief Tests the `moveForwardSafe` function of SafeNavigation.
     *
     * Verifies that the robot moves forward and stops when an obstacle
     * is within the safety threshold.
     */
    void testMoveForwardSafe();

    /**
     * @brief Tests the `moveBackwardSafe` function of SafeNavigation.
     *
     * Ensures the robot moves backward safely and stops when an obstacle
     * is detected within the safety threshold.
     */
    void testMoveBackwardSafe();
};
