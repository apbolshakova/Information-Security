#include "Header.h"

int main(void) {
	setlocale(LC_ALL, "rus");
	cryptogram_t* data = NULL;

	char* russianWords = getTextFromFile(RUSSIAN_DICTIONARY_FILE_PATH, TRUE_);

	printf("������� ���� �� ����� � ������������� ������� (�� 255 ��������):\n");
	char* srcFileName = getFileName();

	data = initCryptogram(srcFileName);

	if (!data) {
		printf("��������� ������ ��� �������������. ������� ����� ������ ��� ������.\n");
		_getch();
		return 0;
	}

	data->wordListHead = sortWordsByLen(data->wordListHead);
	printDecodedWords(data);

	handleMainCycle(data, russianWords);
	cleanMemory(data);
	_getch();
	return 0;
}

char* getFileName() {
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName) {
		printf("������: �������� ��� ��������� ������.\n");
		return NULL;
	}
	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}

void handleMainCycle(cryptogram_t* data, char* russianWords) {
// ���� ���� a � b ����������:
//     ��� ������ 20 ���� �� ������:
//         �������� ����� �� ������� (a, b)
//         ���������, ���� �� ����� ����� � �������
// 	           ���� ����, ��������� ������� ���������� ���� �� �������
//     ���� ������� 10+ ���������� ����, �� ������� ������������ ����� � �������� � ������: ����� ��� ����������
//         ���� ������������ �������, ��� �����
// 	           ������� �� �����
//     ���������� ��������� ���������� (a, b)
//     �������� ������� ������
//     ���������� ������� ���������� ���� � 0
// ���� a ��� b ����������� � ������������, �� ������� ��������� � �������

	while (data->aCoefficient != END_OF_OPTIONS && data->bCoefficient != END_OF_OPTIONS) {
		system("cls");
		printEncryptionKey(data);

		words_list_item_t* word = data->wordListHead;
		int foundWords = 0;

		for (int i = 0; i < NUM_OF_WORD_TO_ANALIZE; i++) {
			if (word == NULL || foundWords == REQUIRED_CORRECT_WORDS) break;

			if (strstr(russianWords, getDecodedWord(word, data)) != NULL) {
				foundWords++;
				printf("������� �����: %s\n", getDecodedWord(word, data));
			}

			word = word->next;
		}

		if (foundWords >= REQUIRED_CORRECT_WORDS) {
			printf("���������� ����������������� ������������: a - %i, b - %i!\n������� 1 ��� ������ ��� 2 ��� ����������� ������.", 
				data->aCoefficient, data->bCoefficient);
			// TODO
			_getch();
		}

		setNextB(data);
		if (data->bCoefficient == END_OF_OPTIONS) {
			setNextA(data);
			data->bCoefficient = 0;
		}
		updateDecodeDictionary(data);
	}
}