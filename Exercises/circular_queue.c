#include <stdio.h>

#define MAX_LENGTH 5    // Max Length of an array
#define DEBUG 0         // Debug Mode (set to 0 to disable debug messages)

typedef struct ArrList {
    int list[MAX_LENGTH];
    int next_index;
    int size;
} QUEUE;

// Creates a new Queue
QUEUE newQueue();

// Enqueues the item to the end of the queue
int enqueue(QUEUE *queue, int item);
// Dequeues the first item of the queue
int dequeue(QUEUE *queue);

// Prints the entire queue
void printList(QUEUE queue);

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main() {
    QUEUE list = newQueue();
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
    printf("\nNext Index: %d", list.next_index);
}

// ~~ QUEUE CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Creates a new Queue
QUEUE newQueue() {
    QUEUE list;
    list.next_index = 0;
    list.size = 0;

    return list;
}

// ~~ QUEUE FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Enqueues the item to the end of the queue
int enqueue(QUEUE *queue, int item) {
    if (queue->size < MAX_LENGTH) {
        queue->list[queue->next_index] = item;
        queue->next_index = ++queue->next_index % MAX_LENGTH;
        queue->size++;
        if (DEBUG)
            printf("Added <%d> sucessfully. \n", item); // Debug Message
        return 1;   // Returns 1 on sucess
    }
    else {
        if (DEBUG)
            printf("Queue is full. \n");                // Debug Message
        return 0;   // Returns 0 on failure
    }
}

// Dequeues the first item of the queue
int dequeue(QUEUE *queue) {
    int d_item = -1; // Container for dequeued item
    int d_index;    // Index for the dequeued item

    if (queue->size > 0) {
        // Gets index of first element in the circular array
        d_index = (queue->next_index + MAX_LENGTH - queue->size) % MAX_LENGTH;
        d_item = queue->list[d_index];
        queue->size--;
        if (DEBUG) {
            printf("Dequeued <%d>. \n", d_item);        // Debug Message
        }
    }
    else {
        if (DEBUG) {
            printf("Nothing to Dequeue. \n");           // Debug messages
        }
    }

    // Returns dequeued item, else returns -1 by default
    return d_item;
}

// Prints the entire queue
void printList(QUEUE queue) {
    // Index of the first element
    int head_index = (queue.next_index + MAX_LENGTH - queue.size) % MAX_LENGTH;
    // Index of the last element
    int tail_index = (queue.next_index + MAX_LENGTH - 1) % MAX_LENGTH;

    printf("List(");

    if (queue.size > 0) {
        for (int i = 0; i < queue.size; i++) {
            printf(" [%d] => %d", i, queue.list[(head_index + i) % MAX_LENGTH]);

            // Checks for next item, puts comma if so
            if (i + 1 < queue.size) {
                printf(",");
            }
        }
    }

    printf(" )\n");

    printf("\tHead: [%d] => %d \n", head_index, queue.list[head_index]);   // Prints the true index of head
    printf("\tTail: [%d] => %d \n", tail_index, queue.list[tail_index]);   // Prints the true index of tail
}