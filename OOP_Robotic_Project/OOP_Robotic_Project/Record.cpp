#include "record.h"
#include <iostream>

/**
 * @file   Record.cpp
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Implementation of the Record class.
 *
 * This file contains the implementation of the Record class, which provides functionality
 * for handling file operations such as opening, closing, reading, and writing files.
 */

 /**
  * @class Record
  * @brief A class that provides file handling operations.
  *
  * The Record class allows opening and closing files, reading and writing lines, and
  * supports file input/output operations using the stream operators.
  */
Record::Record() : fileName("") {}

/**
 * @brief Destructor that closes the file if it is open.
 *
 * The destructor ensures that the file is properly closed when the Record object
 * is destroyed.
 */
Record::~Record() {
    if (file.is_open()) {
        file.close();
    }
}

/**
 * @brief Opens a file with the specified filename and mode.
 *
 * This method attempts to open the file with the provided filename and mode. It
 * returns `true` if the file is successfully opened, and `false` otherwise.
 *
 * @param filename The name of the file to open.
 * @param mode The mode in which to open the file (e.g., read, write, append).
 * @return `true` if the file is successfully opened, otherwise `false`.
 */
bool Record::openFile(const std::string& filename, std::ios::openmode mode) {
    fileName = filename;  // Store the filename
    file.open(fileName, mode);  // Open the file
    return file.is_open();      // Return true if the file was successfully opened
}

/**
 * @brief Closes the currently open file.
 *
 * This method closes the file if it is open. It ensures that resources are released
 * when the file is no longer needed.
 */
void Record::closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

/**
 * @brief Sets the filename for the Record object.
 *
 * This method allows setting or changing the filename for the Record object.
 *
 * @param filename The new filename to be set.
 */
void Record::setFileName(const std::string& filename) {
    fileName = filename;
}

/**
 * @brief Reads a line from the file.
 *
 * This method attempts to read a line from the open file. If successful, it stores
 * the line in the provided string and returns `true`. If the file is not open or
 * reading fails, it returns `false`.
 *
 * @param line A reference to a string where the read line will be stored.
 * @return `true` if the line was successfully read, otherwise `false`.
 */
bool Record::readLine(std::string& line) {
    if (file.is_open() && std::getline(file, line)) {
        return true;  // Line read successfully
    }
    else {
        std::cerr << "File could not be opened or read operation failed!" << std::endl;
        return false;
    }
}

/**
 * @brief Writes a line to the file.
 *
 * This method writes the specified line to the open file, followed by a newline character.
 * If the file is not open, an error message is printed.
 *
 * @param line The line to be written to the file.
 */
void Record::writeLine(const std::string& line) {
    if (file.is_open()) {
        file << line << std::endl;  // Write the line to the file
    }
    else {
        std::cerr << "File could not be opened, write operation failed!" << std::endl;
    }
}

/**
 * @brief Stream insertion operator to write file contents to the output stream.
 *
 * This operator allows writing the contents of the file to the output stream.
 *
 * @param os The output stream to which the file contents will be written.
 * @param record The Record object whose file contents will be written to the stream.
 * @return The output stream with the file contents written to it.
 */
std::fstream& operator<<(std::fstream& os, const Record& record) {
    if (record.file.is_open()) {
        os << record.file.rdbuf();  // Write the file's buffer to the stream
    }
    return os;
}

/**
 * @brief Stream extraction operator to read a line from the file into the Record object.
 *
 * This operator allows reading a line from the file and storing it in the Record object.
 *
 * @param is The input stream from which the file contents will be read.
 * @param record The Record object where the line will be stored.
 * @return The input stream after the operation.
 */
std::fstream& operator>>(std::fstream& is, Record& record) {
    if (record.file.is_open()) {
        std::string line;
        if (record.readLine(line)) {
            // If a line was successfully read, it can be processed further
        }
    }
    return is;
}
