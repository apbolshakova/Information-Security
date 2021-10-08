#include "Header.h"

int main(void)
{
	setlocale(LC_ALL, "rus");
	cryptogram_t* data = NULL;

	FILE* fSrc;
	printf("Enter name of file with source code (up to 255 characters):\n");
	char* srcFileName = getFileName();
	
	if (!srcFileName)
	{
		printf("ERROR: unable to get file name.\n");
		return FAIL;
	}
	
	data = initCryptogram(fSrc);

	// ���� ���� a � b ����������:
	//     ��� ������� �� ����� ������� 20 ����:
	//         �������� ����� �� ������� (a, b)
	//         ���������, ���� �� ����� ����� � �������
	//     ���� ������� 10+ ����, �� ������� ������������ ����� � �������� � ������, ����� �� ���������� �������
	//         ���� ������������ �������, ��� �� �����, �� ���������� ���� ��������� ��������� � ��������� ����������� ������������
	//     ����� 
	//		   ���������� ��������� ���������� (a, b)
	//         �������� ������� ������ 
	fclose(fSrc);
	return 0;
}

char* getFileName()
{
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName)
	{
		printf("ERROR: memory allocation problem.\n");
		return NULL;
	}
	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}