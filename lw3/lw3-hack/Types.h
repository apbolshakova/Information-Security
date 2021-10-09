#ifndef TYPES
#define TYPES

typedef enum Bool_ {
	FALSE_,
	TRUE_
} bool_t;

typedef struct WordListItem_ {
	char* chars;
	int len;
	struct WordListItem_* next;
} words_list_item_t;

typedef struct Cryptogram_ {
	char* text;
	words_list_item_t* wordListHead;
	int aCoefficient;
	int bCoefficient;
	int* decodeDictionary;
} cryptogram_t;

#endif