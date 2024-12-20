#pragma once

#include "Menus.h"

/**
 * @class ConnectionMenu
 * @brief Represents the menu for managing robot connections.
 */
class ConnectionMenu : public Menus {
private:
	std::string choice = "1. Connect Robot\n"
		"2. Disconnect Robot\n"
		"3. Back\n"
		"4. Quit\n";
public:
	/**
 * @brief Constructor for ConnectionMenu.
 *
 * Initializes the ConnectionMenu with a pointer to the Robot object.
 *
 * @param robot Pointer to the Robot object.
 */
	ConnectionMenu(Robot* robot) : Menus(robot) {}

	/**
	   * @brief Prints the available choices in the connection menu.
	   *
	   * Outputs the available choices for the user in the connection menu.
	   */
	void printChoice() override;

	/**
 * @brief Runs the connection menu and performs corresponding actions.
 *
 * This function displays the connection menu and allows the user to pick options
 * such as connecting, disconnecting, returning to the main menu, or exiting the program.
 *
 * @return Returns true to continue executing the main menu, false to exit the program.
 */
	bool run() override;
};