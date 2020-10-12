#include "phoneBookOperations.h"
#include "phoneBookOperationsTests.h"
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define FILE_NAME "phoneBook.txt"

void operations(void)
{
	printf("Операции:\n");
	printf("0 - выйти\n");
	printf("1 - добавить контакт\n");
	printf("2 - распечатать все имеющиеся контакты\n");
	printf("3 - найти номер телефона по имени\n");
	printf("4 - найти имя по номеру телефона\n");
	printf("5 - сохранить текущие данные в файл\n\n");
}

bool testsResult(void)
{
	return testAddContact() && testPhoneNumberSearch() && testNameSearch() && testReadFile() && testSaveFile();
}

void main(void)
{
	if (!testsResult())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	int currentIndex = 0;
	struct Contact phoneBook[PHONEBOOK_LENGTH];
	readFile(phoneBook, FILE_NAME, &currentIndex);
	operations();
	int operationNumber = 0;
	printf("Введите номер операции: ");
	scanf("%i", &operationNumber);
	while (operationNumber != 0)
	{
		switch (operationNumber)
		{
		case 0:
			break;
		case 1:
		{
			char name[NAME_LENGTH];
			char phoneNumber[NUMBER_LENGTH];
			printf("Введите имя: ");
			scanf("%s", &name);
			printf("Введите номер телефона: ");
			scanf("%s", &phoneNumber);
			addContact(phoneBook, &currentIndex, name, phoneNumber);
			printf("Контакт сохранен\n\n");
			break;
		}
		case 2:
			writePhoneBook(phoneBook, currentIndex);
			printf("\n");
			break;
		case 3:
		{
			char name[NAME_LENGTH];
			printf("Введите имя: ");
			scanf("%s", &name);
			int index = phoneNumberSearch(phoneBook, currentIndex, name);
			if (index < 0)
			{
				printf("Введённое имя не найдено в телефонном справочнике\n\n");
				break;
			}
			printf("По введённому имени был найден следующий номер телефона: %s\n\n", phoneBook[index].phoneNumber);
			break;
		}
		case 4:
		{
			char phoneNumber[NUMBER_LENGTH];
			printf("Введите номер телефона: ");
			scanf("%s", &phoneNumber);
			int index = nameSearch(phoneBook, currentIndex, phoneNumber);
			if (index < 0)
			{
				printf("Введённый номер телефона не найден в телефонном справочнике\n\n");
				break;
			}
			printf("По введённому номеру телефона было найдено следующее имя: %s\n\n", phoneBook[index].name);
			break;
		}
		case 5:
			saveFile(phoneBook, FILE_NAME, currentIndex);
			printf("Телефонный справочник сохранён в файл \"%s\"\n\n", FILE_NAME);
			break;
		default:
			printf("Введите корректный номер операции (0 - 5)\n\n");
			break;
		}
		operations();
		printf("Введите номер операции: ");
		scanf("%i", &operationNumber);
	}
	printf("Программа завершена");
}