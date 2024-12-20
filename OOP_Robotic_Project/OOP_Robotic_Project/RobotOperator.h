#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "Encryption.h"

/**
 * @file RobotOperator.h
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Declaration of the RobotOperator class.
 *
 * This file contains the declaration of the RobotOperator class,
 * which is used to manage and control robot operator information,
 * including name, access code, and access state.
 */

 /**
  * @class RobotOperator
  * @brief A class to represent a robot operator with an access code.
  *
  * This class provides functionalities for managing an operator's
  * name, surname, access code, and access state. It also includes
  * methods for encrypting and decrypting access codes.
  */
class RobotOperator
{
private:
    std::string name;        /**< Name of the operator */
    std::string surname;     /**< Surname of the operator */
    unsigned int accessCode; /**< Encrypted access code of the operator */
    bool accessState;        /**< Access state (true: has access, false: no access) */

public:
    /**
     * @brief Constructor for RobotOperator.
     *
     * Initializes a robot operator with the given name, surname,
     * and access code.
     *
     * @param name The operator's first name.
     * @param surname The operator's surname.
     * @param accessCode The operator's access code.
     */
    RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode);

    /**
     * @brief Gets the operator's first name.
     * @return The operator's first name.
     */
    std::string getName() const;

    /**
     * @brief Gets the operator's surname.
     * @return The operator's surname.
     */
    std::string getSurname() const;

    /**
     * @brief Gets the access state of the operator.
     * @return True if the operator has access, false otherwise.
     */
    bool getAccessState() const;

    /**
     * @brief Encrypts the given code using the Encryption class.
     *
     * @param code The code to be encrypted.
     * @return The encrypted code.
     */
    int encryptCode(int code);

    /**
     * @brief Decrypts the given code using the Encryption class.
     *
     * @param code The code to be decrypted.
     * @return The decrypted code.
     */
    int decryptCode(int code);

    /**
     * @brief Checks if the provided code matches the operator's access code.
     *
     * @param code The code to verify.
     * @return True if the codes match, false otherwise.
     */
    bool checkAccessCode(int code);

    /**
     * @brief Prints the operator's details to the console.
     *
     * This includes the operator's name, surname, and access state.
     */
    void print() const;
};

#endif // ROBOTOPERATOR_H
