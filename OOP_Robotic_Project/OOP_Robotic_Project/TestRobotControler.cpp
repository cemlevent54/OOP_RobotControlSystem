/**
 * @file TestRobotControler.cpp
 * @author Cem Levent Avcý
 * @date December, 2024
 *
 * @brief This file implements the methods of the TestRobotControler class, which tests
 * the functionality of the RobotControler class under various conditions.
 */

#include <iostream>
#include "TestRobotControler.h"

using namespace std;

/**
 * @brief Constructs a TestRobotControler object.
 */
TestRobotControler::TestRobotControler() {
}

/**
 * @brief Destroys the TestRobotControler object.
 */
TestRobotControler::~TestRobotControler() {
}

/**
 * @brief Creates a dummy FestoRobotAPI instance for testing.
 *
 * @return A pointer to a new FestoRobotAPI instance.
 */
FestoRobotAPI* TestRobotControler::createDummyAPI() {
    return new FestoRobotAPI();
}

/**
 * @brief Tests movement commands when RobotControler is disconnected.
 *
 * Ensures that movement commands fail gracefully when there is no active connection.
 */
void TestRobotControler::testDisconnectedMovement() {
    cout << "\n--- Test: Movements While Disconnected ---" << endl;

    FestoRobotAPI* robotino = createDummyAPI();
    RobotControler rc(robotino);

    cout << "Attempting to move while disconnected:" << endl;
    rc.moveForward();
    Sleep(3000);
    rc.turnLeft();
    Sleep(3000);
    rc.stop();

    delete robotino;
}

/**
 * @brief Tests movement commands when RobotControler is connected.
 *
 * Verifies that all movement commands work correctly when the robot is connected.
 */
void TestRobotControler::testConnectedMovement() {
    cout << "\n--- Test: Movements While Connected ---" << endl;

    FestoRobotAPI* robotino = createDummyAPI();
    RobotControler rc(robotino);

    cout << "Connecting the robot..." << endl;
    rc.connectRobot();

    cout << "Attempting to move while connected:" << endl;
    rc.moveForward();
    Sleep(3000);
    rc.turnLeft();
    Sleep(3000);
    rc.stop();

    cout << "Disconnecting the robot..." << endl;
    rc.disconnectRobot();

    delete robotino;
}

/**
 * @brief Tests movement commands after the RobotControler is disconnected.
 *
 * Ensures that commands issued after disconnection do not cause unexpected behavior.
 */
void TestRobotControler::testMovementAfterDisconnection() {
    cout << "\n--- Test: Movements After Disconnection ---" << endl;

    FestoRobotAPI* robotino = createDummyAPI();
    RobotControler rc(robotino);

    cout << "Connecting the robot..." << endl;
    rc.connectRobot();

    cout << "Disconnecting the robot..." << endl;
    rc.disconnectRobot();

    cout << "Attempting to move after disconnecting:" << endl;
    rc.moveForward();
    Sleep(3000);
    rc.turnRight();
    Sleep(3000);
    rc.stop();

    delete robotino;
}

/**
 * @brief Tests multiple connection and disconnection attempts.
 *
 * Verifies that repeated connection and disconnection calls are handled correctly
 * without errors or redundancy.
 */
void TestRobotControler::testMultipleConnections() {
    cout << "\n--- Test: Multiple Connection Attempts ---" << endl;

    FestoRobotAPI* robotino = createDummyAPI();
    RobotControler rc(robotino);

    cout << "First connection attempt:" << endl;
    rc.connectRobot();

    cout << "Second connection attempt (should have no effect):" << endl;
    rc.connectRobot();

    cout << "Disconnecting the robot..." << endl;
    rc.disconnectRobot();

    cout << "Another disconnection attempt (should have no effect):" << endl;
    rc.disconnectRobot();

    delete robotino;
}

/**
 * @brief Tests stopping the robot while it is moving.
 *
 * Ensures that the stop command interrupts active movement and halts the robot.
 */
void TestRobotControler::testStopWhileMoving() {
    cout << "\n--- Test: Stop Command While Moving ---" << endl;

    FestoRobotAPI* robotino = createDummyAPI();
    RobotControler rc(robotino);

    cout << "Connecting the robot..." << endl;
    rc.connectRobot();

    cout << "Robot moving forward..." << endl;
    rc.moveForward();
    Sleep(3000);

    cout << "Robot issuing stop command while moving..." << endl;
    rc.stop();

    cout << "Robot turning left..." << endl;
    rc.turnLeft();
    Sleep(3000);

    cout << "Stopping the robot again..." << endl;
    rc.stop();

    rc.disconnectRobot();

    delete robotino;
}

/**
 * @brief Runs all available test scenarios for RobotControler.
 *
 * This function sequentially calls all the test functions in the class to validate
 * the behavior of the RobotControler class under various conditions.
 */
void TestRobotControler::runAllTests() {
    cout << "\n================ Starting RobotControler Tests ================\n" << endl;

    testDisconnectedMovement();
    testConnectedMovement();
    testMovementAfterDisconnection();
    testMultipleConnections();
    testStopWhileMoving();

    cout << "\n================ Ending RobotControler Tests ================\n" << endl;
}

