/*******************************************************************************
 * String Encrypt and Decrypt via Vignere Cipher
 *
 * A program that takes as input a string of text to be encrypted or decrypted
 * then a key. It forces uppercase shifting on the strings
 * It then calls on (en/de)cryption functions to shift the characters based on
 * a key. Finally, it displays encrypted and decrypted texts/messages for the user.
 *
 * INPUT
 * _____________________________________________________________________________
 * text                     : the text to be encrypted
 * message                  : the message to be decrypted
 * otpKey                   : the OTP key
 * repeatKey                : a string to hold the repeated OTP
 * numRepeat                : the number of times to repeat the OTP so that it
 *                            is not shorter than the text or message
 *
 * OUTPUT
 * _____________________________________________________________________________
 * encryptText              : encrypted texts
 * decryptText              : decrypted message                :
 *
 *  FORMULAS USED
 * _____________________________________________________________________________
 * Vignere Cipher Encryption: E_i = (P_i + K_i) mod 26
 * Vignere Cipher Decryption: D_i = (E_i - K_i + 26) mod 26
 *
 *
 * PSUEDOCODE
 * _____________________________________________________________________________
 * Function Encrypt--takes two chars for message and key,
 * uses modular arithmetic to return text key as encrypted
 * according to key
 *
 * Function Decrypt--takes two chars for message and key,
 * uses modular arithmetic to return message char as decrypted
 * according to key
 *
 * MAIN--
 * Branches to (en/de)cryption functions to alter message
 * Displays new message for user
 *
 ******************************************************************************/
#include <iostream>

/*******************************************************************************
 * FUNCTION VignereEncryptChar
 *
 * A function that takes as input a character to be encrypted
 * then a key. It uses modular arithmetic to shift the character based on the key
 * Finally, it returns the encrypted character
 *
 *
 * INPUT
 * _____________________________________________________________________________
 * inp                      : character to be encrypted
 * key						: character that acts as the key for the input char
 * 							  and determines the shift
 *
 * OUTPUT
 * _____________________________________________________________________________
 * encryptChar				: the encrypted character
 *
 * RETURNS
 * _____________________________________________________________________________
 * The encrypted character, encryptChar
 ******************************************************************************/
char VignereEncryptChar(char inp, char key)
{
	char encryptChar;

	encryptChar = ( (inp - 'A') + (key - 'A') ) % 26 + 'A';

	return encryptChar;
}

/*******************************************************************************
 * FUNCTION VignereDecryptChar
 *
 * A function that takes as input a character to be decrypted
 * then a key. It uses modular arithmetic to shift the character based on the key
 * Finally, it returns the decrypted character
 *
 *
 * INPUT
 * _____________________________________________________________________________
 * inp                      : character to be decrypted
 * key						: character that acts as the key for the input char
 * 							  and determines the shift
 *
 * OUTPUT
 * _____________________________________________________________________________
 * decryptChar				: the decrypted character
 *
 * RETURNS
 * _____________________________________________________________________________
 * The decrypted character, decryptChar
 ******************************************************************************/
char VignereDecryptChar(char inp, char key)
{
	char decryptChar;

	decryptChar = ( (inp - 'A') - (key - 'A') + 26) % 26 + 'A';

	return decryptChar;

}

int main()
{
	std::string text = "bUTTERfINGERS ARE YUMMY";   //INPUT
	std::string otpKey = "ABC";                     //INPUT
	std::string repeatKey;                          //INPUT
	std::string message = "BVVTFTFJPGFTS CRF YVOMZ";//INPUT
	std::string encryptText(text.length(), ' ');    //OUTPUT
	std::string decryptText(text.length(), ' ');    //OUTPUT

	//uppercase shift text
	for (int i = 0; i < text.length(); i++)
	{
		if(!std::isupper(text[i]))
		{
			text[i] = std::toupper(text[i]);
		}

	}

	//force uppercase shift otp key
	for(int i = 0; i < otpKey.length(); i++)
	{
		if(!std::isupper(otpKey[i]))
		{
			otpKey[i] = std::toupper(otpKey[i]);
		}
	}

	int numRepeat = (text.length()/otpKey.length() + 1);
	repeatKey.reserve(otpKey.size() * numRepeat);//reserve space for repeatKey
	for (int i = 0; i < numRepeat; i++)//append numRepeat copies of otpKey into repeatKey
	{
		repeatKey += otpKey;
	}

	//force uppercase shift on text
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = std::toupper(text[i]);
	}

	//send each character of text and key to encryption function
	for (int i = 0; i < text.length(); i++)
	{

		if(isalpha(text[i]))
		{
			encryptText[i] = VignereEncryptChar(text[i], repeatKey[i]);
		}

	}

	//force uppercase shift on message
	for(int i = 0; i < message.length(); i++)
	{
		if(!std::isupper(message[i]))
		{
			message[i] = std::toupper(message[i]);
		}
	}

	//send each character of message and key to decryption function
	for (int i = 0; i < text.length(); i++)
	{

		if(isalpha(text[i]))
		{
			decryptText[i] = VignereDecryptChar(message[i], repeatKey[i]);
		}

	}

	//Display the encrypted and decrypted text/message for the user
	std::cout << "Text       : " << text << "   : length: " << text.length();
	std::cout << "\nKey        : " << repeatKey;
	std::cout << "\nEncrypted  : " << encryptText;

	std::cout << "\n\nMessage    : " << message << "   : length: " << text.length();
	std::cout << "\nKey        : " << repeatKey;
	std::cout << "\nDecrypted  : " << decryptText;

	return 0;
}



