#include "mapper.h"
#include <fstream>
#include <iostream>
#include <cmath>  

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * @file   Mapper.cpp
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Implementation of the Mapper class.
 *
 * This file contains the implementation of the Mapper class, which is responsible
 * for mapping and updating the robot's environment using lidar data.
 */

 /**
  * @class Mapper
  * @brief A class that maps the environment based on lidar data.
  *
  * The Mapper class is used to update a map with lidar data and to display or store
  * the generated map. It stores the robot's position and uses lidar data to insert
  * points on the map.
  */
Mapper::Mapper(int gridSizeX, int gridSizeY, int startX, int startY)
    : map(gridSizeX, gridSizeY), robotX(startX), robotY(startY) {

}

/**
 * @brief Updates the map based on lidar data.
 *
 * This method uses the lidar data (distance and angle) to calculate the corresponding
 * (x, y) coordinates in the world frame and updates the map by inserting the points
 * into the map.
 *
 * @param lidarData A vector of lidar data points, where each point is a pair of distance
 *                  and angle in degrees.
 */
void Mapper::updateMap(const std::vector<std::pair<int, int>>& lidarData) {
    for (const auto& data : lidarData) {
        int distance = data.first;  /**< Distance from the robot to the obstacle. */
        int angle = data.second;    /**< Angle of the lidar reading in degrees. */

        int x = robotX + distance * cos(angle * M_PI / 180);  /**< X coordinate calculation. */
        int y = robotY + distance * sin(angle * M_PI / 180);  /**< Y coordinate calculation. */

        if (x >= 0 && x < map.getNumberX() && y >= 0 && y < map.getNumberY()) {
            map.insertPoint(Point(x, y));  /**< If valid, mark the point on the map. */
        }
    }
}

/**
 * @brief Records the current map to a file.
 *
 * This method saves the current state of the map (grid values) to a specified file.
 *
 * @param filename The name of the file where the map will be saved.
 */
void Mapper::recordMap(const std::string& filename) const {
    std::ofstream outFile(filename);  /**< Open the file for writing. */

    if (outFile.is_open()) {
        for (int i = 0; i < map.getNumberY(); ++i) {
            for (int j = 0; j < map.getNumberX(); ++j) {
                outFile << map.getGrid(j, i) << " ";  /**< Write grid values to the file. */
            }
            outFile << "\n";  /**< Newline for the next row. */
        }
        outFile.close();  /**< Close the file after writing. */
    }
    else {
        std::cerr << "Error while file is opening" << std::endl;  /**< Error message if file fails to open. */
    }
}

/**
 * @brief Displays the map visually on the console.
 *
 * This method prints the current map to the console, using 'x' for marked cells
 * and '.' for empty cells.
 */
void Mapper::showMap() const {
    for (int i = 0; i < map.getNumberY(); ++i) {
        for (int j = 0; j < map.getNumberX(); ++j) {
            std::cout << (map.getGrid(j, i) == 1 ? "x" : ".") << " ";  /**< Display map cell. */
        }
        std::cout << std::endl;  /**< Move to the next line after a row of the map is printed. */
    }
}
