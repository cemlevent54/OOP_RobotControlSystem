#ifndef TESTPOINT_H
#define TESTPOINT_H

#include "Point.h"

/**
 * @file TestPoint.h
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Declaration of the TestPoint class for testing the Point class.
 *
 * This file contains the class declaration for the TestPoint class,
 * which includes test cases to validate the functionality of the Point class.
 */

 //! A class for testing the Point class.
 /*!
  * This class provides methods for running various test cases to validate
  * operations and methods in the Point class.
  */
class TestPoint
{
public:
	//! Runs all test cases.
	/*!
	 * Calls individual test methods to validate the functionality of the Point class.
	 */
	static void runTests();

	//! Tests getter and setter methods of the Point class.
	/*!
	 * Validates the correctness of set and get operations for the Point class.
	 */
	static void testSetAndGet();

	//! Tests the distance calculation method of the Point class.
	/*!
	 * Validates the accuracy of the distance calculation between two points.
	 */
	static void testDistance();

	//! Tests the angle calculation method of the Point class.
	/*!
	 * Validates the correctness of angle calculation between two points.
	 */
	static void testAngle();

	//! Tests the equality operator of the Point class.
	/*!
	 * Verifies the implementation of the equality operator for comparing points.
	 */
	static void testEquality();
};

#endif // TESTPOINT_H
