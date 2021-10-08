#include "Header.h"

long int getFileSize(FILE* f)
{
	long int sav = ftell(f);
	fseek(f, 0L, SEEK_END);
	long int fileSize = ftell(f);
	fseek(f, sav, SEEK_SET);
	return(fileSize);
}

bool_t isRussianCapitalLetter(char item)
{
	if ('À' <= item && item <= 'ß') return TRUE_;
	else return FALSE_;
}

bool_t isRussianLowercaseLetter(char item)
{
	if ('à' <= item && item <= 'ÿ') return TRUE_;
	else return FALSE_;
}