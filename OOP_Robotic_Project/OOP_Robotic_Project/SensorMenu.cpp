#include "SensorMenu.h"

void SensorMenu::printChoice() {
	cout << choice << endl;
}

bool SensorMenu::run() {
	cout << "Sensor Menu" << endl;

	bool sensor = true;

	while (sensor)
	{
		printChoice();

		int pick2;
		cin >> pick2;

		switch (pick2)
		{
		case 1:
			if (robot->robotControler)
			{
				//robot->robotControler->printSensor("IR Sensor");
			}
			else
			{
				cout << "Please Connect First!";
			}
			break;
		case 2:
			if (robot->robotControler)
			{
				//robot->controller->printSensor("Lidar Sensor");
			}
			else
			{
				cout << "Please Connect First!";
			}
			break;
		case 3:
			sensor = false;
			cout << "Back to main menu..." << endl << endl;
			break;
		case 4:
			sensor = false;
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