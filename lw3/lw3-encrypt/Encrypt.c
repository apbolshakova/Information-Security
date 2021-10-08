#include "Common.c"

status_t handleEncryption(FILE* fSrc, FILE* fRes, int a, int b)
{
	long int fileSize = getFileSize(fSrc);
	char* temp = (char*)calloc(fileSize, sizeof(char));
	if (temp == NULL) return FAIL;
	while (fgets(temp, fileSize, fSrc) != NULL) encodeDataFromString(fRes, temp, a, b);
	free(temp);
	return SUCCESS;
}

void encodeDataFromString(FILE* fRes, char* str, int a, int b)
{
	while (*str)
	{
		if (isRussianCapitalLetter(*str))
		{
			*str = (((a * (*str - 'À')) + b) % M) + 'À';
		}
		if (isRussianLowercaseLetter(*str))
		{
			*str = (((a * (*str - 'à')) + b) % M) + 'à';
		}
		fprintf(fRes, "%c", *str);
		str++;
	}
}