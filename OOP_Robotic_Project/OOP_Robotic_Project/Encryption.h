#ifndef ENCRYPTION_H
#define ENCRYPTION_H

/**
 * @file Encryption.h
 * @author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Declaration of the Encryption class.
 *
 * This file contains the declaration of the Encryption class, which provides
 * static methods for encrypting and decrypting integer codes.
 */

 /**
  * @class Encryption
  * @brief A class for handling encryption and decryption of integer codes.
  *
  * This class includes static methods for encrypting and decrypting codes.
  */
class Encryption
{
public:
	/**
	 * @brief Encrypts a given code.
	 *
	 * This static method takes a 4-digit integer code and encrypts it using
	 * a predefined algorithm.
	 *
	 * @param code The 4-digit integer code to be encrypted.
	 * @return The encrypted code as an integer.
	 */
	static int encrypt(int code);

	/**
	 * @brief Decrypts a given code.
	 *
	 * This static method takes an encrypted integer code and decrypts it
	 * back to the original 4-digit code.
	 *
	 * @param code The encrypted code to be decrypted.
	 * @return The original code as an integer.
	 */
	static int decrypt(int code);
};

#endif // ENCRYPTION_H
