/**
 * @file TestPose.cpp
 * @author Cem Levent Avcý
 * @date December, 2024
 *
 * @brief Implementation of the TestPose class for testing the Pose class.
 */

#include "TestPose.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Default constructor for the TestPose class.
 */
TestPose::TestPose() {
    cout << "[TestPose] Test class created." << endl;
}

/**
 * @brief Destructor for the TestPose class.
 */
TestPose::~TestPose() {
    cout << "[TestPose] Test class destroyed." << endl;
}

/**
 * @brief Runs all test cases for the Pose class.
 */
void TestPose::runAllTests() {
    cout << "\n================ Starting Pose Tests ================\n" << endl;

    testConstructors();
    testGettersAndSetters();
    testOperators();
    testUtilityFunctions();

    cout << "\n================ Ending Pose Tests ================\n" << endl;
}

/**
 * @brief Tests constructors of the Pose class.
 */
void TestPose::testConstructors() {
    cout << "--- Test: Constructors ---" << endl;

    Pose p1; // Default constructor
    cout << "Default Constructor: Pose(0, 0, 0)" << endl;

    Pose p2(1.5, 2.5, 45.0); // Parameterized constructor
    cout << "Parameterized Constructor: Pose(1.5, 2.5, 45.0)" << endl;
}

/**
 * @brief Tests the getter and setter methods of the Pose class.
 */
void TestPose::testGettersAndSetters() {
    cout << "\n--- Test: Getters and Setters ---" << endl;

    Pose p;
    p.setX(5.0);
    p.setY(10.0);
    p.setTh(90.0);

    cout << "Set X = 5.0, Y = 10.0, Th = 90.0" << endl;
    cout << "Get X: " << p.getX() << ", Get Y: " << p.getY()
        << ", Get Th: " << p.getTh() << endl;
}

/**
 * @brief Tests the equality and relational operators of the Pose class.
 */
void TestPose::testOperators() {
    cout << "\n--- Test: Operators ---" << endl;

    Pose p1(1.0, 2.0, 30.0);
    Pose p2(1.0, 2.0, 30.0);
    Pose p3(3.0, 4.0, 60.0);

    // Equality operator
    if (p1 == p2) {
        cout << "Equality Operator: p1 == p2 (True)" << endl;
    }

    // Addition operator
    Pose p4 = p1 + p3;
    cout << "Addition Operator: p1 + p3 -> Pose(" << p4.getX() << ", "
        << p4.getY() << ", " << p4.getTh() << ")" << endl;

    // Subtraction operator
    Pose p5 = p3 - p1;
    cout << "Subtraction Operator: p3 - p1 -> Pose(" << p5.getX() << ", "
        << p5.getY() << ", " << p5.getTh() << ")" << endl;

    // Less-than operator
    if (p1 < p3) {
        cout << "Less-Than Operator: p1 < p3 (True)" << endl;
    }
}

/**
 * @brief Tests the utility methods (distance and angle calculations).
 */
void TestPose::testUtilityFunctions() {
    cout << "\n--- Test: Utility Functions ---" << endl;

    Pose p1(0.0, 0.0, 0.0);
    Pose p2(3.0, 4.0, 0.0);

    // Distance calculation
    double distance = p1.findDistanceTo(p2);
    cout << "Distance from Pose(0, 0, 0) to Pose(3, 4, 0): " << distance << " meters" << endl;

    // Angle calculation
    double angle = p1.findAngleTo(p2);
    cout << "Angle from Pose(0, 0, 0) to Pose(3, 4, 0): " << angle << " radians" << endl;
}


