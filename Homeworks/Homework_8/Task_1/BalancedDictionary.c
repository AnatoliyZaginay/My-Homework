#include "BalancedDictionary.h"

#include <stdlib.h>
#include <string.h>


struct DictionaryElement
{
	int height;
	char* key;
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
	return calloc(1, sizeof(struct Dictionary));
}

int getHeight(struct DictionaryElement* element)
{
	if (element == NULL)
	{
		return 0;
	}
	return element->height;
}

int getSubtreeHeight(struct DictionaryElement* element)
{
	if (element == NULL)
	{
		return 0;
	}
	return element->height + 1;
}

void updateHeight(struct DictionaryElement* element)
{
	if (element == NULL)
	{
		return;
	}
	if (element->left == NULL && element->right == NULL)
	{
		element->height = 0;
		return;
	}
	const int heightLeft = getHeight(element->left);
	const int heightRight = getHeight(element->right);
	element->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

int disbalance(struct DictionaryElement* element)
{
	if (element == NULL)
	{
		return 0;
	}
	return getSubtreeHeight(element->left) - getSubtreeHeight(element->right);
}

bool isBalanced(struct DictionaryElement* element)
{
	if (element == NULL)
	{
		return true;
	}
	const int elementDisbalance = disbalance(element);
	const bool leftChildrenBalance = isBalanced(element->left);
	const bool rightChildrenBalance = isBalanced(element->right);
	return elementDisbalance <= 1 && elementDisbalance >= -1 && leftChildrenBalance && rightChildrenBalance;
}

bool dictionaryBalance(struct Dictionary* dictionary)
{
	return isBalanced(dictionary->root);
}

struct DictionaryElement* leftRotation(struct DictionaryElement* element)
{
	struct DictionaryElement* newRoot = element->right;
	element->right = newRoot->left;
	newRoot->left = element;
	updateHeight(element);
	updateHeight(newRoot);
	return newRoot;
}

struct DictionaryElement* rightRotation(struct DictionaryElement* element)
{
	struct DictionaryElement* newRoot = element->left;
	element->left = newRoot->right;
	newRoot->right = element;
	updateHeight(element);
	updateHeight(newRoot);
	return newRoot;
}

struct DictionaryElement* bigLeftRotation(struct DictionaryElement* element)
{
	element->right = rightRotation(element->right);
	element = leftRotation(element);
	return element;
}

struct DictionaryElement* bigRightRotation(struct DictionaryElement* element)
{
	element->left = leftRotation(element->left);
	element = rightRotation(element);
	return element;
}

struct DictionaryElement* balance(struct DictionaryElement* element)
{
	updateHeight(element);
	if (disbalance(element) == -2)
	{
		if (disbalance(element->right) > 0)
		{
			return bigLeftRotation(element);
		}
		return leftRotation(element);
	}
	if (disbalance(element) == 2)
	{
		if (disbalance(element->left) < 0)
		{
			return bigRightRotation(element);
		}
		return rightRotation(element);
	}
	return element;
}

struct DictionaryElement* balanceAfterAdding(struct DictionaryElement* currentElement, struct DictionaryElement* elementToAdd)
{
	if (strcmp(currentElement->key, elementToAdd->key) == 0)
	{
		free(currentElement->value);
		currentElement->value = elementToAdd->value;
		elementToAdd->value = NULL;
		free(elementToAdd->key);
		free(elementToAdd);
		return currentElement;
	}
	if (strcmp(elementToAdd->key, currentElement->key) < 0)
	{
		if (currentElement->left == NULL)
		{
			currentElement->left = elementToAdd;
		}
		else
		{
			currentElement->left = balanceAfterAdding(currentElement->left, elementToAdd);
		}
	}
	else
	{
		if (currentElement->right == NULL)
		{
			currentElement->right = elementToAdd;
		}
		else
		{
			currentElement->right = balanceAfterAdding(currentElement->right, elementToAdd);
		}
	}
	return balance(currentElement);
}

void addElement(struct Dictionary* dictionary, char* key, char* value)
{
	struct DictionaryElement* newElement = malloc(sizeof(struct DictionaryElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->height = 0;
	newElement->key = malloc(strlen(key) + 1);
	if (newElement->key != NULL)
	{
		strcpy(newElement->key, key);
	}
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
	dictionary->root = balanceAfterAdding(dictionary->root, newElement);
}

bool isEmpty(struct Dictionary* dictionary)
{
	return dictionary->root == NULL;
}

char* getValue(struct Dictionary* dictionary, char* key)
{
	struct DictionaryElement* currentElement = dictionary->root;
	while (currentElement != NULL)
	{
		if (strcmp(currentElement->key, key) == 0)
		{
			return currentElement->value;
		}
		if (strcmp(key, currentElement->key) < 0)
		{
			currentElement = currentElement->left;
			continue;
		}
		currentElement = currentElement->right;
	}
	return NULL;
}

bool checkKey(struct Dictionary* dictionary, char* key)
{
	return getValue(dictionary, key) != NULL;
}

struct DictionaryElement* findRightMinimum(struct DictionaryElement* currentElement)
{
	if (currentElement->left == NULL)
	{
		return currentElement;
	}
	return findRightMinimum(currentElement->left);
}

struct DictionaryElement* deleteMinimum(struct DictionaryElement* currentElement)
{
	if (currentElement->left == NULL)
	{
		return currentElement->right;
	}
	currentElement->left = deleteMinimum(currentElement->left);
	return balance(currentElement);
}

struct DictionaryElement* balanceAfterDeleting(struct DictionaryElement* currentElement, char* key)
{
	if (currentElement == NULL)
	{
		return NULL;
	}
	if (strcmp(key, currentElement->key) < 0)
	{
		currentElement->left = balanceAfterDeleting(currentElement->left, key);
		return balance(currentElement);
	}
	if (strcmp(key, currentElement->key) > 0)
	{
		currentElement->right = balanceAfterDeleting(currentElement->right, key);
		return balance(currentElement);
	}
	else
	{
		struct DictionaryElement* leftChild = currentElement->left;
		struct DictionaryElement* rightChild = currentElement->right;
		free(currentElement->value);
		free(currentElement->key);
		free(currentElement);
		if (rightChild == NULL)
		{
			return leftChild;
		}
		struct DictionaryElement* rightMinimum = findRightMinimum(rightChild);
		rightMinimum->right = deleteMinimum(rightChild);
		rightMinimum->left = leftChild;
		return balance(rightMinimum);
	}
}

bool deleteElement(struct Dictionary* dictionary, char* key)
{
	if (!checkKey(dictionary, key))
	{
		return false;
	}
	dictionary->root = balanceAfterDeleting(dictionary->root, key);
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