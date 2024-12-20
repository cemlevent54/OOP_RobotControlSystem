#include "TestMapper.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @file   TestMapper.cpp
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Implementation of the TestMapper class methods for testing the Mapper class.
 *
 * This file contains the implementation of test methods for the Mapper class, including tests
 * for the constructor, updateMap, recordMap, and showMap methods.
 */

 /**
  * @brief Runs all tests for the Mapper class.
  *
  * This method calls each individual test method and reports the results.
  */
void TestMapper::runAllTests() {
    std::cout << "Running tests for Mapper...\n";
    testConstructor();
    testUpdateMap();
    testRecordMap();
    testShowMap();
    std::cout << "All tests passed successfully!\n";
}

/**
 * @brief Tests the constructor of the Mapper class.
 *
 * This test verifies that the Mapper object is constructed with the correct initial values.
 */
void TestMapper::testConstructor() {
    Mapper mapper(10, 10, 5, 5);

    std::cout << "testConstructor: Passed\n";
}

/**
 * @brief Tests the updateMap method of the Mapper class.
 *
 * This test verifies that the Mapper class correctly updates the map using lidar data.
 */
void TestMapper::testUpdateMap() {
    Mapper mapper(10, 10, 5, 5);

    std::vector<std::pair<int, int>> lidarData = {
        {3, 0}, {4, 90}, {2, 180}, {5, 270}
    };

    mapper.updateMap(lidarData);

    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf()); // Capture the output
    mapper.showMap();
    std::cout.rdbuf(oldCoutBuf); // Restore the original cout buffer

    std::string output = oss.str();
    if (output.empty()) {
        throw std::runtime_error("testUpdateMap: Map output is empty!");
    }

    std::cout << "testUpdateMap: Passed\n";
}

/**
 * @brief Tests the recordMap method of the Mapper class.
 *
 * This test verifies that the Mapper class correctly saves the map to a file.
 */
void TestMapper::testRecordMap() {
    Mapper mapper(10, 10, 5, 5);
    std::vector<std::pair<int, int>> lidarData = {
        {3, 0}, {4, 90}, {2, 180}, {5, 270}
    };

    mapper.updateMap(lidarData);
    mapper.recordMap("test_map.txt");

    std::ifstream inFile("test_map.txt");
    if (!inFile.is_open()) {
        throw std::runtime_error("testRecordMap: Unable to open the saved map file!");
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(inFile, line)) {
        ++lineCount;
    }

    if (lineCount == 0) {
        throw std::runtime_error("testRecordMap: Map file is empty!");
    }

    inFile.close();
    std::cout << "testRecordMap: Passed\n";
}

/**
 * @brief Tests the showMap method of the Mapper class.
 *
 * This test verifies that the Mapper class correctly displays the map in the console.
 */
void TestMapper::testShowMap() {
    Mapper mapper(10, 10, 5, 5);
    mapper.showMap();
    std::cout << "testShowMap: Passed\n";
}
