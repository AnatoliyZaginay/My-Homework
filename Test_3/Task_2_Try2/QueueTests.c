#include "QueueTests.h"

#include "Queue.h"
#include <stdlib.h>

bool deleteQueueTest(void)
{
	struct Queue* queue = createQueue();
	bool result = queue != NULL;
	deleteQueue(&queue);
	return result && queue == NULL;
}

bool isEmptyTest(void)
{
	struct Queue* queue = createQueue();
	bool result = isEmpty(queue);
	deleteQueue(&queue);
	return result;
}

bool enqueueTest(void)
{
	struct Queue* queue = createQueue();
	enqueue(queue, 1, 1);
	bool result = !isEmpty(queue);
	deleteQueue(&queue);
	return result;
}

bool dequeueTest(void)
{
	struct Queue* queue = createQueue();
	enqueue(queue, 1, 1);
	bool result = dequeue(queue) == 1 && dequeue(queue) == -1;
	deleteQueue(&queue);
	return result;
}

bool priorityTest(void)
{
	struct Queue* queue = createQueue();
	enqueue(queue, 1, 1);
	enqueue(queue, 2, 2);
	enqueue(queue, 3, 3);
	enqueue(queue, 0, 1);
	enqueue(queue, 4, 2);
	bool result = dequeue(queue) == 3 && dequeue(queue) == 2 && dequeue(queue) == 4 &&
		dequeue(queue) == 1 && dequeue(queue) == 0 && dequeue(queue) == -1;
	deleteQueue(&queue);
	return result;
}

bool queueTests(void)
{
	return deleteQueueTest() && isEmptyTest() && enqueueTest() && dequeueTest() && priorityTest();
}