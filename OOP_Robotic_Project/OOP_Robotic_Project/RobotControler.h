#pragma once
/**
 * @file   RobotControler.h
 * @Author Cem Levent Avcý (cemlevent54@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the RobotControler class.
 *
 * This file contains the definition of the RobotControler class, which is used to control
 * the movement of a robot in a 2D space.
 */

#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Pose.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"

//! RobotControler class
/*!
 * @brief Controls the movement of a robot in a 2D space.
 *
 * The RobotControler class provides functionalities for controlling the movement of a robot
 * in a 2D space. It uses the FestoRobotAPI class to communicate with the robot and send commands
 * for moving the robot in different directions.
 */
class RobotControler {
private:
    FestoRobotAPI* robotAPI; /*!< Pointer to the FestoRobotAPI object used to control the robot. */
    Pose* position; /*!< Pointer to the Pose object representing the current position and orientation of the robot. */
    bool connectionStatus; /*!< Flag indicating whether the robot is connected or not. */

public:
    //! Default Constructor
    /*!
    * Initializes the RobotControler with default values.
    */
    RobotControler();

    //! One Parametrized Constructor
    /*!
    * Initializes the RobotControler with provided FestoRobotAPI object.
    */
    RobotControler(FestoRobotAPI* api);

    //! Parameterized Constructor
    /*!
    * Initializes the RobotControler with provided FestoRobotAPI and Pose objects.
    * @param api Pointer to the FestoRobotAPI object.
    * @param initialPose Pointer to the initial Pose object.
    */
    RobotControler(FestoRobotAPI* api, const Pose& initialPose);

    //! Destructor
    /*!
    * Cleans up dynamically allocated memory.
    */
    ~RobotControler();

    //! turnLeft function 
    /*!
    * This function turns the robot to the left.
    * @param void
    */
    void turnLeft();
    //! turnRight function
    /*!
    * This function turns the robot to the right.
    * @param void
    */
    void turnRight();
    //! moveForward function
    /*!
    * This function moves the robot forward.
    * @param void
    */
    void moveForward();
    //! moveBackward function
    /*!
    * This function moves the robot backward.
    * @param void
    */
    void moveBackward();
    //! moveLeft function
    /*!
    * This function moves the robot to the left.
    */
    void moveLeft();
    //! moveRight function
    /*!
    * This function moves the robot to the right.
    */
    void moveRight();
    //! stop function
    /*!
    * This function stops the robot.
    * @param void
    */
    void stop();
    //! getPose function
    /*!
    * This function returns the current position and orientation of the robot.
    * @param void
    * @return the current position of the robot as a Pose object.
    */
    Pose getPose();
    //! print function
    /*!
    * This function prints the current status of the robot.
    * @param void
    */
    void print();
    //! connectRobot function
    /*!
    * This function connects the robot to the controller if it is not already connected.
    * @param void
    * @return true if the connection is successful, false otherwise.
    */
    bool connectRobot();
    //! disconnectRobot function
    /*!
    * This function disconnects the robot from the controller if it is connected.
    * @param void
    * @return true if the disconnection is successful, false otherwise.
    */
    bool disconnectRobot();
};
#pragma once
