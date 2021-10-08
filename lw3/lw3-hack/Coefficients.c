#include "Header.h"

void setNextA(cryptogram_t* data)
{
	int newA = data->aCoefficient++;
	if (newA < 1 || newA >= ALPHABET_SIZE || getNOD(newA, ALPHABET_SIZE) != 1)
	{
		data->aCoefficient = END_OF_OPTIONS;
	}
	else {
		data->aCoefficient = newA;
	}
}

void setNextB(cryptogram_t* data)
{
	int newB = data->bCoefficient++;
	if (newB < 0 || newB >= ALPHABET_SIZE)
	{
		data->bCoefficient = END_OF_OPTIONS;
	}
	else {
		data->bCoefficient = newB;
	}
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

void printEncryptionKey(cryptogram_t* data)
{
	printf("Текущий ключ шифрования: a = %i, b = %i\n\n", data->aCoefficient, data->bCoefficient);
}