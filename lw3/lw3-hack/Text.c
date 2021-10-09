#include "Header.h"

char* getTextFromFile(char* dataPath, bool_t showLoadingProcess) {
	FILE* f = fopen(dataPath, "r");
	if (f == NULL) return;
	long int fileSize = getFileSize(f);

	char* curStr = (char*)calloc(fileSize, sizeof(char));
	if (curStr == NULL) return NULL;

	char* text = (char*)calloc(fileSize, sizeof(char));
	if (text == NULL) {
		curStr = NULL;
		free(curStr);
		return NULL;
	}

	char charForLoadingInfo = '\0';
	while (fgets(curStr, fileSize, f) != NULL) saveDataFromString(text, curStr, showLoadingProcess, &charForLoadingInfo);
	free(curStr);
	fclose(f);

	return text;
}

void saveDataFromString(char* text, char* strToSave, bool_t showLoadingProcess, char* charForLoadingInfo) {
	if (showLoadingProcess == TRUE_) {
		if (*charForLoadingInfo != strToSave[0]) {
			*charForLoadingInfo = strToSave[0];
			system("cls");
			printf("Загрузка: в текущей строке первый символ - %c\n", *charForLoadingInfo);
		}
	}

	char* sav = text;
	while (*text) text++;
	
	while (*strToSave) {
		*text = *strToSave;
		text++;
		strToSave++;
	}

	*text = '\0';
	text = sav;
}

void printText(cryptogram_t* data) {
	printf("Текст криптограммы с выполненными заменами:\n\n");
	char* ptr = data->text;
	while (*ptr) {
		printf("%c", getDecodedLetter(*ptr, data->decodeDictionary));
		ptr++;
	}
	printf("\n\n");
}

long int getFileSize(FILE* f) {
	long int sav = ftell(f);
	fseek(f, 0L, SEEK_END);
	long int fileSize = ftell(f);
	fseek(f, sav, SEEK_SET);
	return(fileSize);
}