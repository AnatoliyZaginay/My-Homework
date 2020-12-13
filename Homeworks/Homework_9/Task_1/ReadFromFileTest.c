#include "ReadFromFileTest.h"

#include "ReadFromFile.h"
#include "HashTable.h"

bool readFromFileTest(void)
{
	struct HashTable* hashTable = createHashTable();
	bool result = !readFromFile(hashTable, "wrong_name.txt") && readFromFile(hashTable, "test.txt") &&
		checkValueInHashTable(hashTable, "Useful") && checkValueInHashTable(hashTable, "test") &&
		checkValueInHashTable(hashTable, "-") && checkValueInHashTable(hashTable, "failed");
	deleteHashTable(&hashTable);
	return result;
}