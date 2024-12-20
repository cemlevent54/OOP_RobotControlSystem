/**
 * @file   SafeNavigation.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the SafeNavigation class.
 *
 * This class is responsible for managing safe navigation of the robot using
 * data from an infrared (IR) sensor and controlling the robot's movement
 * through a robot controller. It provides functionality to safely move the
 * robot forward and backward based on the sensor readings.
 */

#pragma once 

#include "IRSensor.h"
#include "RobotControler.h"

 /**
  * @enum MOVESTATE
  * @brief Defines the possible movement states of the robot.
  */
enum MOVESTATE { MOVING, STOP }; //!< Movement states of the robot (MOVING or STOP)

/**
 * @class SafeNavigation
 * @brief Manages safe movement of the robot using the IR sensor and robot controller.
 *
 * The SafeNavigation class interacts with the IRSensor to retrieve distance data
 * and with the RobotControler to control the robot's movements. It ensures that
 * the robot moves safely by considering sensor readings during forward and
 * backward motion.
 */
class SafeNavigation {
private:
    IRSensor* IR;                 /*!< Reference to the IR sensor for distance measurements. */
    RobotControler* controller;   /*!< Reference to the RobotControler for controlling the robot. */
    MOVESTATE state;              /*!< Current movement state (MOVING or STOP). */

public:
    /**
     * @brief Constructor for the SafeNavigation class.
     *
     * Initializes the SafeNavigation object with references to the IR sensor
     * and robot controller. Sets the initial state to STOP.
     * @param ir A pointer to an IRSensor object for interacting with the sensor.
     * @param ctrl A pointer to a RobotControler object for controlling the robot.
     */
    SafeNavigation(IRSensor* ir, RobotControler* ctrl);

    /**
     * @brief Destructor for the SafeNavigation class.
     *
     * Frees any dynamically allocated resources (if any). In this case, it doesn't
     * perform any specific action as there are no dynamically allocated resources.
     */

    void moveForwardSafe();

    /**
     * @brief Moves the robot backward safely.
     *
     * Moves the robot backward while ensuring safety by monitoring the IR sensor data.
     * The robot will stop if an obstacle is detected within a predefined range.
     */
    void moveBackwardSafe();
};
