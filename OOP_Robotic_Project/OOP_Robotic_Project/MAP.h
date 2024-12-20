#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "Point.h"

/**
 * @file   Map.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the Map class.
 *
 * This file defines the Map class, which represents a grid-based map.
 * The Map class provides functionality to create, modify, and display a 2D grid.
 * It includes methods to clear the map, insert points, adjust grid size, and print grid contents.
 */

 /**
  * @struct Point
  * @brief A structure to represent a point with (x, y) coordinates.
  *
  * The Point structure is used to store the coordinates of a point on the grid.
  */
  //struct Point {
  //    int x, y; /**< The x and y coordinates of the point. */
  //
  //    /**
  //     * @brief Constructs a Point object with given coordinates.
  //     *
  //     * If no coordinates are provided, both x and y default to 0.
  //     *
  //     * @param x The x-coordinate of the point (default is 0).
  //     * @param y The y-coordinate of the point (default is 0).
  //     */
  //    Point(int x = 0, int y = 0) : x(x), y(y) {}
  //};

  /**
   * @class Map
   * @brief A class to represent a grid-based map.
   *
   * The Map class provides functionality to create, modify, and display a 2D grid.
   * It supports operations to clear the map, insert points, adjust grid size, and print grid contents.
   */
class Map {
private:
    std::vector<std::vector<int>> grid;  /**< 2D vector to store the map data. */
    int gridSizeX, gridSizeY;            /**< The size of the grid (X and Y dimensions). */

public:
    /**
     * @brief Constructs a Map object with specified grid dimensions.
     *
     * Initializes the grid with the given dimensions and sets all cells to 0.
     * Default grid size is 10x10 if no dimensions are provided.
     *
     * @param sizeX The number of columns in the grid (default is 10).
     * @param sizeY The number of rows in the grid (default is 10).
     */
    Map(int sizeX = 10, int sizeY = 10);

    /**
     * @brief Clears the map by setting all grid cells to 0.
     */
    void clearMap();

    /**
     * @brief Marks the grid cell corresponding to the given point with a 1.
     *
     * @param point The point whose corresponding grid cell will be marked as 1.
     */
    void insertPoint(const Point& point);

    /**
     * @brief Returns the value at the specified grid cell.
     *
     * @param x The x-coordinate of the grid cell.
     * @param y The y-coordinate of the grid cell.
     * @return The value of the grid cell at (x, y), or -1 if the coordinates are out of bounds.
     */
    int getGrid(int x, int y) const;

    /**
     * @brief Sets the value of the grid cell at the specified (x, y) coordinates.
     *
     * @param x The x-coordinate of the grid cell.
     * @param y The y-coordinate of the grid cell.
     * @param value The value to set the grid cell to.
     */
    void setGrid(int x, int y, int value);

    /**
     * @brief Returns the number of columns (X dimension) in the grid.
     *
     * @return The number of columns in the grid.
     */
    int getNumberX() const;

    /**
     * @brief Returns the number of rows (Y dimension) in the grid.
     *
     * @return The number of rows in the grid.
     */
    int getNumberY() const;

    /**
     * @brief Increases the size of the grid by a specified amount in both X and Y directions.
     *
     * @param deltaX The number of columns to add to the grid.
     * @param deltaY The number of rows to add to the grid.
     */
    void addGridSize(int deltaX, int deltaY);

    /**
     * @brief Sets the grid size to the specified dimensions.
     *
     * @param sizeX The number of columns in the grid.
     * @param sizeY The number of rows in the grid.
     */
    void setGridSize(int sizeX, int sizeY);

    /**
     * @brief Prints the dimensions of the grid.
     */
    void printInfo() const;

    /**
     * @brief Prints the contents of the grid visually, using '.' for empty cells and 'x' for filled cells.
     */
    void showMap() const;
};

#endif // MAP_H
