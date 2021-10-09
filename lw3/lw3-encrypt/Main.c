#include "Header.h"

int main(void)
{
	setlocale(LC_ALL, "rus");
	FILE* fSrc;
	FILE* fRes;
	printf("������� �������� ����� � �������� ������� (�� 255 ��������):\n");
	char* srcFileName = getFileName();
	printf("������� �������� ���� ��� ���������� ���������� (�� 255 ��������):\n");
	char* resFileName = getFileName();
	
	if (!srcFileName || !resFileName)
	{
		printf("������: ����������� �������� ������ �� ������.\n");
		return FAIL;
	}
	if (!(fSrc = fopen(srcFileName, "r")))
	{
		printf("������ ��� �������� ����� � �������� �������.\n");
		return FAIL;
	}
	if (!(fRes = fopen(resFileName, "w")))
	{
		printf("������ ��� �������� ����� ��� ������ ����������.\n");
		return FAIL;
	}
	
	int a = getA();
	int b = getB();

	int operationCode = 0;
	printf("������� 1 ��� ����������, 2 ��� ������������ � ����� ������ ������� ��� ������: ");
	scanf("%i", &operationCode);
	switch (operationCode)
	{
	case 1: handleEncryption(fSrc, fRes, a, b); break;
	case 2: handleDecryption(fSrc, fRes, a, b); break;
	default: break;
	}

	fclose(fSrc);
	fclose(fRes);
	return 0;
}

char* getFileName()
{
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName)
	{
		printf("��������� ������ ��� ��������� ������.\n");
		return NULL;
	}

	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}

int getA()
{
	int a = 0;
	printf("������� ����������� a ��� ���������� �� ������� (a*letter + b) mod m: ");
	scanf("%i", &a);
	while (a < 1 || a >= M || getNOD(a, M) != 1)
	{
		printf("������������ a. ���(a, m) ������ ���� 1, ��� m = 32. ����� a �� ����� ���� ������ 1 � ������ ��� m-1.");
		scanf("%i", &a);
	}
	return a;
}

int getNOD(int n1, int n2)
{
	int div;
	if (n1 == n2)  return n1;
	int d = n1 - n2;
	if (d < 0) {
		d = -d;  div = getNOD(n1, d);
	}
	else
		div = getNOD(n2, d);
	return div;
}

int getB()
{
	int b = 0;
	printf("������� ����������� b ��� ���������� �� ������� (a*letter + b) mod m: ");
	scanf("%i", &b);
	while (b < 0 || b >= M)
	{
		printf("������������ b: �� �� ����� ���� ������ ��� 0 � ������ ��� m-1.");
		scanf("%i", &b);
	}
	return b;
}