//Alper Can Özer - 152120211117 - 30.12.2023

#include "App.h"

/**
 * @brief Runs the application.
 *
 * This function is responsible for executing the main functionality of the application.
 * It first performs authentication, and if successful, displays a menu for the user to
 * choose different options related to connection, motion, and sensors.
 */
void App::run()
{
	if (!authentication.authenticate())
	{
		return;
	}
	bool exit = false;
	do
	{
		cout << mainMenu << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			exit = connectionMenu->run();
			break;
		case 2:
			exit = motionMenu->run();
			break;
		case 3:
			exit = sensorMenu->run();
			break;
		case 4:
			cout << endl << "Goodbye. Exit...";
			exit = false;
			break;
		default:
			cout << "Please enter a valid number!" << endl << endl;
			break;
		}
	} while (exit);
}
