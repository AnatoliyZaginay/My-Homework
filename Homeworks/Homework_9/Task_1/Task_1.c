#include "HashTable.h"
#include "HashTableTests.h"
#include "ListTests.h"
#include "ReadFromFile.h"
#include "ReadFromFileTest.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define FILE_NAME "text.txt"

void main(void)
{
	if (!listTests() || !hashTableTests() || !readFromFileTest())
	{
		printf("Tests failed");
		return;
	}
	setlocale(LC_ALL, "Rus");
	struct HashTable* hashTable = createHashTable();
	if (hashTable == NULL)
	{
		printf("Ошибка создания хеш-таблицы");
		return;
	}
	if (!readFromFile(hashTable, FILE_NAME))
	{
		deleteHashTable(&hashTable);
		printf("Файл не найден");
		return;
	}
	printf("Слова, встречающиеся в тексте, и их количество:\n");
	printHashTable(hashTable);
	printf("\nМаксимальная длина списка в сегменте таблицы: %i\n", getMaxListLength(hashTable));
	printf("Средняя длина списка в сегменте таблицы: %f\n", getAverageListLength(hashTable));
	printf("Коэффициент заполнения хеш-таблицы: %f\n", getFillFactor(hashTable));
	deleteHashTable(&hashTable);
}