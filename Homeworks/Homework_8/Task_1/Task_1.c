#include "BalancedDictionary.h"
#include "BalancedDictionaryTests.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define VALUE_LENGTH 30
#define KEY_LENGTH 30

void commands(void)
{
	printf("Комманды:\n");
	printf("0 - Выйти\n");
	printf("1 - Добавить значение по заданному ключу в словарь\n");
	printf("2 - Получить значение по заданному ключу из словаря\n");
	printf("3 - Проверить наличие заданного ключа в словаре\n");
	printf("4 - Удалить заданный ключ и связанное с ним значение из словаря\n\n");
}

void main(void)
{
	if (!dictionaryTests())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct Dictionary* dictionary = createDictionary();
	if (dictionary == NULL)
	{
		printf("Ошибка создания словаря");
		return;
	}
	int commandNumber = -1;
	while (commandNumber != 0)
	{
		commands();
		printf("Введите номер команды: ");
		scanf("%i", &commandNumber);
		char key[KEY_LENGTH] = "";
		char value[VALUE_LENGTH] = "";
		switch (commandNumber)
		{
		case 0:
			printf("Программа завершена");
			break;
		case 1:

			printf("Введите ключ: ");
			scanf("%s", &key);
			printf("Введите значение: ");
			scanf("%s", &value);
			addElement(dictionary, key, value);
			printf("Значение по введённому ключу добавлено\n");
			break;
		case 2:
			printf("Введите ключ: ");
			scanf("%s", &key);
			char* returnedValue = getValue(dictionary, key);
			if (returnedValue == NULL)
			{
				printf("Значение по введённому ключу не найдено\n");
			}
			else
			{
				printf("Значение по введённому ключу: %s\n", returnedValue);
			}
			break;
		case 3:
			printf("Введите ключ: ");
			scanf("%s", &key);
			if (checkKey(dictionary, key))
			{
				printf("Введённый ключ найден в словаре\n");
			}
			else
			{
				printf("Введённый ключ не найден в словаре\n");
			}
			break;
		case 4:
			printf("Введите ключ: ");
			scanf("%s", &key);
			if (deleteElement(dictionary, key))
			{
				printf("Введённый ключ и связанное с ним значение удалены из словаря\n");
			}
			else
			{
				printf("Введённый ключ не найден в словаре\n");
			}
			break;
		default:
			printf("Введён неверный номер команды\n");
			break;
		}
		printf("\n");
	}
	deleteDictionary(&dictionary);
}