/**
 * @file   RobotControler.cpp
 * @author Cem Levent Avcý
 * @date   December, 2024
 * @brief  Implementation of the RobotControler class.
 *
 * This file contains the implementation of the RobotControler class, including constructors,
 * methods for controlling the movement of a robot, and utility methods.
 */

#include <iostream>
#include <string>
using namespace std;
#include "Pose.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "RobotControler.h"

/**
 * @brief Default Constructor.
 * Initializes the RobotControler with null values and sets connection status to false.
 */
RobotControler::RobotControler() {
    this->robotAPI = nullptr;
    this->position = new Pose();
    this->connectionStatus = false;
    cout << "RobotControler created using default constructor." << endl;
}

/**
 * @brief Parameterized Constructor.
 * Initializes the RobotControler with provided API.
 * @param api Pointer to the FestoRobotAPI object.
 */

RobotControler::RobotControler(FestoRobotAPI* api) {
    this->robotAPI = api;
    this->connectionStatus = false;
    this->position = new Pose();
    cout << "RobotControler created using one parameterized constructor." << endl;
}


/**
 * @brief Parameterized Constructor.
 * Initializes the RobotControler with provided API and initial pose.
 * @param api Pointer to the FestoRobotAPI object.
 * @param initialPose Pointer to the initial Pose object.
 */
RobotControler::RobotControler(FestoRobotAPI* api, const Pose& initialPose) {
    this->robotAPI = api;
    this->position = new Pose(initialPose); // Gelen pozisyonu kopyalayarak oluþtur
    this->connectionStatus = false;

    if (this->robotAPI != nullptr) {
        this->connectionStatus = connectRobot();
        cout << "RobotControler connected successfully using parameterized constructor." << endl;
    }
    else {
        cout << "Error: robotAPI is null in parameterized constructor." << endl;
    }
}

/**
 * @brief Destructor.
 * Cleans up dynamically allocated memory for the position object.
 */
RobotControler::~RobotControler() {
    delete this->position;
    cout << "RobotControler destroyed and resources cleaned up." << endl;
}

/**
 * @brief This function turns the robot to the left if it is connected.
 */
void RobotControler::turnLeft() {
    if (this->connectionStatus) {
        this->robotAPI->rotate(LEFT);
        cout << "RobotControler turned left." << endl;
    }
    else {
        cout << "Error: RobotControler is not connected." << endl;
    }

}

/**
 * @brief This function turns the robot to the right if it is connected.
 */
void RobotControler::turnRight() {
    if (this->connectionStatus) {
        this->robotAPI->rotate(RIGHT);
        cout << "RobotControler turned right." << endl;
    }
    else {
        cout << "Error: RobotControler is not connected." << endl;
    }

}

/**
 * @brief This function moves the robot forward if it is connected.
 */
void RobotControler::moveForward() {
    if (this->connectionStatus) {
        this->robotAPI->move(FORWARD);
        cout << "RobotControler moved forward." << endl;
    }
    else {
        cout << "Error: RobotControler is not connected." << endl;
    }
}

/**
 * @brief This function moves the robot backward if it is connected.
 */
void RobotControler::moveBackward() {
    if (this->connectionStatus) {
        this->robotAPI->move(BACKWARD);
        cout << "RobotControler moved backward." << endl;
    }

    else {
        cout << "Error: RobotControler is not connected." << endl;
    }
}

/**
 * @brief This function moves the robot to the left if it is connected.
 */
void RobotControler::moveLeft() {
    if (this->connectionStatus) {
        this->robotAPI->move(LEFT);
        cout << "RobotControler moved left." << endl;
    }
    else {
        cout << "Error: RobotControler is not connected." << endl;
    }
}

/**
 * @brief This function moves the robot to the right if it is connected.
 */
void RobotControler::moveRight() {
    if (this->connectionStatus) {
        this->robotAPI->move(RIGHT);
        cout << "RobotControler moved right." << endl;
    }
    else {
        cout << "Error: RobotControler is not connected." << endl;
    }
}

/**
 * @brief This function stops the robot if it is connected.
 */
void RobotControler::stop() {
    if (this->connectionStatus) {
        this->robotAPI->stop();
        cout << "RobotControler stopped." << endl;
    }
}

/**
 * @brief This function returns the current position and orientation of the robot.
 * @return The current position of the robot as a Pose object.
 */
Pose RobotControler::getPose() {
    cout << "Getting the current position of the robot." << endl;
    double x, y, th;
    this->robotAPI->getXYTh(x, y, th);
    this->position->setX(x);
    this->position->setY(y);
    this->position->setTh(th);
    return *this->position;
}

/**
 * @brief This function prints the current status of the robot.
 */
void RobotControler::print() {
    cout << "----------------------------------------------------------------------" << endl;
    cout << "IsOpen: " << this->connectionStatus << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Robot Position: " << this->position->getX() << ", "
        << this->position->getY() << ", "
        << this->position->getTh() << endl;
}

/**
 * @brief This function connects the robot to the API if it is not already connected.
 * @return true if the connection is successful, false otherwise.
 */
bool RobotControler::connectRobot() {
    if (!this->connectionStatus && this->robotAPI != nullptr) {
        this->robotAPI->connect();
        this->connectionStatus = true;
        cout << "RobotControler connected successfully." << endl;
    }


    return this->connectionStatus;
}

/**
 * @brief This function disconnects the robot from the API if it is connected.
 * @return true if the disconnection is successful, false otherwise.
 */
bool RobotControler::disconnectRobot() {
    if (this->connectionStatus && this->robotAPI != nullptr) {
        this->robotAPI->disconnect();
        this->connectionStatus = false;
        cout << "RobotControler disconnected successfully." << endl;
    }
    return this->connectionStatus;
}
