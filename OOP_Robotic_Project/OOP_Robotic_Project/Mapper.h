#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"
#include <vector>
#include <string>

/**
 * @file   Mapper.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the Mapper class.
 *
 * This file defines the Mapper class, which is responsible for mapping the robot's
 * environment based on lidar data. It allows updating the map, storing it to a file,
 * and displaying it visually.
 */

 /**
  * @class Mapper
  * @brief A class responsible for mapping the robot's environment using lidar data.
  *
  * The Mapper class uses lidar data (distance and angle) to update the map with the robot's
  * surroundings. It also provides functionality to store the map to a file and display it
  * visually on the console.
  */
class Mapper {
private:
    Map map;  /**< The map that stores the environment grid. */
    int robotX, robotY;  /**< The current position of the robot (x, y coordinates). */

public:
    /**
     * @brief Constructs a Mapper object with specified grid size and initial robot position.
     *
     * The constructor initializes a Map object and sets the robot's initial position.
     *
     * @param gridSizeX The number of columns in the map (default is 0).
     * @param gridSizeY The number of rows in the map (default is 0).
     * @param startX The initial x-coordinate of the robot (default is 0).
     * @param startY The initial y-coordinate of the robot (default is 0).
     */
    Mapper(int gridSizeX, int gridSizeY, int startX = 0, int startY = 0);

    /**
     * @brief Updates the map using lidar data.
     *
     * This method takes lidar data (a vector of distance and angle pairs) and updates
     * the map by marking the corresponding points based on the robot's current position.
     *
     * @param lidarData A vector of lidar data, where each pair consists of distance
     *                  and angle (in degrees).
     */
    void updateMap(const std::vector<std::pair<int, int>>& lidarData);

    /**
     * @brief Records the current map to a file.
     *
     * This method saves the current state of the map (grid values) to a specified file.
     *
     * @param filename The name of the file where the map will be saved.
     */
    void recordMap(const std::string& filename) const;

    /**
     * @brief Displays the map visually on the console.
     *
     * This method prints the current map to the console, where 'x' represents a marked
     * point and '.' represents an empty cell.
     */
    void showMap() const;
};

#endif // MAPPER_H
