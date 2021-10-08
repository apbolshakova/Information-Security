#include "Header.h"

void parseTextIntoWords(cryptogram_t* data)
{
	char* sav = data->text;
	while (*data->text && !isLetter(*data->text)) data->text++;
	if (isLetter(*data->text)) addWordToList(data);
	while (*data->text)
	{
		while (*data->text && !isLetter(*data->text)) data->text++;
		if (isLetter(*data->text)) addWordToList(data);
	}
	data->text = sav;
}

void addWordToList(cryptogram_t* data)
{
	words_list_item_t* newWord = (words_list_item_t*)malloc(sizeof(words_list_item_t));
	if (newWord == NULL) return;
	handleWordData(newWord, data);
	if (wordIsUnique(newWord, data->wordListHead))
	{
		newWord->next = data->wordListHead;
		data->wordListHead = newWord;
	}
}

void handleWordData(words_list_item_t* newWord, cryptogram_t* data)
{
	char* textSav = data->text;
	newWord->len = 0;
	while (isLetter(*data->text))
	{
		newWord->len++;
		data->text++;
	}
	newWord->chars = (char*)malloc(newWord->len * sizeof(char) + 1);
	data->text = textSav;
	char* charsSav = newWord->chars;
	while (isLetter(*data->text))
	{
		*(newWord->chars) = *data->text;
		data->text++;
		newWord->chars++;
	}
	*(newWord->chars) = '\0';
	newWord->chars = charsSav;
}

words_list_item_t* sortWordsByLen(words_list_item_t* firstWord)
{
	words_list_item_t* newfirstWord = NULL;
	while (firstWord != NULL)
	{
		words_list_item_t* item = firstWord;
		firstWord = firstWord->next;

		if (newfirstWord == NULL || item->len < newfirstWord->len)
		{
			item->next = newfirstWord;
			newfirstWord = item;
		}
		else
		{
			words_list_item_t* current = newfirstWord;
			while (current->next != NULL && !(item->len < current->next->len))
			{
				current = current->next;
			}
			item->next = current->next;
			current->next = item;
		}
	}
	return newfirstWord;
}

void printWords(cryptogram_t* data)
{
	system("cls");

	words_list_item_t* word = data->wordListHead;
	int prevValue = word->len;
	printf("По %i:\n", prevValue);
	printDecodedWord(word->chars, data);

	word = word->next;
	while (word != NULL)
	{
		int nextValue = word->len;

		if (nextValue != prevValue) printf("\nПо %i:\n", nextValue);
		printDecodedWord(word->chars, data);

		word = word->next;
		prevValue = nextValue;
	}
}

void printDecodedWord(char* ptr, cryptogram_t* data)
{
	while (*ptr)
	{
		printf("%c", getDecodedLetter(*ptr, data->decodeDictionary));
		ptr++;
	}
	printf("\n");
}

void cleanWordsList(cryptogram_t* data)
{
	words_list_item_t* prev = NULL;
	while (data->wordListHead->next) {
		prev = data->wordListHead;
		data->wordListHead = data->wordListHead->next;
		free(prev);
	}
	free(data->wordListHead);
}

bool_t wordIsUnique(words_list_item_t* newWord, words_list_item_t* head)
{
	words_list_item_t* item = head;
	bool_t isUnique = TRUE;
	while (item != NULL && isUnique)
	{
		if (item->len == newWord->len &&
			areSameWords(item->chars, newWord->chars)) isUnique = FALSE;
		item = item->next;
	}
	return isUnique;
}

bool_t areSameWords(char* a, char* b)
{
	bool_t areSame = TRUE;
	while (*a && *b)
	{
		if (*a != *b)
		{
			areSame = FALSE;
			break;
		}
		++a;
		++b;
	}
	if (*a || *b) areSame = FALSE; //должны были закончиться одновременно
	return areSame;
}