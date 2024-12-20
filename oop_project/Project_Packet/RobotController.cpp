
//---------------------------------------------------------------------------------
//  Description:  Example controller program for Nao robot.
//                This demonstrates how to use NaoRobotAPI
//---------------------------------------------------------------------------------

#include "FestoRobotAPI.h"
#include <iostream>

FestoRobotAPI* robotino;

void print() {

	//Read IR range values
	double ir[9];
	for (int i = 0; i < 9; i++)
		ir[i] = robotino->getIRRange(i);

	//Pose
	double x, y, th;
	robotino->getXYTh(x, y, th);

	cout << "--------------------SENSOR VALUES-------------------------------------" << endl;
	cout << "POSE         : (X) " << x << " meters, "
		<< "(Y) " << y << " meters, "
		<< "(Th) " << (th * 180) / 3.14 << " degrees" << endl << endl;
	cout << "IR RANGES : " << endl;
	cout << "       FRONT           " << endl;
	cout << "        "<<ir[0]<<"           " << endl;
	cout << "    " << ir[1] << "     "<<ir[8]<<"      " << endl;
	cout << "    " << ir[2] << "     " << ir[7] << "      " << endl;
	cout << "    " << ir[3] << "     " << ir[6] << "      " << endl;
	cout << "    " << ir[4] << "     " << ir[5] << "      " << endl;
	cout << "----------------------------------------------------------------------" << endl;

	int number = robotino->getLidarRangeNumber();

	float* ranges = new float[number];
	cout << "--------------------LIDAR VALUES (in meters)-------------------------------------" << endl;

	robotino->getLidarRange(ranges);

	for (int i = 0; i < number; i++) {
		cout << i << "-> ";
		cout << ranges[i] <<endl;
	}
	cout << "----------------------------------------------------------------------" << endl;

	delete[] ranges;


}


// main function
int main() {
	//Create a robot object
	robotino = new FestoRobotAPI();

	//Make connection to Nao
	robotino->connect();
	Sleep(2000);
	print();


	//Move forward and print the sensor values
	robotino->move(FORWARD);
	Sleep(2000);
	robotino->stop();
	print();
	
	//Move backward and print the sensor values
	robotino->move(BACKWARD);
	Sleep(2000);
	robotino->stop();
	print();

	//Move left and print the sensor values
	robotino->move(LEFT);
	Sleep(2000);
	robotino->stop();
	print();

	//Move right and print the sensor values
	robotino->move(RIGHT);
	Sleep(2000);
	robotino->stop();
	print();

	//Turn left and print the sensor values
	robotino->rotate(LEFT);
	Sleep(2000);
	robotino->stop();
	print();

	//Turn right and print the sensor values
	robotino->rotate(RIGHT);
	Sleep(2000);
	robotino->stop();
	print();

	// close connection to the robot
	robotino->disconnect();

	//Delete the robot object
	delete robotino;
	return 0;
}