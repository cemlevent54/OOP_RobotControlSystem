/**
 * @file   IRSensorTest.h
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Header file for testing the IRSensor class.
 *
 * Declares the IRSensorTest class and its test cases to ensure IRSensor functionality works as intended.
 */

#pragma once

#include "IRSensor.h"

 /**
  * @class IRSensorTest
  * @brief A test class to validate the functionality of the IRSensor class.
  *
  * This class contains test cases for the parameterized constructor, update function,
  * getRange function, and overloaded operator[] of the IRSensor class.
  */
class IRSensorTest {
private:
    IRSensor* sensor; /*!< Pointer to the IRSensor object for testing. */

public:
    //! Default constructor.
    IRSensorTest();

    //! Destructor.
    ~IRSensorTest();

    /**
     * @brief Runs all test cases for the IRSensor class.
     */
    void runTests();

    /**
     * @brief Tests the parameterized constructor of IRSensor.
     */
    void testParameterizedConstructor();

    /**
     * @brief Tests the `update` function of IRSensor.
     */
    void testUpdate();

    /**
     * @brief Tests the `getRange` function of IRSensor.
     */
    void testGetRange();

    /**
     * @brief Tests the overloaded `operator[]` function of IRSensor.
     */
    void testOperatorOverloading();
};
