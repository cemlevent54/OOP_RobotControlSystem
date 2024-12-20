// 152120211071 Cem Levent Avcý

#include "ConnectionMenu.h"


/**
 * @brief Prints the choices available in the connection menu.
 *
 * This function outputs the available choices for the user in the connection menu.
 */
void ConnectionMenu::printChoice()
{
	cout << choice << endl;
}

/**
 * @brief Runs the connection menu and performs corresponding actions.
 *
 * This function displays the connection menu and allows the user to pick options
 * such as connecting, disconnecting, returning to the main menu, or exiting the program.
 *
 * @return Returns true to continue executing the main menu, false to exit the program.
 */
bool ConnectionMenu::run()
{
	cout << "Connection Menu" << endl << endl;
	bool connection = true;
	while (connection)
	{
		printChoice();
		int pick2;
		cin >> pick2;

		switch (pick2)
		{
		case 1: {
			// Connect Robot
			// buradayýz!!
			//robot->robotControler = new RobotControler(robot->robot);
			break;
		}
			
			
		case 2: // Disconnect Robot
			
			break;
		case 3:
			connection = false;
			cout << "Back to main menu..." << endl << endl;
			break;
		case 4:
			connection = false;
			cout << "Exit..." << endl << endl;
			return false;
			break;
		default:
			cout << "Please enter a valid number!" << endl << endl;
			break;
		}
		return true;
	}
}