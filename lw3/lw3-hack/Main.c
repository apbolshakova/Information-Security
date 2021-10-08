#include "Header.h"

int main(void)
{
	setlocale(LC_ALL, "rus");
	cryptogram_t* data = NULL;

	FILE* fSrc;
	printf("Enter name of file with source code (up to 255 characters):\n");
	char* srcFileName = getFileName();
	
	if (!srcFileName)
	{
		printf("ERROR: unable to get file name.\n");
		return FAIL;
	}
	
	data = initCryptogram(fSrc);

	// Цикл пока a и b корректные:
	//     Для каждого из самых длинных 20 слов:
	//         Заменить буквы по текущим (a, b)
	//         Проверить, есть ли такое слово в словаре
	//     Если найдено 10+ слов, то выводим пользователю текст с заменами и вопрос, нужно ли продолжать перебор
	//         Если пользователь говорит, что не нужно, то спрашиваем куда сохранить результат и сохраняем разобранную криптограмму
	//     Иначе 
	//		   Установить следующие подходящие (a, b)
	//         Обновить словарь замены 
	fclose(fSrc);
	return 0;
}

char* getFileName()
{
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName)
	{
		printf("ERROR: memory allocation problem.\n");
		return NULL;
	}
	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}