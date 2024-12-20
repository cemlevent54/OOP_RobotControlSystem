#pragma once
/**
 * @file   Pose.h
 * @Author Cem Levent Avcý (cemlevent54@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the Pose class.
 *
 * This file contains the definition of the Pose class, which is used to represent
 * the position and orientation of a robot in a 2D space.
 */
#pragma once

#include <iostream>
#include <string>

 //! Pose class
 /*!
  * @brief Represents the position and orientation of a robot in a 2D space.
  *
  * The Pose class stores the x and y coordinates (in meters) and the orientation
  * (theta, in degrees) of a robot in a 2D space. It provides functionalities for
  * setting and retrieving these values, as well as performing operations such as
  * distance and angle calculations.
  */
class Pose {
private:
    double x;  /*!< x-coordinate of the robot in the 2D space (meters). */
    double y;  /*!< y-coordinate of the robot in the 2D space (meters). */
    double th; /*!< Orientation of the robot in the 2D space (degrees). */

public:
    //! Default constructor
    /*!
     * Initializes the Pose object with default values (x = 0, y = 0, th = 0).
     */
    Pose();

    //! Parameterized constructor
    /*!
     * Initializes the Pose object with specified values.
     * @param x Initial x-coordinate (in meters).
     * @param y Initial y-coordinate (in meters).
     * @param th Initial orientation (in degrees).
     */
    Pose(double x, double y, double th);

    //! Getter for x-coordinate
    /*!
     * @return The x-coordinate of the Pose (in meters).
     */
    double getX();

    //! Setter for x-coordinate
    /*!
     * @param x New x-coordinate to set (in meters).
     */
    void setX(double x);

    //! Getter for y-coordinate
    /*!
     * @return The y-coordinate of the Pose (in meters).
     */
    double getY();

    //! Setter for y-coordinate
    /*!
     * @param y New y-coordinate to set (in meters).
     */
    void setY(double y);

    //! Getter for orientation
    /*!
     * @return The orientation (theta) of the Pose (in degrees).
     */
    double getTh();

    //! Setter for orientation
    /*!
     * @param th New orientation to set (in degrees).
     */
    void setTh(double th);

    /**
     * @brief Equality operator to compare two Pose objects.
     * @param other Another Pose object to compare with.
     * @return True if both Pose objects are equal, otherwise false.
     */
    bool operator==(const Pose& other);

    /**
     * @brief Addition operator to add two Pose objects.
     * @param other Another Pose object to add.
     * @return A new Pose object with the result of the addition.
     */
    Pose operator+(const Pose& other);

    /**
     * @brief Subtraction operator to subtract one Pose from another.
     * @param other Another Pose object to subtract.
     * @return A new Pose object with the result of the subtraction.
     */
    Pose operator-(const Pose& other);

    /**
     * @brief Addition and assignment operator to update this Pose by adding a scalar value.
     * @param other A scalar value to add to the current Pose.
     * @return A reference to the updated Pose object.
     */
    Pose& operator+=(const double& other);

    /**
     * @brief Subtraction and assignment operator to update this Pose by subtracting a scalar value.
     * @param other A scalar value to subtract from the current Pose.
     * @return A reference to the updated Pose object.
     */
    Pose& operator-=(const double& other);

    /**
     * @brief Less-than operator to compare two Pose objects.
     * @param other Another Pose object to compare with.
     * @return True if this Pose is less than the other Pose, otherwise false.
     */
    bool operator<(const Pose& other);

    /**
     * @brief Retrieves the current Pose values.
     * @param _x Reference to store the x-coordinate (in meters).
     * @param _y Reference to store the y-coordinate (in meters).
     * @param _th Reference to store the orientation (in degrees).
     */
    void getPose(double& _x, double& _y, double& _th);

    /**
     * @brief Sets the Pose values.
     * @param _x New x-coordinate (in meters).
     * @param _y New y-coordinate (in meters).
     * @param _th New orientation (in degrees).
     */
    void setPose(double _x, double _y, double _th);

    /**
     * @brief Calculates the Euclidean distance to another Pose.
     * @param pos Another Pose object to calculate the distance to.
     * @return The distance to the specified Pose (in meters).
     */
    double findDistanceTo(const Pose& pos);

    /**
     * @brief Calculates the angle between this Pose and another Pose.
     * @param pos Another Pose object to calculate the angle to.
     * @return The angle to the specified Pose in radians.
     */
    double findAngleTo(const Pose& pos);
};