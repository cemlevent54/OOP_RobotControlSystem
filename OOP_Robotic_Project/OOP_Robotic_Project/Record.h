#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <string>

/**
 * @file   Record.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the Record class, which provides file handling capabilities.
 *
 * This file contains the definition of the Record class, which includes methods for opening, closing,
 * reading, and writing files, as well as stream operators for file input/output operations.
 */
class Record {
private:
    std::fstream file;  ///< File stream object to handle file operations
    std::string fileName;  ///< The name of the file

public:
    /**
     * @brief Constructor that initializes the Record object.
     *
     * The constructor initializes the object with an empty file name and ensures no file is open.
     */
    Record();

    /**
     * @brief Destructor that closes the file if it is open.
     *
     * If a file is open, it will be closed to release any resources when the object is destroyed.
     */
    ~Record();

    /**
     * @brief Opens the file with the given filename and mode.
     *
     * This function attempts to open the specified file in the provided mode.
     *
     * @param filename The name of the file to open.
     * @param mode The mode in which to open the file (e.g., read, write, append).
     * @return `true` if the file was successfully opened, otherwise `false`.
     */
    bool openFile(const std::string& filename, std::ios::openmode mode);

    /**
     * @brief Closes the open file if it is currently open.
     *
     * This function will close the file if it is open and release associated resources.
     */
    void closeFile();

    /**
     * @brief Sets the filename for the Record object.
     *
     * This function allows setting or changing the filename associated with the Record object.
     *
     * @param filename The new filename to set.
     */
    void setFileName(const std::string& filename);

    /**
     * @brief Reads a line from the file.
     *
     * This function reads a line from the open file and stores it in the provided string.
     *
     * @param line A reference to a string where the read line will be stored.
     * @return `true` if a line was successfully read, otherwise `false`.
     */
    bool readLine(std::string& line);

    /**
     * @brief Writes a line to the file.
     *
     * This function writes the provided line to the open file, followed by a newline character.
     *
     * @param line The line to write to the file.
     */
    void writeLine(const std::string& line);

    /**
     * @brief Stream insertion operator to write file contents to the output stream.
     *
     * This operator allows writing the contents of the file to the output stream.
     *
     * @param os The output stream to write to.
     * @param record The Record object whose file contents will be written to the stream.
     * @return The output stream after the operation.
     */
    friend std::fstream& operator<<(std::fstream& os, const Record& record);

    /**
     * @brief Stream extraction operator to read a line from the file.
     *
     * This operator allows reading a line from the file and storing it in the Record object.
     *
     * @param is The input stream from which the file contents will be read.
     * @param record The Record object where the line will be stored.
     * @return The input stream after the operation.
     */
    friend std::fstream& operator>>(std::fstream& is, Record& record);
};

#endif // RECORD_H

