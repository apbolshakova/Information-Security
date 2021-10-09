#include "Header.h"

int main(void)
{
	setlocale(LC_ALL, "rus");
	FILE* fSrc;
	FILE* fRes;
	printf("Введите название файла с исходным текстом (до 255 символов):\n");
	char* srcFileName = getFileName();
	printf("Введите название файл для сохранения результата (до 255 символов):\n");
	char* resFileName = getFileName();
	
	if (!srcFileName || !resFileName)
	{
		printf("Ошибка: отсутствует название одного из файлов.\n");
		return FAIL;
	}
	if (!(fSrc = fopen(srcFileName, "r")))
	{
		printf("Ошибка при открытии файла с исходным текстом.\n");
		return FAIL;
	}
	if (!(fRes = fopen(resFileName, "w")))
	{
		printf("Ошибка при создании файла для записи результата.\n");
		return FAIL;
	}
	
	int a = getA();
	int b = getB();

	int operationCode = 0;
	printf("Введите 1 для шифрования, 2 для дешифрования и любую другую клавишу для выхода: ");
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
		printf("Произошла ошибка при выделении памяти.\n");
		return NULL;
	}

	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}

int getA()
{
	int a = 0;
	printf("Введите коэффициент a для шифрования по формуле (a*letter + b) mod m: ");
	scanf("%i", &a);
	while (a < 1 || a >= M || getNOD(a, M) != 1)
	{
		printf("Некорректное a. НОД(a, m) должен быть 1, где m = 32. Также a не может быть меньше 1 и больше чем m-1.");
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
	printf("Введите коэффициент b для шифрования по формуле (a*letter + b) mod m: ");
	scanf("%i", &b);
	while (b < 0 || b >= M)
	{
		printf("Некорректное b: он не может быть меньше чем 0 и больше чем m-1.");
		scanf("%i", &b);
	}
	return b;
}