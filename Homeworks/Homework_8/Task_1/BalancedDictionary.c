#include "BalancedDictionary.h"

#include <stdlib.h>
#include <string.h>


struct DictionaryElement
{
	int height;
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
	if (heightLeft > heightRight)
	{
		element->height = heightLeft + 1;
		return;
	}
	element->height = heightRight + 1;
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
	int elementDisbalance = disbalance(element);
	bool leftChildrenBalance = isBalanced(element->left);
	bool rightChildrenBalance = isBalanced(element->right);
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
	if (currentElement->key == elementToAdd->key)
	{
		strcpy(currentElement->value, elementToAdd->value);
		free(elementToAdd->value);
		free(elementToAdd);
		return currentElement;
	}
	if (elementToAdd->key < currentElement->key)
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

void addElement(struct Dictionary* dictionary, int key, char* value)
{
	struct DictionaryElement* newElement = malloc(sizeof(struct DictionaryElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->key = key;
	newElement->height = 0;
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

struct DictionaryElement* findRightMinimum(struct DictionaryElement* currentElement)
{
	if (currentElement->left == NULL)
	{
		return currentElement;
	}
	return findRightMinimum(currentElement->left);
}

struct DictionaryElement* deleteMinimum(struct DictionaryElement* currentElement) // удаление узла с минимальным ключом из дерева p
{
	if (currentElement->left == NULL)
		return currentElement->right;
	currentElement->left = deleteMinimum(currentElement->left);
	return balance(currentElement);
}

struct DictionaryElement* balanceAfterDeleting(struct DictionaryElement* currentElement, int key)
{
	if (currentElement == NULL)
	{
		return NULL;
	}
	if (key < currentElement->key)
	{
		currentElement->left = balanceAfterDeleting(currentElement->left, key);
		return balance(currentElement);
	}
	if (key > currentElement->key)
	{
		currentElement->right = balanceAfterDeleting(currentElement->right, key);
		return balance(currentElement);
	}
	else
	{
		struct DictionaryElement* leftChild = currentElement->left;
		struct DictionaryElement* rightChild = currentElement->right;
		free(currentElement->value);
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

bool deleteElement(struct Dictionary* dictionary, int key)
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