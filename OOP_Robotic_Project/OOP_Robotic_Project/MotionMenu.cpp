#include "MotionMenu.h"

void MotionMenu::printChoice()
{
	cout << choice << endl;
}

/**
 * @brief Runs the motion menu and performs corresponding robot motions.
 *
 * This function displays the motion menu and allows the user to choose various
 * robot motion options such as moving forward, backward, turning left or right,
 * printing the controller status, and returning to the main menu or exiting the program.
 *
 * @return Returns true to continue executing the main menu, false to exit the program.
 */
bool MotionMenu::run() {
	cout << "Motion Menu" << endl;
	bool motion = true;

	while (motion)
	{
		printChoice();

		int pick2;
		cin >> pick2;

		switch (pick2)
		{
		case 1:
			if (robot->robotControler)
			{

			}
			else
			{
				cout << connectionErr << endl << endl;
			}
			break;
		case 2:
			if (robot->robotControler)
			{
				
			}
			break;
		case 3:
			if (robot->robotControler)
			{
				
			}
			else
			{
				cout << connectionErr << endl << endl;
			}
			break;
		case 4:
			if (robot->robotControler)
			{

			}
			else
			{
				cout << connectionErr << endl << endl;
			}
			break;
		case 5:
			if (robot->robotControler)
			{

			}
			else
			{
				cout << connectionErr;
			}
			break;
		case 6:
			if (robot->robotControler)
			{

			}
			else
			{
				cout << connectionErr;
			}
			break;
		case 7:
			motion = false;
			cout << "Back to main menu..." << endl << endl;
			break;
		case 8:
			motion = false;
			cout << "Exit..." << endl;
			return false;
			break;
		default:
			cout << "Please enter a valid number!" << endl << endl;
			break;
		}
		return true;
	}
}

/**
 * @brief Updates the robot sensors based on the current state.
 *
 * This function updates the state of bumper, sonar, and force sensors based on
 * the current state of the robot as obtained from the robot API.
 *
 * @param bumper Pointer to the bumper sensor object.
 * @param sonar Pointer to the sonar sensor object.
 * @param force Pointer to the force sensor object.
 * @param robotAPI Pointer to the NaoRobotAPI object.
 */