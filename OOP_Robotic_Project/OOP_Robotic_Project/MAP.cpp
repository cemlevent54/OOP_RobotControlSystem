/**
 * @file   Map.cpp
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Implementation of the Map class.
 *
 * This file contains the implementation of the Map class, including constructors,
 * getter and setter methods, utility methods, and operations to manipulate a grid.
 */
#include "Map.h"

 /**
  * @brief Constructor for creating a grid with given dimensions and initializing all cells to 0.
  *
  * @param sizeX The number of columns in the grid.
  * @param sizeY The number of rows in the grid.
  */
Map::Map(int sizeX, int sizeY) : gridSizeX(sizeX), gridSizeY(sizeY) {
    // Resize the grid to the specified dimensions and initialize all cells to 0
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));
}

/**
 * @brief Clears the grid by setting all cells to 0.
 */
void Map::clearMap() {
    // Loop through each row and set all cells to 0
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

/**
 * @brief Marks the corresponding grid cell for the given point as 1.
 *
 * @param point The point whose corresponding grid cell will be marked.
 */
void Map::insertPoint(const Point& point) {
    // Check if the given point is within the bounds of the grid
    if (point.getX() >= 0 && point.getX() < gridSizeX && point.getY() >= 0 && point.getY() < gridSizeY) {
        grid[point.getY()][point.getX()] = 1;  // Mark the point on the grid
    }
}

/**
 * @brief Gets the value of the grid cell at the specified (x, y) coordinates.
 *
 * @param x The x-coordinate of the grid cell.
 * @param y The y-coordinate of the grid cell.
 * @return The value of the grid cell at (x, y), or -1 if the coordinates are out of bounds.
 */
int Map::getGrid(int x, int y) const {
    // Check if the coordinates are valid
    if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
        return grid[y][x];  // Return the value of the grid cell
    }
    return -1;  // Return -1 if the coordinates are out of bounds
}

/**
 * @brief Sets the value of the grid cell at the specified (x, y) coordinates.
 *
 * @param x The x-coordinate of the grid cell.
 * @param y The y-coordinate of the grid cell.
 * @param value The value to set the grid cell to.
 */
void Map::setGrid(int x, int y, int value) {
    // Check if the coordinates are valid
    if (x >= 0 && x < gridSizeX && y >= 0 && y < gridSizeY) {
        grid[y][x] = value;  // Set the value of the grid cell
    }
}

/**
 * @brief Gets the number of columns (X dimension) of the grid.
 *
 * @return The number of columns in the grid.
 */
int Map::getNumberX() const {
    return gridSizeX;
}

/**
 * @brief Gets the number of rows (Y dimension) of the grid.
 *
 * @return The number of rows in the grid.
 */
int Map::getNumberY() const {
    return gridSizeY;
}

/**
 * @brief Increases the grid size by a specified amount in both X and Y directions.
 *
 * @param deltaX The number of columns to add to the grid.
 * @param deltaY The number of rows to add to the grid.
 */
void Map::addGridSize(int deltaX, int deltaY) {
    // Increase the grid dimensions by deltaX and deltaY
    gridSizeX += deltaX;
    gridSizeY += deltaY;

    // Resize the grid and add new rows
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));

    // Resize existing rows to match the new column count
    for (auto& row : grid) {
        row.resize(gridSizeX, 0);
    }
}

/**
 * @brief Sets the grid size to the specified dimensions.
 *
 * @param sizeX The number of columns in the grid.
 * @param sizeY The number of rows in the grid.
 */
void Map::setGridSize(int sizeX, int sizeY) {
    gridSizeX = sizeX;
    gridSizeY = sizeY;
    grid.resize(gridSizeY, std::vector<int>(gridSizeX, 0));  // Resize the grid to the new dimensions
}

/**
 * @brief Prints the dimensions of the grid.
 */
void Map::printInfo() const {
    std::cout << "Grid Size: " << gridSizeX << "x" << gridSizeY << std::endl;
}

/**
 * @brief Prints the contents of the grid, using '.' for empty cells and 'x' for filled cells.
 */
void Map::showMap() const {
    // Loop through each row and print each cell
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell == 0 ? '.' : 'x') << " ";  // Print '.' for empty cells and 'x' for filled cells
        }
        std::cout << std::endl;
    }
}

