#include "Header.h"

cryptogram_t* initCryptogram(char* dataPath)
{
	cryptogram_t* data = (cryptogram_t*)malloc(sizeof(cryptogram_t));
	if (data == NULL) return NULL;

	data->decodeDictionary = (int*)calloc(ALPHABET_SIZE, sizeof(int));
	if (!data->decodeDictionary) {
		data = NULL;
		free(data);
		return NULL;
	}

	FILE *f = fopen(dataPath, "r");
	if ((f != NULL) && (fgetc(f) != EOF) && !(feof(f)))
	{
		initText(data, f, dataPath);
	}
	fclose(f);
	parseTextIntoWords(data);

	data->aCoefficient = 1;
	data->bCoefficient = 1;
	
	updateDecodeDictionary(data);

	return data;
}

void printCryptogram(cryptogram_t* data)
{
	system("cls");
	printEncryptionKey(data);
	printText(data);
}

void cleanMemory(cryptogram_t* data)
{
	cleanWordsList(data);

	data->text = NULL;
	free(data->text);

	data->decodeDictionary = NULL;
	free(data->decodeDictionary);

	data = NULL;
	free(data);
}