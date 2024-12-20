#ifndef TESTENCRYPTION_H
#define TESTENCRYPTION_H

#include "Encryption.h"

/**
 * @file TestEncryption.h
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Declaration of the TestEncryption class for testing the Encryption class.
 *
 * This file contains the class declaration for the TestEncryption class,
 * which includes test cases to validate the functionality of the Encryption class.
 */

 //! A class for testing the Encryption class.
 /*!
  * This class provides methods for running various test cases to validate
  * encryption and decryption operations.
  */
class TestEncryption {
public:
    //! Runs all test cases.
    /*!
     * Calls individual test methods to validate the functionality of the Encryption class.
     */
    static void runTests();

    //! Tests the encrypt method of the Encryption class.
    /*!
     * Validates the correctness of the encryption process.
     */
    static void testEncrypt();

    //! Tests the decrypt method of the Encryption class.
    /*!
     * Validates the correctness of the decryption process.
     */
    static void testDecrypt();
};

#endif // TESTENCRYPTION_H
