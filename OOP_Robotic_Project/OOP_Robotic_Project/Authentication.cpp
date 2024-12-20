// 152120211071 - Cem Levent Avcý

#include <iostream>
#include <string>
#include "Authentication.h"

/*
* @brief Authenticates the user based on name, surname, and access code.
* 
* This function prompts the user to enter their name, surname, and access code.
* It then checks the entered access code against the encrypted access code stored
* in the robot operator. If the access code is correct, the user is authenticated,
* otherwise, they are denied access.
* 
* @return Returns true if the user is successfully authenticated, false otherwise.
*/

bool Authentication::authenticate()
{
	std::string name, surname;
	unsigned int accessCode;

	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter your surname: ";
	std::cin >> surname;
	std::cout << "Enter your access code: ";
	std::cin >> accessCode;

	if(!robotOperator.checkAccessCode(encryptor.encrypt(accessCode)))
	{
		std::cout << "Access denied. Incorrect access code." << std::endl;
		return false;
	}
	else {
		std::cout << "Access granted. Welcome, " << name << " " << surname << "!" << std::endl;
		return true;
	}
}