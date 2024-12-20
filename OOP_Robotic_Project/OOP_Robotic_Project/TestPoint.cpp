#include "TestPoint.h"
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @file TestPoint.cpp
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Implementation of the TestPoint class.
 *
 * This file contains the implementation of the TestPoint class,
 * which includes test cases for the Point class.
 */

 //! Runs all test cases.
 /*!
  * Executes individual test methods to validate the functionality of the Point class.
  */
void TestPoint::runTests()
{
    cout << "Running Point Tests...\n";
    testSetAndGet();
    testDistance();
    testAngle();
    testEquality();
}

//! Tests the Set and Get methods of the Point class.
/*!
 * Validates the setX, setY, getX, and getY methods by setting and retrieving coordinates.
 */
void TestPoint::testSetAndGet()
{
    Point p;
    p.setX(5.0);
    p.setY(3.0);
    cout << "Test Set and Get: X = " << p.getX() << ", Y = " << p.getY() << endl;
}

//! Tests the distance calculation method of the Point class.
/*!
 * Validates the findDistanceTo method by calculating the distance between two points.
 */
void TestPoint::testDistance()
{
    Point p1(0, 0);
    Point p2(3, 4);
    double distance = p1.findDistanceTo(p2);
    cout << "Test Distance: Distance = " << distance << " (Expected: 5.0)" << endl;
}

//! Tests the angle calculation method of the Point class.
/*!
 * Validates the findAngleTo method by calculating the angle between two points.
 */
void TestPoint::testAngle()
{
    Point p1(0, 0);
    Point p2(1, 1);
    double angle = p1.findAngleTo(p2);
    cout << "Test Angle: Angle = " << angle << " radians (Expected: ~0.785)" << endl;
}

//! Tests the equality operator of the Point class.
/*!
 * Validates the operator== method by comparing two points for equality.
 */
void TestPoint::testEquality()
{
    Point p1(1, 1);
    Point p2(1, 1);
    Point p3(2, 2);
    cout << "Test Equality: p1 == p2? " << (p1 == p2 ? "True" : "False") << endl;
    cout << "Test Equality: p1 == p3? " << (p1 == p3 ? "True" : "False") << endl;
}
