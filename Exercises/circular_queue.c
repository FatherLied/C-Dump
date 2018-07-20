#include <stdio.h>

#define MAX_LENGTH 5    // Max Length of an array
#define DEBUG 0         // Debug Mode (set to 0 to disable debug messages)

typedef struct ArrList {
	int list[MAX_LENGTH];
	int nextIndex;
	int size;
} QUEUE;

// Creates a new Queue
QUEUE newList();

// Enqueues the item to the end of the queue
void enqueue(QUEUE *queue, int item);
// Dequeues the first item of the queue
int dequeue(QUEUE *queue);

// Prints the entire list
void printList(QUEUE queue);

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main() {
	QUEUE list = newList();
	enqueue(&list, 5);
	enqueue(&list, 4);
	enqueue(&list, 3);
	enqueue(&list, 2);
	enqueue(&list, 1);
	enqueue(&list, 0);
	printList(list);
	dequeue(&list);
	printList(list);
	enqueue(&list, 6);
	printList(list);
	dequeue(&list);
	printList(list);

	printf("\nSize: %d", list.size);
	printf("\nNext Index: %d", list.nextIndex);
}

// ~~ QUEUE CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Creates a new Queue
QUEUE newList() {
	QUEUE list;
	list.nextIndex = 0;
	list.size = 0;

	return list;
}

// ~~ QUEUE FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Enqueues the item to the end of the queue
void enqueue(QUEUE *queue, int item) {
	if (queue->size < MAX_LENGTH) {
		queue->list[queue->nextIndex] = item;
		queue->nextIndex = ++queue->nextIndex % MAX_LENGTH;
		queue->size++;
		if (DEBUG)
			printf("Added <%d> sucessfully. \n", item); // Debug Message
		return;
	}
	else {
		if (DEBUG)
			printf("Queue is full. \n");                // Debug Message
		return;
	}
}

// Dequeues the first item of the queue
int dequeue(QUEUE *queue) {
	int d_item = 0; // Container for dequeued item
	int d_index;    // Index for the dequeued item

	if (queue->size > 0) {
		// Gets index of first element in the circular array
		d_index = (queue->nextIndex + MAX_LENGTH - queue->size) % MAX_LENGTH;
		d_item = queue->list[d_index];
		queue->size--;
		if (DEBUG)
			printf("Dequeued <%d>. \n", d_item);        // Debug Message
	}
	else {
		if (DEBUG)
			printf("Nothing to Dequeue. \n");           // Debug Message
	}

	// Returns 0 as default, else returns the dequeued item 
	return d_item;
}

// Prints the entire list
void printList(QUEUE queue) {
	int ptr = (queue.nextIndex + MAX_LENGTH - queue.size) % MAX_LENGTH;
	printf("List(");

	if (queue.size > 0) {
		for (int i = 0; i < queue.size; i++) {
			printf(" [%d] => %d", i, queue.list[(ptr + i) % MAX_LENGTH]);

			// Checks for next item, puts comma if so
			if (i + 1 < queue.size) {
				printf(",");
			}
		}
	}

	printf(" )\n");
}