/**
 * @file   SafeNavigation.cpp
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Implementation of the SafeNavigation class.
 *
 * This file contains the implementation of the SafeNavigation class, which handles
 * safe movement of the robot using an IR sensor for obstacle detection and a robot
 * controller for controlling the robot's movements.
 */

#include "SafeNavigation.h"
#include <iostream>
#define SAFE_DISTANCE 0.5

 /**
  * @brief Constructor for the SafeNavigation class.
  *
  * Initializes the SafeNavigation object with references to the IR sensor and the robot
  * controller. The initial state is set to STOP.
  * @param sensor A pointer to an IRSensor object used for distance measurements.
  * @param ctrl A pointer to a RobotControler object used to control the robot's movements.
  */
SafeNavigation::SafeNavigation(IRSensor* sensor, RobotControler* ctrl)
    : IR(sensor), controller(ctrl), state(STOP)
{

}

/**
 * @brief Moves the robot forward safely.
 *
 * This method checks the distance measured by the IR sensor at the front. If the
 * distance is greater than 1.0 unit, the robot moves forward. Otherwise, the robot
 * stops to avoid a potential obstacle.
 */
void SafeNavigation::moveForwardSafe()
{
    if (IR->getRange(0) > SAFE_DISTANCE)
    { // Engel mesafesi 0.5m
        controller->moveForward();
        state = MOVING;
        std::cout << "Güvenli þekilde ileri hareket." << std::endl;
    }
    else
    {
        controller->stop();
        state = STOP;
        std::cout << "Engel tespit edildi, duruldu." << std::endl;
    }
}

/**
 * @brief Moves the robot backward safely.
 *
 * This method checks the distance measured by the IR sensor at the rear. If the
 * distance is greater than 1.0 unit, the robot moves backward. Otherwise, the robot
 * stops to avoid a potential obstacle.
 */
void SafeNavigation::moveBackwardSafe()
{
    if (IR->getRange(1) > SAFE_DISTANCE) // Sabit mesafe kontrolü
    {
        controller->moveBackward();
        state = MOVING;
        std::cout << "Güvenli þekilde geri hareket." << std::endl;
    }
    else
    {
        controller->stop();
        state = STOP;
        std::cout << "Engel tespit edildi, duruldu." << std::endl;
    }
}
