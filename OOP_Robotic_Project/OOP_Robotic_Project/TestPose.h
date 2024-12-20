#pragma once

/**
 * @file TestPose.h
 * @author Cem Levent Avcý
 * @date December, 2024
 *
 * @brief Declaration of the TestPose class for testing the Pose class.
 *
 * This file contains the class declaration for testing the Pose class,
 * including its constructors, getter and setter methods, operator overloads,
 * and utility functions.
 */

#include "Pose.h"

 /**
  * @class TestPose
  * @brief A class to test the functionality of the Pose class.
  *
  * This class includes various test cases for constructors, getters, setters,
  * overloaded operators, and utility functions such as distance and angle calculations.
  */
class TestPose {
public:
    /**
     * @brief Default constructor for TestPose.
     */
    TestPose();

    /**
     * @brief Destructor for TestPose.
     */
    ~TestPose();

    /**
     * @brief Runs all test cases for the Pose class.
     */
    void runAllTests();

private:
    /**
     * @brief Tests constructors of the Pose class.
     */
    void testConstructors();

    /**
     * @brief Tests the getter and setter methods of the Pose class.
     */
    void testGettersAndSetters();

    /**
     * @brief Tests the equality and relational operators of the Pose class.
     */
    void testOperators();

    /**
     * @brief Tests the utility methods (distance and angle calculations).
     */
    void testUtilityFunctions();
};
