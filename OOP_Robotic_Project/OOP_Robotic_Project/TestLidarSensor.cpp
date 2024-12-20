/**
 * @file   LidarSensorTest.cpp
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Source file for testing the LidarSensor class.
 *
 * Implements the test methods defined in LidarSensorTest.h to ensure
 * the correct functionality of the LidarSensor class.
 */

#include "TestLidarSensor.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "LidarSensor.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"

 /**
  * @brief Constructor for LidarSensorTest.
  *
  * Initializes the test environment with the real FestoRobotAPI and LidarSensor.
  */
LidarSensorTest::LidarSensorTest() {
    api = new FestoRobotAPI();
    lidarSensor = new LidarSensor(api, 5); // 5 range test deðeri
}

/**
 * @brief Destructor for LidarSensorTest.
 *
 * Cleans up dynamically allocated resources.
 */
LidarSensorTest::~LidarSensorTest() {
    delete lidarSensor;
    delete api;
}

/**
 * @brief Runs all test cases for the LidarSensor class.
 */
void LidarSensorTest::runTests() {
    std::cout << "Running LidarSensor tests..." << std::endl;
    api->connect(); // Robota baðlanma

    testConstructor();
    testUpdate();
    testGetRange();
    testGetMin();
    testGetMax();
    testOperatorOverloading();
    testGetAngle();

    api->disconnect(); // Robottan baðlantýyý kesme
    std::cout << "All tests passed successfully!" << std::endl;
}

/**
 * @brief Tests the constructor of LidarSensor.
 */
void LidarSensorTest::testConstructor() {
    std::cout << "Testing constructor... ";
    for (int i = 0; i < 5; ++i) {
        assert(lidarSensor->getRange(i) == 0.0); // Baþlangýç deðerleri 0.0 olmalý
    }
    std::cout << "Passed!" << std::endl;
}

/**
 * @brief Tests the `update` function of LidarSensor.
 */
void LidarSensorTest::testUpdate() {
    std::cout << "Testing update function... ";
    lidarSensor->update();
    for (int i = 0; i < 5; ++i) {
        assert(lidarSensor->getRange(i) >= 0.0); // Güncellenmiþ deðerler geçerli olmalý
    }
    std::cout << "Passed!" << std::endl;
}

/**
 * @brief Tests the `getRange` function of LidarSensor.
 */
void LidarSensorTest::testGetRange() {
    std::cout << "Testing getRange function... ";
    lidarSensor->update();
    for (int i = 0; i < 5; ++i) {
        assert(lidarSensor->getRange(i) >= 0.0);
    }
    try {
        lidarSensor->getRange(-1); // Geçersiz indeks
        assert(false); // Hata fýrlatýlmalý
    }
    catch (const std::out_of_range&) {}
    try {
        lidarSensor->getRange(5); // Geçersiz indeks
        assert(false);
    }
    catch (const std::out_of_range&) {}

    std::cout << "Passed!" << std::endl;
}

/**
 * @brief Tests the `getMin` function of LidarSensor.
 */
void LidarSensorTest::testGetMin() {
    std::cout << "Testing getMin function... ";
    lidarSensor->update();
    int minIndex;
    double minValue = lidarSensor->getMin(minIndex);
    assert(minValue >= 0.0 && minIndex >= 0 && minIndex < 5);
    std::cout << "Passed!" << std::endl;
}

/**
 * @brief Tests the `getMax` function of LidarSensor.
 */
void LidarSensorTest::testGetMax() {
    std::cout << "Testing getMax function... ";
    lidarSensor->update();
    int maxIndex;
    double maxValue = lidarSensor->getMax(maxIndex);
    assert(maxValue >= 0.0 && maxIndex >= 0 && maxIndex < 5);
    std::cout << "Passed!" << std::endl;
}

/**
 * @brief Tests the overloaded `operator[]` function of LidarSensor.
 */
void LidarSensorTest::testOperatorOverloading() {
    std::cout << "Testing operator[] overloading... ";
    lidarSensor->update();
    for (int i = 0; i < 5; ++i) {
        assert((*lidarSensor)[i] >= 0.0);
    }
    std::cout << "Passed!" << std::endl;
}

/**
 * @brief Tests the `getAngle` function of LidarSensor.
 */
void LidarSensorTest::testGetAngle() {
    std::cout << "Testing getAngle function... ";
    for (int i = 0; i < 5; ++i) {
        double expectedAngle = i * (360.0 / 5);
        assert(lidarSensor->getAngle(i) == expectedAngle);
    }
    assert(lidarSensor->getAngle(-1) == -1.0); // Geçersiz indeks
    assert(lidarSensor->getAngle(5) == -1.0);
    std::cout << "Passed!" << std::endl;
}
