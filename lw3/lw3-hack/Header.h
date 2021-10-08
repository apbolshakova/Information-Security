#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <malloc.h>
#include "Types.h"

#define LEN 256
#define LEN_CODE "%255s"
#define ALPHABET_SIZE 32
#define NO_LETTERS '\0'
#define END_OF_OPTIONS -1

void setNextA(cryptogram_t* data);
void setNextB(cryptogram_t* data);
int getNOD(int n1, int n2);
void printEncryptionKey(cryptogram_t* data);

cryptogram_t* initCryptogram(char* dataPath);
void printCryptogram(cryptogram_t* data);
void cleanMemory(cryptogram_t* data);

void updateDecodeDictionary(cryptogram_t* data);
char getDecodedLetter(char ch, int decodeDictionary[ALPHABET_SIZE]);

bool_t isRussianCapitalLetter(char item);
bool_t isRussianLowercaseLetter(char item);
bool_t isLetter(char item);

char* getFileName();

void initText(cryptogram_t* data, FILE* f, char* dataPath);
void saveDataFromString(cryptogram_t* data, char* str);
void printText(cryptogram_t* data);
long int getFileSize(FILE* f);

void parseTextIntoWords(cryptogram_t* data);
void addWordToList(cryptogram_t* data);
void handleWordData(words_list_item_t* newWord, cryptogram_t* data);
words_list_item_t* sortWordsByLen(words_list_item_t* firstWord);
void printWords(cryptogram_t* data);
void printDecodedWord(char* ptr, cryptogram_t* data);
void cleanWordsList(cryptogram_t* data);
bool_t wordIsUnique(words_list_item_t* newWord, words_list_item_t* head);
bool_t areSameWords(char* a, char* b);