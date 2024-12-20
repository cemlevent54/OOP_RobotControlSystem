#include "Encryption.h"
#include <utility>

/**
 * @file Encryption.cpp
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Implementation of the Encryption class.
 *
 * This file contains the implementation of the Encryption class methods
 * for encrypting and decrypting integer codes.
 */

 /**
  * @brief Encrypts a given 4-digit code.
  *
  * This method encrypts a 4-digit integer code by adding 7 to each digit,
  * taking modulo 10, and swapping the positions of the 1st and 3rd digits
  * as well as the 2nd and 4th digits.
  *
  * @param code The 4-digit integer code to be encrypted.
  * @return The encrypted code as an integer.
  */
int Encryption::encrypt(int code)
{
    int digits[4];
    for (int i = 3; i >= 0; --i)
    {
        digits[i] = (code % 10 + 7) % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    int encryptedCode = 0;
    for (int i = 0; i < 4; ++i)
    {
        encryptedCode = encryptedCode * 10 + digits[i];
    }
    return encryptedCode;
}

/**
 * @brief Decrypts a given encrypted 4-digit code.
 *
 * This method decrypts an encrypted integer code by swapping the positions
 * of the 1st and 3rd digits as well as the 2nd and 4th digits, and then
 * reversing the encryption logic by subtracting 7 (modulo 10) from each digit.
 *
 * @param code The encrypted integer code to be decrypted.
 * @return The original 4-digit code as an integer.
 */
int Encryption::decrypt(int code)
{
    int digits[4];
    for (int i = 3; i >= 0; --i)
    {
        digits[i] = code % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    int decryptedCode = 0;
    for (int i = 0; i < 4; ++i)
    {
        digits[i] = (digits[i] + 3) % 10; // Correct decryption adjustment
        decryptedCode = decryptedCode * 10 + digits[i];
    }
    return decryptedCode;
}
