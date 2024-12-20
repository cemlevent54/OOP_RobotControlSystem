#pragma once

#include <string>
#include "Robot.h"

#ifndef MENUS_H
#define MENUS_H

/**
 * @class Menus
 * @brief Represents a base class for different menus in the application.
 */
class Menus {
protected:
	std::string connectionErr = "Please connect to robot before this action!";
	Robot* robot;

public:
	/**
 * @brief Constructor for Menus.
 *
 * Initializes the Menus with a pointer to the Robot object.
 *
 * @param _robot Pointer to the Robot object.
 */
	Menus(Robot* _robot) : robot(_robot) {}


	/**
	 * @brief Virtual function to print menu choices.
	 *
	 * This function is virtual and may be overridden in derived classes
	 * to print the available menu choices.
	 */
	virtual void printChoice() { return; }

	/**
 * @brief Virtual function to run the menu.
 *
 * This function is virtual and may be overridden in derived classes
 * to execute the specific functionality of the menu.
 *
 * @return Returns false by default, indicating no specific action to continue.
 */
	virtual bool run() { return false; }
};

#endif