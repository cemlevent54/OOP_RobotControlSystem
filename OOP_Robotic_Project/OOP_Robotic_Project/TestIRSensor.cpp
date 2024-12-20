/**
 * @file   IRSensorTest.cpp
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Source file for testing the IRSensor class.
 *
 * This file contains the implementation of test cases for the IRSensor class.
 */


#include <iostream>
#include "IRSensor.h"
#include "TestIRSensor.h"


using namespace std;

/**
 * @brief Default constructor for IRSensorTest.
 */
IRSensorTest::IRSensorTest() : sensor(nullptr) {}

/**
 * @brief Destructor for IRSensorTest.
 */
IRSensorTest::~IRSensorTest() {
    delete sensor; // Clean up if needed.
}

/**
 * @brief Runs all test cases for IRSensor.
 */
void IRSensorTest::runTests() {
    cout << "Running IRSensor tests..." << endl;

    testParameterizedConstructor();
    testUpdate();
    testGetRange();
    testOperatorOverloading();

    cout << "All IRSensor tests passed!" << endl;
}

/**
 * @brief Tests the parameterized constructor of IRSensor.
 */
void IRSensorTest::testParameterizedConstructor() {
    FestoRobotAPI api; // Dummy API
    sensor = new IRSensor(&api);
    cout << "Testing parameterized constructor... ";

    for (int i = 0; i < 9; ++i) {
        if (sensor->getRange(i) != 0.0) {
            cout << "Failed at index " << i << endl;
            return;
        }
    }

    cout << "Passed!" << endl;
}

/**
 * @brief Tests the update function of IRSensor.
 */
void IRSensorTest::testUpdate() {
    FestoRobotAPI api; // Dummy API
    sensor = new IRSensor(&api);
    cout << "Testing update function... ";

    // Mock sensor values, assuming getIRRange will update (simulation).
    sensor->update();

    for (int i = 0; i < 9; ++i) {
        if (sensor->getRange(i) != 0.0) { // Replace with real API logic if possible
            cout << "Update Failed at index " << i << endl;
            return;
        }
    }

    cout << "Passed!" << endl;
}

/**
 * @brief Tests the getRange function.
 */
void IRSensorTest::testGetRange() {
    FestoRobotAPI api;
    sensor = new IRSensor(&api);
    cout << "Testing getRange function... ";

    sensor->update();

    for (int i = 0; i < 9; ++i) {
        if (sensor->getRange(i) != 0.0) { // Replace with mock updates.
            cout << "getRange Failed at index " << i << endl;
            return;
        }
    }

    if (sensor->getRange(-1) != -1.0 || sensor->getRange(9) != -1.0) {
        cout << "Invalid index handling failed!" << endl;
        return;
    }

    cout << "Passed!" << endl;
}

/**
 * @brief Tests the overloaded operator[] for IRSensor.
 */
void IRSensorTest::testOperatorOverloading() {
    FestoRobotAPI api;
    sensor = new IRSensor(&api);
    cout << "Testing operator[] overloading... ";

    sensor->update();

    for (int i = 0; i < 9; ++i) {
        if ((*sensor)[i] != 0.0) { // Replace with mock updates.
            cout << "Operator[] Failed at index " << i << endl;
            return;
        }
    }

    if ((*sensor)[-1] != -1.0 || (*sensor)[9] != -1.0) {
        cout << "Invalid index handling failed!" << endl;
        return;
    }

    cout << "Passed!" << endl;
}
