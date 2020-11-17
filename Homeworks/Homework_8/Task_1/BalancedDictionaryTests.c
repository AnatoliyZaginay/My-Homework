#include "BalancedDictionaryTests.h";

#include "BalancedDictionary.h"
#include <stdlib.h>
#include <string.h>

bool deleteDictionaryTest(void)
{
	struct Dictionary* dictionary = createDictionary();
	deleteDictionary(&dictionary);
	return dictionary == NULL;
}

bool isEmptyTest(void)
{
	struct Dictionary* dictionary = createDictionary();
	bool result = isEmpty(dictionary);
	deleteDictionary(&dictionary);
	return result;
}

bool addElementTest(void)
{
	struct Dictionary* dictionary = createDictionary();
	addElement(dictionary, 5, "test");
	bool result = !isEmpty(dictionary);
	deleteDictionary(&dictionary);
	return result;
}

bool checkKeyTest(void)
{
	struct Dictionary* dictionary = createDictionary();
	addElement(dictionary, 5, "test1");
	addElement(dictionary, 2, "test2");
	addElement(dictionary, 6, "test3");
	addElement(dictionary, 3, "test4");
	bool result = checkKey(dictionary, 2) && checkKey(dictionary, 3) && checkKey(dictionary, 5) && checkKey(dictionary, 6);
	deleteDictionary(&dictionary);
	return result;
}

bool getValueTest(void)
{
	struct Dictionary* dictionary = createDictionary();
	addElement(dictionary, 5, "test1");
	addElement(dictionary, 2, "test2");
	addElement(dictionary, 6, "test3");
	addElement(dictionary, 3, "test4");
	bool result = strcmp(getValue(dictionary, 2), "test2") == 0 && strcmp(getValue(dictionary, 3), "test4") == 0 &&
		strcmp(getValue(dictionary, 5), "test1") == 0 && strcmp(getValue(dictionary, 6), "test3") == 0;
	deleteDictionary(&dictionary);
	return result;
}

bool deleteElementTest(void)
{
	struct Dictionary* dictionary = createDictionary();
	addElement(dictionary, 5, "test1");
	addElement(dictionary, 2, "test2");
	addElement(dictionary, 6, "test3");
	addElement(dictionary, 3, "test4");
	bool result = !deleteElement(dictionary, 1) && deleteElement(dictionary, 3) && !checkKey(dictionary, 3) &&
		deleteElement(dictionary, 5) && !checkKey(dictionary, 5) && deleteElement(dictionary, 6) &&
		!checkKey(dictionary, 6) && deleteElement(dictionary, 2) && !checkKey(dictionary, 2) &&
		isEmpty(dictionary);
	deleteDictionary(&dictionary);
	return result;
}

bool dictionaryBalanceTest(void)
{
	struct Dictionary* dictionary = createDictionary();
	bool result = dictionaryBalance(dictionary);
	addElement(dictionary, 5, "test");
	result = result && dictionaryBalance(dictionary);
	addElement(dictionary, 6, "test");
	result = result && dictionaryBalance(dictionary);
	addElement(dictionary, 7, "test");
	result = result && dictionaryBalance(dictionary);
	addElement(dictionary, 4, "test");
	result = result && dictionaryBalance(dictionary);
	addElement(dictionary, 3, "test");
	result = result && dictionaryBalance(dictionary);
	deleteElement(dictionary, 5);
	result = result && dictionaryBalance(dictionary);
	deleteElement(dictionary, 7);
	result = result && dictionaryBalance(dictionary);
	deleteDictionary(&dictionary);
	return result;
}

bool dictionaryTests(void)
{
	return deleteDictionaryTest() && isEmptyTest() && addElementTest() && checkKeyTest() && getValueTest() && deleteElementTest() &&
		dictionaryBalanceTest();
}