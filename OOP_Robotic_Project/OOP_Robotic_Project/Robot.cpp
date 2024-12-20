#include "Robot.h"

/**
 * @brief Default constructor for the Robot class.
 *
 * This constructor initializes the Robot object by setting the controller
 * to NULL and creating instances of BumperSensor, ForceSensor, and SonarSensor.
 */

Robot::Robot()
{
	robotAPI = new FestoRobotAPI();
	robotControler = new RobotControler(robotAPI);
	//robot = new NaoRobotInterface(robotAPI);
}