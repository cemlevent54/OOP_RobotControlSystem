#ifndef TESTRECORD_H
#define TESTRECORD_H

/**
 * @file   TestRecord.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for testing the Record class.
 *
 * This file contains the declaration of the TestRecord class, which is responsible for testing the functionalities
 * of the Record class, including file operations like opening, closing, reading, and writing to files.
 */

#include "Record.h"

class TestRecord {
public:
    /**
     * @brief Runs all tests for the Record class.
     */
    static void runAllTests();

private:
    /**
     * @brief Tests the constructor of the Record class.
     */
    static void testConstructor();

    /**
     * @brief Tests the openFile method.
     */
    static void testOpenFile();

    /**
     * @brief Tests the closeFile method.
     */
    static void testCloseFile();

    /**
     * @brief Tests the setFileName method.
     */
    static void testSetFileName();

    /**
     * @brief Tests the readLine method.
     */
    static void testReadLine();

    /**
     * @brief Tests the writeLine method.
     */
    static void testWriteLine();

    /**
     * @brief Tests the stream insertion (<<) and extraction (>>) operators for file streams.
     */
    static void testStreamOperators();
};

#endif // TESTRECORD_H
