#include "Queue.h"

#include <stdlib.h>

struct QueueElement
{
	int value;
	int priority;
	struct QueueElement* next;
};

struct Queue
{
	struct QueueElement* head;
	struct QueueElement* tail;
};

struct Queue* createQueue(void)
{
	struct Queue* newQueue = malloc(sizeof(struct Queue));
	if (newQueue == NULL)
	{
		return NULL;
	}
	newQueue->tail = NULL;
	newQueue->head = NULL;
	return newQueue;
}

bool isEmpty(struct Queue* queue)
{
	return queue->tail == NULL && queue->head == NULL;
}

void enqueue(struct Queue* queue, int value, int priority)
{
	struct QueueElement* newElement = malloc(sizeof(struct QueueElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->value = value;
	newElement->priority = priority;
	newElement->next = NULL;
	if (isEmpty(queue))
	{
		queue->tail = newElement;
		queue->head = newElement;
		return;
	}
	if (priority > queue->head->priority)
	{
		newElement->next = queue->head;
		queue->head = newElement;
		return;
	}
	struct QueueElement* currentElement = queue->head;
	while (currentElement->next != NULL && currentElement->next->priority >= priority)
	{
		currentElement = currentElement->next;
	}
	newElement->next = currentElement->next;
	if (currentElement == queue->tail)
	{
		queue->tail = newElement;
	}
	currentElement->next = newElement;
	return;
}

int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
	{
		return -1;
	}
	const int value = queue->head->value;
	struct QueueElement* deletedElement = queue->head;
	queue->head = queue->head->next;
	if (queue->head == NULL)
	{
		queue->tail = NULL;
	}
	free(deletedElement);
	return value;
}

void deleteQueue(struct Queue** queue)
{
	while (!isEmpty(*queue))
	{
		dequeue(*queue);
	}
	free(*queue);
	*queue = NULL;
}