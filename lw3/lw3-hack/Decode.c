#include "Header.h"

void updateDecodeDictionary(cryptogram_t* data)
{
	int a = data->aCoefficient;
	int b = data->bCoefficient;

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		int encodedIndex = (a * i + b) % ALPHABET_SIZE;
		(data->decodeDictionary)[encodedIndex] = i;
	}
}

char getDecodedLetter(char ch, int decodeDictionary[ALPHABET_SIZE])
{
	if (isRussianCapitalLetter(ch))
	{
		return decodeDictionary[ch - 'À'] + 'À';
	}
	if (isRussianLowercaseLetter(ch))
	{
		return decodeDictionary[ch - 'à'] + 'à';
	}
	return ch;
}