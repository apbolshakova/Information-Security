#include "Header.h"

status_t handleDecryption(FILE* fSrc, FILE* fRes, int a, int b)
{
	int* decodeDictionary = getDecodeDictionary(a, b);
	if (!decodeDictionary) return FAIL;
	long int fileSize = getFileSize(fSrc);
	char* temp = (char*)calloc(fileSize, sizeof(char));
	if (temp == NULL) return FAIL;
	while (fgets(temp, fileSize, fSrc) != NULL) decodeDataFromString(fRes, temp, decodeDictionary);
	free(temp);
	free(decodeDictionary);
	return SUCCESS;
}

int* getDecodeDictionary(int a, int b)
{
	int* decodeDictionary = (int*)calloc(M, sizeof(int));
	if (!decodeDictionary) return NULL;

	for (int i = 0; i < M; i++) {
		int encodedIndex = (a * i + b) % M;
		decodeDictionary[encodedIndex] = i;
	}
	return decodeDictionary;
}

void decodeDataFromString(FILE* fRes, char* str, int decodeDictionary[M])
{
	while (*str)
	{
		if (isRussianCapitalLetter(*str))
		{
			*str = decodeDictionary[*str - 'À'] + 'À';
		}
		if (isRussianLowercaseLetter(*str))
		{
			*str = decodeDictionary[*str - 'à'] + 'à';
		}
		fprintf(fRes, "%c", *str);
		str++;
	}
}

