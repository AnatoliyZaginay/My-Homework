#include "HashTableTests.h"

#include "HashTable.h"
#include <stdlib.h>

bool deleteHashTableTest(void)
{
	struct HashTable* hashTable = createHashTable();
	deleteHashTable(&hashTable);
	return hashTable == NULL;
}

bool isHashTableEmptyTest(void)
{
	struct HashTable* hashTable = createHashTable();
	bool result = isHashTableEmpty(hashTable);
	deleteHashTable(&hashTable);
	return result;
}

bool addTest(void)
{
	struct HashTable* hashTable = createHashTable();
	add(hashTable, "test");
	bool result = !isHashTableEmpty(hashTable);
	deleteHashTable(&hashTable);
	return result;
}

bool checkValueInHashTableTest(void)
{
	struct HashTable* hashTable = createHashTable();
	add(hashTable, "test1");
	add(hashTable, "test2");
	add(hashTable, "test3");
	bool result = checkValueInHashTable(hashTable, "test1") && checkValueInHashTable(hashTable, "test2") &&
		checkValueInHashTable(hashTable, "test3") && !checkValueInHashTable(hashTable, "test4");
	deleteHashTable(&hashTable);
	return result;
}

bool getFillFactorTest(void)
{
	struct HashTable* hashTable = createHashTable();
	bool result = getFillFactor(hashTable) == 0;
	add(hashTable, "test1");
	result = result && getFillFactor(hashTable) == 0.25;
	add(hashTable, "test2");
	result = result && getFillFactor(hashTable) == 0.5;
	deleteHashTable(&hashTable);
	return result;
}

bool getMaxListLengthTest(void)
{
	struct HashTable* hashTable = createHashTable();
	bool result = getMaxListLength(hashTable) == 0;
	add(hashTable, "test1");
	result = result && getMaxListLength(hashTable) == 1;
	add(hashTable, "test5");
	result = result && getMaxListLength(hashTable) == 2;
	deleteHashTable(&hashTable);
	return result;
}

bool getAverageListLengthTest(void)
{
	struct HashTable* hashTable = createHashTable();
	bool result = getAverageListLength(hashTable) == 0;
	add(hashTable, "test1");
	result = result && getAverageListLength(hashTable) == 0.25;
	add(hashTable, "test5");
	result = result && getAverageListLength(hashTable) == 0.5;
	deleteHashTable(&hashTable);
	return result;
}

bool updateHashTableSizeTest(void)
{
	struct HashTable* hashTable = createHashTable();
	add(hashTable, "test1");
	add(hashTable, "test2");
	add(hashTable, "test3");
	add(hashTable, "test4");
	bool result = getFillFactor(hashTable) == 1;
	add(hashTable, "test5");
	result = result && getFillFactor(hashTable) < 1;
	add(hashTable, "test6");
	result = result && checkValueInHashTable(hashTable, "test1") && checkValueInHashTable(hashTable, "test2") &&
		checkValueInHashTable(hashTable, "test3") && checkValueInHashTable(hashTable, "test4") &&
		checkValueInHashTable(hashTable, "test5") && checkValueInHashTable(hashTable, "test6");
	deleteHashTable(&hashTable);
	return result;
}

bool hashTableTests(void)
{
	return deleteHashTableTest() && isHashTableEmptyTest() && addTest() && checkValueInHashTableTest() &&
		getFillFactorTest() && getMaxListLengthTest() && getAverageListLengthTest() && updateHashTableSizeTest();
}