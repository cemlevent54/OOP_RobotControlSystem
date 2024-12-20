#pragma once

/**
 * @file TestRobotControler.h
 * @author Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the TestRobotControler class for testing RobotControler behavior.
 *
 * This file contains the class declaration for testing the RobotControler class,
 * including connected and disconnected states, movement tests, and edge case scenarios.
 */

#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "RobotControler.h"

 /**
  * @class TestRobotControler
  * @brief A class to test the behavior of the RobotControler class.
  *
  * This class includes various test scenarios to validate the functionality
  * of the RobotControler class. It tests movement commands under different conditions
  * such as connected and disconnected states, stopping while moving, and multiple
  * connection attempts.
  */
class TestRobotControler {
public:
    /**
     * @brief Constructs a TestRobotControler object.
     */
    TestRobotControler();

    /**
     * @brief Destroys the TestRobotControler object and cleans up any resources.
     */
    ~TestRobotControler();

    /**
     * @brief Tests movement commands when the robot is disconnected.
     *
     * Validates that the RobotControler properly blocks movement commands
     * when no connection is established.
     */
    void testDisconnectedMovement();

    /**
     * @brief Tests movement commands when the robot is connected.
     *
     * Ensures that all movement commands (forward, backward, left, right, etc.)
     * work correctly when the connection is active.
     */
    void testConnectedMovement();

    /**
     * @brief Tests movement commands after the robot is disconnected.
     *
     * Checks that movement commands fail gracefully after the connection has been terminated.
     */
    void testMovementAfterDisconnection();

    /**
     * @brief Tests multiple connection and disconnection attempts.
     *
     * Verifies that the RobotControler handles repeated connection and disconnection
     * commands without errors or unexpected behavior.
     */
    void testMultipleConnections();

    /**
     * @brief Tests stopping the robot while it is moving.
     *
     * Ensures that the "stop" command interrupts movement commands and stops the robot successfully.
     */
    void testStopWhileMoving();

    /**
     * @brief Runs all available test scenarios for RobotControler.
     *
     * This function sequentially calls all the test functions to validate
     * the behavior of the RobotControler class.
     */
    void runAllTests();

private:
    /**
     * @brief Creates a dummy instance of FestoRobotAPI.
     *
     * This function initializes and returns a pointer to a FestoRobotAPI object
     * to simulate the robot API during tests.
     *
     * @return A pointer to a FestoRobotAPI instance.
     */
    FestoRobotAPI* createDummyAPI();
};
