#include "Header.h"

void initText(cryptogram_t* data, FILE* f, char* DATA_PATH)
{
	fclose(f);
	f = fopen(DATA_PATH, "r");
	if (f == NULL) return;
	long int fileSize = getFileSize(f);
	char* temp = (char*)calloc(fileSize, sizeof(char));
	if (temp == NULL) return NULL;
	data->text = (char*)calloc(fileSize, sizeof(char));
	if (data->text == NULL)
	{
		temp = NULL;
		free(temp);
		return NULL;
	}
	while (fgets(temp, fileSize, f) != NULL) saveDataFromString(data, temp);
	free(temp);
}

void saveDataFromString(cryptogram_t* data, char* str)
{
	char* sav = data->text;
	while (*(data->text)) data->text++;
	
	while (*str)
	{
		*(data->text) = *str;
		(data->text)++;
		str++;
	}
	*(data->text) = '\0';

	data->text = sav;
}

void printText(cryptogram_t* data)
{
	printf("Текст криптограммы с выполненными заменами:\n\n");
	char* ptr = data->text;
	while (*ptr)
	{
		printf("%c", getDecodedLetter(*ptr, data->decodeDictionary));
		ptr++;
	}
	printf("\n\n");
}

long int getFileSize(FILE* f)
{
	long int sav = ftell(f);
	fseek(f, 0L, SEEK_END);
	long int fileSize = ftell(f);
	fseek(f, sav, SEEK_SET);
	return(fileSize);
}