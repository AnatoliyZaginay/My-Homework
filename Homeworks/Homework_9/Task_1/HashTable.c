#include "HashTable.h"

#include "List.h"
#include <stdlib.h>

#define DEFAULT_SIZE 4

struct Bucket
{
	struct List* list;
	int listLength;
};

struct HashTable
{
	int size;
	int countOfElements;
	float fillFactor;
	struct Bucket** buckets;
};

void deleteHashTable(struct HashTable** hashTable)
{
	if ((*hashTable)->buckets != NULL)
	{
		for (int i = 0; i < (*hashTable)->size; ++i)
		{
			if ((*hashTable)->buckets[i] != NULL)
			{
				if ((*hashTable)->buckets[i]->list != NULL)
				{
					deleteList(&((*hashTable)->buckets[i]->list));
				}
				free((*hashTable)->buckets[i]);
			}
		}
		free((*hashTable)->buckets);
	}
	free(*hashTable);
	*hashTable = NULL;
}

bool createBuckets(struct HashTable* hashTable)
{
	struct Bucket** buckets = malloc(sizeof(struct Bucket*) * hashTable->size);
	if (buckets == NULL)
	{
		return false;
	}
	for (int i = 0; i < hashTable->size; ++i)
	{
		buckets[i] = malloc(sizeof(struct Bucket));
		if (buckets[i] == NULL)
		{
			return false;
		}
		buckets[i]->list = createList();
		if (buckets[i]->list == NULL)
		{
			return false;
		}
		buckets[i]->listLength = 0;
	}
	hashTable->buckets = buckets;
	return true;
}

struct HashTable* createHashTable(void)
{
	struct HashTable* newHashTable = malloc(sizeof(struct HashTable));
	if (newHashTable == NULL)
	{
		return NULL;
	}
	newHashTable->size = DEFAULT_SIZE;
	newHashTable->countOfElements = 0;
	newHashTable->fillFactor = 0;
	newHashTable->buckets = NULL;
	if (!createBuckets(newHashTable))
	{
		deleteHashTable(&newHashTable);
	}
	return newHashTable;
}

int hashFunction(char* value, int hashSize)
{
	unsigned int result = 0;
	for (int i = 0; value[i] != '\0'; ++i)
	{
		result = (result + value[i]) % hashSize;
	}
	return result;
}

void addElementToHashTable(struct HashTable* hashTable, char* value, const int count)
{
	const unsigned int hash = hashFunction(value, hashTable->size);
	if (checkValue(hashTable->buckets[hash]->list, value))
	{
		updateCount(hashTable->buckets[hash]->list, value);
	}
	else
	{
		addElementToList(hashTable->buckets[hash]->list, value, count);
		++(hashTable->buckets[hash]->listLength);
		++(hashTable->countOfElements);
		hashTable->fillFactor = (float)hashTable->countOfElements / hashTable->size;
	}
}

struct List* listOfOldElements(struct HashTable* hashTable)
{
	struct List* list = createList();
	for (int i = 0; i < hashTable->size; ++i)
	{
		while (!isEmpty(hashTable->buckets[i]->list))
		{
			char* value = getValueFromHead(hashTable->buckets[i]->list);
			int count = getCountFromHead(hashTable->buckets[i]->list);
			deleteHead(hashTable->buckets[i]->list);
			addElementToList(list, value, count);
			free(value);
		}
	}
	return list;
}

void updateHashTableSize(struct HashTable* hashTable)
{
	struct List* saver = listOfOldElements(hashTable);
	for (int i = 0; i < hashTable->size; ++i)
	{
		deleteList(&(hashTable->buckets[i]->list));
		free(hashTable->buckets[i]);
	}
	free(hashTable->buckets);
	hashTable->size *= 2;
	hashTable->countOfElements = 0;
	if (!createBuckets(hashTable))
	{
		deleteHashTable(&hashTable);
	}
	while (!isEmpty(saver))
	{
		char* value = getValueFromHead(saver);
		int count = getCountFromHead(saver);
		deleteHead(saver);
		addElementToHashTable(hashTable, value, count);
		free(value);
	}
	deleteList(&saver);
}

void add(struct HashTable* hashTable, char* value)
{
	addElementToHashTable(hashTable, value, 1);
	if (hashTable->fillFactor > 1)
	{
		updateHashTableSize(hashTable);
	}
}

void printHashTable(struct HashTable* hashTable)
{
	for (int i = 0; i < hashTable->size; ++i)
	{
		if (hashTable->buckets[i]->list != NULL)
		{
			printList(hashTable->buckets[i]->list);
		}
	}
}

float getFillFactor(struct HashTable* hashTable)
{
	return hashTable->fillFactor;
}

int getMaxListLength(struct HashTable* hashTable)
{
	int maxLength = 0;
	for (int i = 0; i < hashTable->size; ++i)
	{
		if (hashTable->buckets[i]->listLength > maxLength)
		{
			maxLength = hashTable->buckets[i]->listLength;
		}
	}
	return maxLength;
}

float getAverageListLength(struct HashTable* hashTable)
{
	if (hashTable->countOfElements == 0)
	{
		return 0;
	}
	int sumOfLengths = 0;
	for (int i = 0; i < hashTable->size; ++i)
	{
		sumOfLengths += hashTable->buckets[i]->listLength;
	}
	const float averageListLength = (float)sumOfLengths / hashTable->size;
	return averageListLength;
}

bool isHashTableEmpty(struct HashTable* hashTable)
{
	return hashTable->countOfElements == 0;
}

bool checkValueInHashTable(struct HashTable* hashTable, char* value)
{
	for (int i = 0; i < hashTable->size; ++i)
	{
		if (checkValue(hashTable->buckets[i]->list, value))
		{
			return true;
		}
	}
	return false;
}