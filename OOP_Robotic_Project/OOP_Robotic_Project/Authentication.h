#pragma once

#include "RobotOperator.h"
#include "Encryption.h"
#include <iostream>

#ifndef AUTHENTÝCATÝON_H
#define AUTHENTÝCATÝON_H

/**
 * @class Authentication
 * @brief Handles user authentication using a RobotOperator and Encryption.
 */
class Authentication {
private:
    RobotOperator robotOperator;
    Encryption encryptor;

public:
    /**
 * @brief Default constructor for Authentication.
 *
 * Initializes Authentication with default values for RobotOperator.
 */
    Authentication() :
        robotOperator("Levent", "Avcý", 1234) {}


    /**
     * @brief Authenticates the user based on name, surname, and access code.
     *
     * This function prompts the user to enter their name, surname, and access code.
     * It then checks the entered access code against the encrypted access code stored
     * in the robot operator. If the access code is correct, the user is authenticated,
     * otherwise, they are denied access.
     *
     * @return Returns true if the user is successfully authenticated, false otherwise.
     */
    bool authenticate();
};


#endif