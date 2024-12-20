#include "RobotOperator.h"
#include <iostream>

/**
 * @file RobotOperator.cpp
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Implementation of the RobotOperator class.
 *
 * This file contains the implementation of the RobotOperator class methods,
 * including constructors, access control, and utility functions.
 */

 //! Constructor
 /*!
  * Initializes a RobotOperator object with the given name, surname, and access code.
  * The access code is encrypted and stored.
  *
  * @param name The operator's first name.
  * @param surname The operator's surname.
  * @param accessCode The operator's access code.
  */
RobotOperator::RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode)
    : name(name), surname(surname), accessState(false)
{
    this->accessCode = encryptCode(accessCode);
}

//! Getter for the operator's name.
/*!
 * @return The operator's first name.
 */
std::string RobotOperator::getName() const
{
    return name;
}

//! Getter for the operator's surname.
/*!
 * @return The operator's surname.
 */
std::string RobotOperator::getSurname() const
{
    return surname;
}

//! Getter for the operator's access state.
/*!
 * @return True if the operator has access, false otherwise.
 */
bool RobotOperator::getAccessState() const
{
    return accessState;
}

//! Encrypts the given code.
/*!
 * Uses the Encryption class to encrypt the given code.
 *
 * @param code The code to be encrypted.
 * @return The encrypted code.
 */
int RobotOperator::encryptCode(int code)
{
    return Encryption::encrypt(code);
}

//! Decrypts the given code.
/*!
 * Uses the Encryption class to decrypt the given code.
 *
 * @param code The code to be decrypted.
 * @return The decrypted code.
 */
int RobotOperator::decryptCode(int code)
{
    return Encryption::decrypt(code);
}

//! Verifies the provided access code.
/*!
 * Checks if the provided code matches the stored encrypted access code.
 * Updates the access state accordingly.
 *
 * @param code The code to verify.
 * @return True if the provided code is correct, false otherwise.
 */
bool RobotOperator::checkAccessCode(int code)
{
    if (code == accessCode) {
        return true;
    }
    return false;
}

//! Prints the operator's details.
/*!
 * Outputs the operator's name, surname, and access state to the console.
 */
void RobotOperator::print() const
{
    std::cout << "Name: " << name << " " << surname << "\n"
        << "Access State: " << (accessState ? "Granted" : "Denied") << std::endl;
}
