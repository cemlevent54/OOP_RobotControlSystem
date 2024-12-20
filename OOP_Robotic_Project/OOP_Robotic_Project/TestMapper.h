#ifndef TESTMAPPER_H
#define TESTMAPPER_H

#include "Mapper.h"
#include <string>

/**
 * @file   TestMapper.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the TestMapper class, which provides test methods for the Mapper class.
 *
 * This file declares the TestMapper class that contains static methods for testing the functionality
 * of the Mapper class, including tests for the constructor, updateMap, recordMap, and showMap methods.
 */
class TestMapper {
public:
    /**
     * @brief Runs all the tests for the Mapper class.
     *
     * This static method runs each individual test for the Mapper class and prints the results.
     */
    static void runAllTests();

private:
    /**
     * @brief Tests the constructor of the Mapper class.
     *
     * This test verifies the proper initialization of a Mapper object.
     */
    static void testConstructor();

    /**
     * @brief Tests the updateMap method of the Mapper class.
     *
     * This test ensures that the updateMap method correctly updates the map with lidar data.
     */
    static void testUpdateMap();

    /**
     * @brief Tests the recordMap method of the Mapper class.
     *
     * This test verifies that the recordMap method properly saves the map data to a file.
     */
    static void testRecordMap();

    /**
     * @brief Tests the showMap method of the Mapper class.
     *
     * This test checks if the showMap method correctly outputs the map to the console.
     */
    static void testShowMap();
};

#endif // TESTMAPPER_H
