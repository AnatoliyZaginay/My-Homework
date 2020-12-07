#include "Dictionary.h"

#include <stdlib.h>
#include <string.h>

struct DictionaryElement
{
	int key;
	char* value;
	struct DictionaryElement* left;
	struct DictionaryElement* right;
};

struct Dictionary
{
	struct DictionaryElement* root;
};

struct Dictionary* createDictionary(void)
{
	struct Dictionary* newDictionary = malloc(sizeof(struct Dictionary));
	if (newDictionary != NULL)
	{
		newDictionary->root = NULL;
	}
	return newDictionary;
}

void addElement(struct Dictionary* dictionary, int key, char* value)
{
	struct DictionaryElement* currentElement = dictionary->root;
	while (currentElement != NULL)
	{
		if (currentElement->key == key)
		{
			strcpy(currentElement->value, value);
			return;
		}
		if (key < currentElement->key)
		{
			if (currentElement->left == NULL)
			{
				break;
			}
			currentElement = currentElement->left;
			continue;
		}
		if (currentElement->right == NULL)
		{
			break;
		}
		currentElement = currentElement->right;
	}
	struct DictionaryElement* newElement = malloc(sizeof(struct DictionaryElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->key = key;
	newElement->value = malloc(strlen(value) + 1);
	if (newElement->value != NULL)
	{
		strcpy(newElement->value, value);
	}
	newElement->left = NULL;
	newElement->right = NULL;
	if (dictionary->root == NULL)
	{
		dictionary->root = newElement;
		return;
	}
	if (key < currentElement->key)
	{
		currentElement->left = newElement;
		return;
	}
	currentElement->right = newElement;
}

bool isEmpty(struct Dictionary* dictionary)
{
	return dictionary->root == NULL;
}

char* getValue(struct Dictionary* dictionary, int key)
{
	struct DictionaryElement* currentElement = dictionary->root;
	while (currentElement != NULL)
	{
		if (currentElement->key == key)
		{
			return currentElement->value;
		}
		if (key < currentElement->key)
		{
			currentElement = currentElement->left;
			continue;
		}
		currentElement = currentElement->right;
	}
	return NULL;
}

bool checkKey(struct Dictionary* dictionary, int key)
{
	return getValue(dictionary, key) != NULL;
}

void deleteLeaf(struct Dictionary* dictionary, struct DictionaryElement* leaf, struct DictionaryElement* previousElement)
{
	if (previousElement == NULL)
	{
		dictionary->root = NULL;
		free(leaf->value);
		free(leaf);
		return;
	}
	if (previousElement->left == leaf)
	{
		previousElement->left = NULL;
	}
	else
	{
		previousElement->right = NULL;
	}
	free(leaf->value);
	free(leaf);
}

void deleteRootWithOneBranch(struct Dictionary* dictionary, struct DictionaryElement* root, struct DictionaryElement* previousElement)
{
	if (root->right != NULL)
	{
		if (previousElement == NULL)
		{
			dictionary->root = root->right;
			free(root->value);
			free(root);
			return;
		}
		if (previousElement->left == root)
		{
			previousElement->left = root->right;
		}
		else
		{
			previousElement->right = root->right;
		}
		free(root->value);
		free(root);
		return;
	}
	if (previousElement == NULL)
	{
		dictionary->root = root->left;
		free(root->value);
		free(root);
		return;
	}
	if (previousElement->left == root)
	{
		previousElement->left = root->left;
	}
	else
	{
		previousElement->right = root->left;
	}
	free(root->value);
	free(root);
}

bool deleteElement(struct Dictionary* dictionary, int key)
{
	if (!checkKey(dictionary, key))
	{
		return false;
	}
	struct DictionaryElement* currentElement = dictionary->root;
	struct DictionaryElement* previousElement = NULL;
	while (currentElement->key != key)
	{
		if (key < currentElement->key)
		{
			previousElement = currentElement;
			currentElement = currentElement->left;
			continue;
		}
		previousElement = currentElement;
		currentElement = currentElement->right;
	}
	if (currentElement->left == NULL && currentElement->right == NULL)
	{
		deleteLeaf(dictionary, currentElement, previousElement);
		return true;
	}
	if (currentElement->left == NULL || currentElement->right == NULL)
	{
		deleteRootWithOneBranch(dictionary, currentElement, previousElement);
		return true;
	}
	struct DictionaryElement* minimumRightElement = currentElement->right;
	while (minimumRightElement->left != NULL)
	{
		minimumRightElement = minimumRightElement->left;
	}
	int newKey = minimumRightElement->key;
	char* newValue = malloc(strlen(minimumRightElement->value) + 1);
	if (newValue != NULL)
	{
		strcpy(newValue, minimumRightElement->value);
	}
	deleteElement(dictionary, minimumRightElement->key);
	currentElement->key = newKey;
	free(currentElement->value);
	currentElement->value = newValue;
	return true;
}

void deleteDictionary(struct Dictionary** dictionary)
{
	while ((*dictionary)->root != NULL)
	{
		deleteElement(*dictionary, (*dictionary)->root->key);
	}
	free(*dictionary);
	*dictionary = NULL;
}