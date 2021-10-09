#include "Header.h"

int main(void) {
	setlocale(LC_ALL, "rus");
	cryptogram_t* data = NULL;

	printf("������� ���� �� ����� � ������������� ������� (�� 255 ��������):\n");
	char* srcFileName = getFileName();

	data = initCryptogram(srcFileName);

	if (!data) {
		printf("��������� ������ ��� �������������. ������� ����� ������ ��� ������.\n");
		_getch();
		return 0;
	}

	data->wordListHead = sortWordsByLen(data->wordListHead);
	printWords(data);

	handleMainCycle(data);
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

void handleMainCycle(cryptogram_t* data) {
// ���� ���� a � b ����������:
//     ��� ������ 20 ���� �� ������:
//         �������� ����� �� ������� (a, b)
//         ���������, ���� �� ����� ����� � �������
// 	           ���� ����, ��������� ������� ���������� ���� �� �������
//     ���� ������� 10+ ���������� ����, �� ������� ������������ ����� � �������� � ������, ��������� �� ���������
//         ���� ������������ �������, ��� ������
//             ���������� ���� ��������� ���������
//             ��������� ����������� ������������
// 	           ������� ��������� �� ������
// 	           ������� �� �����
//     ���������� ��������� ���������� (a, b)
//     �������� ������� ������
//     ���������� ������� ���������� ���� � 0
// ���� a ��� b ����������� � ������������, �� ������� ��������� � �������
	while (data->aCoefficient != END_OF_OPTIONS && data->bCoefficient != END_OF_OPTIONS) {
		for (int i = 0; i < NUM_OF_WORD_TO_ANALIZE; i++) {
			break;
		}
		break;
	}
}