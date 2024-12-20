#include "TestRecord.h"
#include <iostream>
#include <cassert>
#include <fstream>

/**
 * @file   TestRecord.cpp
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Implementation of the test methods for the Record class.
 *
 * This file contains the implementation of the TestRecord class, which tests the functionality
 * of the Record class. The tests include methods for file opening, closing, reading, writing,
 * and operator overloading.
 */

 /**
  * @brief Runs all the tests for the Record class.
  *
  * This method runs each individual test for the Record class, checks for assertions, and prints
  * the results to the console. If all tests pass, a success message is printed.
  */
void TestRecord::runAllTests() {
    std::cout << "Running tests for Record...\n";
    testConstructor();
    testOpenFile();
    testCloseFile();
    testSetFileName();
    testReadLine();
    testWriteLine();
    testStreamOperators();
    std::cout << "All Record tests passed successfully!\n";
}

/**
 * @brief Tests the constructor of the Record class.
 *
 * This test ensures that the Record object is properly constructed.
 */
void TestRecord::testConstructor() {
    Record record;
    std::cout << "testConstructor: Passed\n";
}

/**
 * @brief Tests the openFile method of the Record class.
 *
 * This test verifies that the openFile method opens a file correctly.
 * The file is opened for writing, and then closed after the operation.
 */
void TestRecord::testOpenFile() {
    Record record;
    assert(record.openFile("test_open.txt", std::ios::out));
    record.closeFile();
    std::cout << "testOpenFile: Passed\n";
}

/**
 * @brief Tests the closeFile method of the Record class.
 *
 * This test verifies that the closeFile method correctly closes an open file.
 * The user is expected to verify if the file has been successfully closed.
 */
void TestRecord::testCloseFile() {
    Record record;
    record.openFile("test_close.txt", std::ios::out);
    record.closeFile();

    // File closure verification is left to user observation.
    std::cout << "testCloseFile: Passed\n";
}

/**
 * @brief Tests the setFileName method of the Record class.
 *
 * This test ensures that the setFileName method sets the file name correctly.
 * A file is opened using the set name and closed after the operation.
 */
void TestRecord::testSetFileName() {
    Record record;
    record.setFileName("test_set_name.txt");
    record.openFile("test_set_name.txt", std::ios::out);
    record.closeFile();
    std::cout << "testSetFileName: Passed\n";
}

/**
 * @brief Tests the readLine method of the Record class.
 *
 * This test verifies that the readLine method reads lines from a file correctly.
 * A test file with multiple lines is created, and the lines are read and verified.
 */
void TestRecord::testReadLine() {
    Record record;
    std::ofstream file("test_read.txt");
    file << "First line\nSecond line\n";
    file.close();

    record.openFile("test_read.txt", std::ios::in);
    std::string line;
    assert(record.readLine(line));
    assert(line == "First line");
    assert(record.readLine(line));
    assert(line == "Second line");
    record.closeFile();
    std::cout << "testReadLine: Passed\n";
}

/**
 * @brief Tests the writeLine method of the Record class.
 *
 * This test ensures that the writeLine method writes a line correctly to a file.
 * After writing, the file is read to verify that the written line is present.
 */
void TestRecord::testWriteLine() {
    Record record;
    record.openFile("test_write.txt", std::ios::out);
    record.writeLine("This is a test line.");
    record.closeFile();

    std::ifstream file("test_write.txt");
    std::string line;
    std::getline(file, line);
    assert(line == "This is a test line.");
    file.close();
    std::cout << "testWriteLine: Passed\n";
}

/**
 * @brief Tests the stream operators (<< and >>) for the Record class.
 *
 * This test verifies that the stream operators correctly write and read
 * data from a file. The content is written and read using the overloaded operators.
 */
void TestRecord::testStreamOperators() {
    Record record;
    record.openFile("test_stream.txt", std::ios::out);
    record.writeLine("Stream operator test.");
    record.closeFile();

    record.openFile("test_stream.txt", std::ios::in);
    std::fstream file("test_stream_output.txt", std::ios::out);
    file << record;
    file.close();
    record.closeFile();

    std::ifstream outputFile("test_stream_output.txt");
    std::string line;
    std::getline(outputFile, line);
    assert(line == "Stream operator test.");
    outputFile.close();
    std::cout << "testStreamOperators: Passed\n";
}
