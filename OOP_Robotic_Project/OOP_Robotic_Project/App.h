// 152120211071 - Cem Levent Avcý

#include <string>
#include "Authentication.h"
#include "ConnectionMenu.h"
#include "SensorMenu.h"
#include "MotionMenu.h"

#ifndef APP_H
#define APP_H

/**
 * @class App
 * @brief Represents the main application that manages authentication and menus.
 */
class App {
private:
	std::string mainMenu = "1. Connection\n"
		"2. Motion\n"
		"3. Sensor\n"
		"4. Quit\n";
	Authentication authentication;

	ConnectionMenu* connectionMenu;
	SensorMenu* sensorMenu;
	MotionMenu* motionMenu;

	Robot* robot;



public:
	/**
   * @brief Default constructor for the App class.
   *
   * Initializes the App object by creating instances of Authentication,
   * Robot, ConnectionMenu, SensorMenu, and MotionMenu.
   */
	App() : authentication() {
		robot = new Robot();
		connectionMenu = new ConnectionMenu(robot);
		sensorMenu = new SensorMenu(robot);
		motionMenu = new MotionMenu(robot);
	}

	/**
 * @brief Runs the main application.
 *
 * This function is responsible for executing the main functionality of the application,
 * including authentication and navigating through different menus.
 */
	void run();
};
#endif