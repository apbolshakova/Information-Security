#include "Header.h"

bool_t isRussianCapitalLetter(char item) {
	if ('À' <= item && item <= 'ß') return TRUE_;
	else return FALSE_;
}

bool_t isRussianLowercaseLetter(char item) {
	if ('à' <= item && item <= 'ÿ') return TRUE_;
	else return FALSE_;
}

bool_t isLetter(char item) {
	if ('À' <= item && item <= 'ÿ') return TRUE_;
	else return FALSE_;
}