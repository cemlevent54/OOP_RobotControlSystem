#pragma once

#include "RobotControler.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
// sensor.h
#include <iostream>
#include <string>
#include "IRSensor.h"
#include "LidarSensor.h"

class Robot {
public:
    FestoRobotAPI* robotAPI;
    RobotControler* robotControler;
    //Festointerface

    Robot();
};