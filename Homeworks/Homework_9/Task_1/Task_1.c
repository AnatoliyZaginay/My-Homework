#include "ReadFromFile.h"
#include "HashTable.h"

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
	struct HashTable* hashTable = createHashTable();
	readFromFile(hashTable, "text.txt");
	printHashTable(hashTable);
	printf("%i\n", getMaxListLength(hashTable));
	printf("%f\n", getAverageListLength(hashTable));
	printf("%f\n", getFillFactor(hashTable));
	deleteHashTable(&hashTable);
}