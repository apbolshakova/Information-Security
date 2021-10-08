#include "Header.h"

int main(void)
{
	FILE* fSrc;
	FILE* fRes;
	char* srcFileName = getSrcFileName();
	char* resFileName = getResFileName();
	
	if (!srcFileName || !resFileName)
	{
		printf("ERROR: unable to get file name.\n");
		return FAIL;
	}
	if (!(fSrc = fopen(srcFileName, "r")))
	{
		printf("ERROR: unable to open file.\n");
		return FAIL;
	}
	if (!(fRes = fopen(resFileName, "w")))
	{
		printf("ERROR: unable to open file.\n");
		return FAIL;
	}
	
	int a = getA();
	int b = getB();

	int operationCode = 0;
	printf("Enter 1 to encode, 2 to decode and 3 to exit: ");
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

char* getSrcFileName()
{
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName)
	{
		printf("ERROR: memory allocation problem.\n");
		return NULL;
	}
	printf("Enter name of file with source code (up to 255 characters):\n");
	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}

char* getResFileName()
{
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName)
	{
		printf("ERROR: memory allocation problem.\n");
		return NULL;
	}
	printf("Enter name of file for result saving (up to 255 characters):\n");
	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}

int getA()
{
	int a = 0;
	printf("Enter coefficient a for encrypting with formula (a*letter + b) mod m: ");
	scanf("%i", &a);
	while (a < 1 || a >= M || getNOD(a, M) != 1)
	{
		printf("Incorrect a. NOD(a, m) must be 1, where m = 32. Also a can't be less than 1 and greater than m-1.");
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
	printf("Enter coefficient b for encrypting with formula (a*letter + b) mod m: ");
	scanf("%i", &b);
	while (b < 0 || b >= M)
	{
		printf("Incorrect b: it can't be less than 0 and greater than m-1.");
		scanf("%i", &b);
	}
	return b;
}