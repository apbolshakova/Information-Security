#include "Header.h"

int main(void) {
	setlocale(LC_ALL, "rus");
	cryptogram_t* data = NULL;

	printf("Введите путь до файла с зашифрованным текстом (до 255 символов):\n");
	char* srcFileName = getFileName();

	data = initCryptogram(srcFileName);

	if (!data) {
		printf("Произошла ошибка при иниицализации. Нажмите любую кнопку для выхода.\n");
		_getch();
		return 0;
	}

	data->wordListHead = sortWordsByLen(data->wordListHead);
	printWords(data);

	handleMainCycle(data);
	cleanMemory(data);
	_getch();
	return 0;
}

char* getFileName() {
	char* fileName = (char*)calloc(LEN, sizeof(char));
	if (!fileName) {
		printf("Ошибка: проблема при выделении памяти.\n");
		return NULL;
	}
	scanf_s(LEN_CODE, fileName, LEN);
	return fileName;
}

void handleMainCycle(cryptogram_t* data) {
// Цикл пока a и b корректные:
//     Для первых 20 слов из списка:
//         Заменить буквы по текущим (a, b)
//         Проверить, есть ли такое слово в словаре
// 	           Если есть, увеличить счётчик корректных слов на единицу
//     Если найдено 10+ корректных слов, то выводим пользователю текст с заменами и вопрос, произошло ли попадание
//         Если пользователь говорит, что попали
//             Спрашиваем куда сохранить результат
//             Сохраняем разобранную криптограмму
// 	           Выводим сообщение об успехе
// 	           Выходим из цикла
//     Установить следующие подходящие (a, b)
//     Обновить словарь замены
//     Установить счётчик корректных слов в 0
// Если a или b установлено в некорректное, то выводим сообщение о неудаче
	while (data->aCoefficient != END_OF_OPTIONS && data->bCoefficient != END_OF_OPTIONS) {
		for (int i = 0; i < NUM_OF_WORD_TO_ANALIZE; i++) {
			break;
		}
		break;
	}
}