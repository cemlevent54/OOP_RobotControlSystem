#include <string>
#include "Menus.h"
//#include "SensorInterface.h"

#ifndef MOTIONMENU_H
#define MOTIONMENU_H

/**
 * @class MotionMenu
 * @brief Represents the menu for managing robot motion.
 */
class MotionMenu : public Menus {
private:
	string choice = "1. Move Robot\n"
		"2. Safe Move Robot\n"
		"3. Turn Left\n"
		"4. Turn Right\n"
		"5. Backward\n"
		"6. Get Info\n"
		"7. Back\n"
		"8. Quit\n";

	/**
 * @brief Updates robot sensors based on the current state.
 *
 * This function updates the state of bumper, sonar, and force sensors based on
 * the current state of the robot as obtained from the robot API.
 *
 * @param bumper Pointer to the bumper sensor object.
 * @param sonar Pointer to the sonar sensor object.
 * @param force Pointer to the force sensor object.
 * @param robotAPI Pointer to the NaoRobotAPI object.
 */

public:
	/**
 * @brief Constructor for MotionMenu.
 *
 * Initializes the MotionMenu with a pointer to the Robot object.
 *
 * @param robot Pointer to the Robot object.
 */
	MotionMenu(Robot* robot) : Menus(robot) {}

	/**
 * @brief Overrides the printChoice function to print the menu choices.
 *
 * Outputs the available choices for the user in the motion menu.
 */
	void printChoice() override;

	/**
	* @brief Runs the motion menu and performs corresponding actions.
	*
	* This function displays the motion menu and allows the user to choose various
	* robot motion options such as moving forward, backward, turning left or right,
	* printing the controller status, and returning to the main menu or exiting the program.
	*
	* @return Returns true to continue executing the main menu, false to exit the program.
	*/
	bool run();
};
#endif