#pragma once

#define NAME_LENGTH 30
#define NUMBER_LENGTH 30
#define PHONEBOOK_LENGTH 100

//Структура контакта в телефонном справочнике, имеет два поля: имя и номер телефона
struct Contact
{
	char name[NAME_LENGTH];
	char phoneNumber[NUMBER_LENGTH];
};

//Читает данные из файла и заносит их в телефонный справочник
void readFile(struct Contact array[], const char fileName[], int* currentIndex);

//Сохраняет данные из телефонного справочника в файл
void saveFile(struct Contact array[], const char fileName[], const int lasIndex);

//Добавляет контакт в телефонный справочник
void addContact(struct Contact array[], int* currentIndex, const char name[], const char number[]);

//Выводит в консоль все контакты из телефонного справочника
void writePhoneBook(struct Contact array[], const int lastIndex);

//Ищет имя в телефонном справочнике по номеру телефона, возвращает индекс элемента массива с указанным номером телефона
int nameSearch(struct Contact array[], const int lastIndex, const char number[]);

//Ищет номер телефона в телефонном справочнике по имени, возвращает индекс элемента массива с указанынм именем
int phoneNumberSearch(struct Contact array[], const int lastIndex, const char name[]);