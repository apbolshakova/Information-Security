#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 256
#define LEN_CODE "%255s"
#define M 32

typedef enum Status_ { FAIL, SUCCESS } status_t;
typedef enum Bool_ { FALSE_, TRUE_ } bool_t;
typedef enum Mode_ { ENCRYPT_, DECRYPT_ } mode_t;

char* getSrcFileName();
char* getResFileName();
int getA();
int getNOD(int n1, int n2);
int getB();

long int getFileSize(FILE* f);
bool_t isRussianCapitalLetter(char item);
bool_t isRussianLowercaseLetter(char item);

status_t handleEncryption(FILE* fSrc, FILE* fRes, int a, int b);
void encodeDataFromString(FILE* fRes, char* str, int a, int b);

status_t handleDecryption(FILE* fSrc, FILE* fRes, int a, int b);
int* getDecodeDictionary(int a, int b);
void decodeDataFromString(FILE* fRes, char* str, int decodeDictionary[M]);