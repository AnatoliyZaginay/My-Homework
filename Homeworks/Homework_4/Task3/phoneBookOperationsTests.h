#pragma once

#include <stdbool.h>

//Тест на добавление нового контакта в телефонный справочник
bool testAddContact(void);

//Тест на поиск номера телефона по имени в телефонном справочнике
bool testPhoneNumberSearch(void);

//Тест на поиск имени по номеру телефона в телефонном справочнике
bool testNameSearch(void);

//Тест на чтение данных для телефонного справочника из файла
bool testReadFile(void);

//Тест на сохранение данных телефонного справочника в файл
bool testSaveFile(void);