#include "TestEncryption.h"
#include <iostream>
using namespace std;

/**
 * @file TestEncryption.cpp
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Implementation of the TestEncryption class.
 *
 * This file contains the implementation of the TestEncryption class,
 * which includes test cases for the Encryption class.
 */

 //! Runs all test cases.
 /*!
  * Executes individual test methods to validate the functionality of the Encryption class.
  */
void TestEncryption::runTests()
{
    cout << "Running Encryption Tests...\n";
    testEncrypt();
    testDecrypt();
}

//! Tests the encryption functionality of the Encryption class.
/*!
 * Validates the encrypt method by encrypting a sample code.
 */
void TestEncryption::testEncrypt()
{
    Encryption encryption;
    int code = 1234;
    int encryptedCode = encryption.encrypt(code);
    cout << "Test Encrypt: Original: " << code << ", Encrypted: " << encryptedCode << endl;
}

//! Tests the decryption functionality of the Encryption class.
/*!
 * Validates the decrypt method by decrypting an encrypted code.
 */
void TestEncryption::testDecrypt()
{
    Encryption encryption;
    int code = 1234;
    int encryptedCode = encryption.encrypt(code);
    int decryptedCode = encryption.decrypt(encryptedCode);
    cout << "Test Decrypt: Encrypted: " << encryptedCode << ", Decrypted: " << decryptedCode << endl;
}
