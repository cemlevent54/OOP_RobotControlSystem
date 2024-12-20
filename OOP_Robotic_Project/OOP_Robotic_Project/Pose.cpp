/**
 * @file   Pose.cpp
 * @author Cem Levent Avcý
 * @date   December, 2024
 * @brief  Implementation of the Pose class.
 *
 * This file contains the implementation of the Pose class, including constructors,
 * getter and setter methods, overloaded operators, and utility methods.
 */

#include "Pose.h"
#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief Default constructor for the Pose class.
 *
 * Initializes the Pose object with default values (x = 0, y = 0, th = 0).
 */
Pose::Pose() : x(0), y(0), th(0) {}

/**
 * @brief Parameterized constructor for the Pose class.
 *
 * Initializes the Pose object with specified values.
 * @param x Initial x-coordinate (in meters).
 * @param y Initial y-coordinate (in meters).
 * @param th Initial orientation (in degrees).
 */
Pose::Pose(double x, double y, double th) : x(x), y(y), th(th) {}

/**
 * @brief Getter for the x-coordinate.
 * @return The x-coordinate of the Pose (in meters).
 */
double Pose::getX() {
    return x;
}

/**
 * @brief Setter for the x-coordinate.
 * @param x New x-coordinate to set (in meters).
 */
void Pose::setX(double x) {
    this->x = x;
}

/**
 * @brief Getter for the y-coordinate.
 * @return The y-coordinate of the Pose (in meters).
 */
double Pose::getY() {
    return y;
}

/**
 * @brief Setter for the y-coordinate.
 * @param y New y-coordinate to set (in meters).
 */
void Pose::setY(double y) {
    this->y = y;
}

/**
 * @brief Getter for the orientation (theta).
 * @return The orientation (theta) of the Pose (in degrees).
 */
double Pose::getTh() {
    return th;
}

/**
 * @brief Setter for the orientation (theta).
 * @param th New orientation to set (in degrees).
 */
void Pose::setTh(double th) {
    this->th = th;
}

/**
 * @brief Equality operator to compare two Pose objects.
 *
 * Compares the x, y, and th values of the two Pose objects.
 * @param other Another Pose object to compare with.
 * @return True if both Pose objects are equal, otherwise false.
 */
bool Pose::operator==(const Pose& other) {
    return (x == other.x && y == other.y && th == other.th);
}

/**
 * @brief Addition operator to add two Pose objects.
 *
 * Adds the x, y, and th values of the two Pose objects.
 * @param other Another Pose object to add.
 * @return A new Pose object with the result of the addition.
 */
Pose Pose::operator+(const Pose& other) {
    return Pose(x + other.x, y + other.y, th + other.th);
}

/**
 * @brief Subtraction operator to subtract one Pose from another.
 *
 * Subtracts the x, y, and th values of the other Pose from this Pose.
 * @param other Another Pose object to subtract.
 * @return A new Pose object with the result of the subtraction.
 */
Pose Pose::operator-(const Pose& other) {
    return Pose(x - other.x, y - other.y, th - other.th);
}

/**
 * @brief Addition and assignment operator to update this Pose by adding a scalar value.
 *
 * Adds the scalar value to the x, y, and th values of this Pose.
 * @param other A scalar value to add to the current Pose.
 * @return A reference to the updated Pose object.
 */
Pose& Pose::operator+=(const double& other) {
    x += other;
    y += other;
    th += other;
    return *this;
}

/**
 * @brief Subtraction and assignment operator to update this Pose by subtracting a scalar value.
 *
 * Subtracts the scalar value from the x, y, and th values of this Pose.
 * @param other A scalar value to subtract from the current Pose.
 * @return A reference to the updated Pose object.
 */
Pose& Pose::operator-=(const double& other) {
    x -= other;
    y -= other;
    th -= other;
    return *this;
}

/**
 * @brief Less-than operator to compare two Pose objects.
 *
 * Compares the x, y, and th values lexicographically.
 * @param other Another Pose object to compare with.
 * @return True if this Pose is less than the other Pose, otherwise false.
 */
bool Pose::operator<(const Pose& other) {
    if (x < other.x) return true;
    if (x == other.x && y < other.y) return true;
    if (x == other.x && y == other.y && th < other.th) return true;
    return false;
}

/**
 * @brief Retrieves the current Pose values.
 *
 * Stores the x, y, and th values in the provided references.
 * @param _x Reference to store the x-coordinate (in meters).
 * @param _y Reference to store the y-coordinate (in meters).
 * @param _th Reference to store the orientation (in degrees).
 */
void Pose::getPose(double& _x, double& _y, double& _th) {
    _x = x;
    _y = y;
    _th = th;
}

/**
 * @brief Sets the Pose values.
 *
 * Updates the x, y, and th values of this Pose.
 * @param _x New x-coordinate (in meters).
 * @param _y New y-coordinate (in meters).
 * @param _th New orientation (in degrees).
 */
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

/**
 * @brief Calculates the Euclidean distance to another Pose.
 *
 * Computes the distance between this Pose and the specified Pose.
 * @param pos Another Pose object to calculate the distance to.
 * @return The distance to the specified Pose (in meters).
 */
double Pose::findDistanceTo(const Pose& pos) {
    double dx = pos.x - x;
    double dy = pos.y - y;
    double distance = sqrt(pow(dx, 2) + pow(dy, 2));
    return distance;
}

/**
 * @brief Calculates the angle between this Pose and another Pose.
 *
 * Computes the angle from this Pose to the specified Pose.
 * @param pos Another Pose object to calculate the angle to.
 * @return The angle to the specified Pose in radians.
 */
double Pose::findAngleTo(const Pose& pos) {
    double dx = pos.x - x;
    double dy = pos.y - y;
    double angle = atan2(dy, dx);
    return angle;
}
