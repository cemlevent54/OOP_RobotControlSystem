#ifndef TESTMAP_H
#define TESTMAP_H

#include "Map.h"

/**
 * @file   TestMap.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the TestMap class, which contains methods to test the Map class.
 *
 * This file contains the definition of the TestMap class, including methods for running tests
 * on the Map class, covering various functionalities like constructors, methods, and grid resizing.
 */
class TestMap {
public:
    /**
     * @brief Runs all the tests for the Map class.
     *
     * This method runs a series of tests to ensure that the Map class is functioning as expected.
     */
    static void runAllTests();

private:
    /**
     * @brief Tests the constructor of the Map class.
     */
    static void testConstructor();

    /**
     * @brief Tests the clearMap method of the Map class.
     */
    static void testClearMap();

    /**
     * @brief Tests the insertPoint method of the Map class.
     */
    static void testInsertPoint();

    /**
     * @brief Tests the getGrid and setGrid methods of the Map class.
     */
    static void testGetAndSetGrid();

    /**
     * @brief Tests the addGridSize method of the Map class to resize the grid.
     */
    static void testResizeGrid();

    /**
     * @brief Tests the showMap method of the Map class.
     */
    static void testShowMap();
};

#endif // TESTMAP_H
