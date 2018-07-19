#include <stdio.h>

#define MAX_LENGTH 5    // Max Length of an array
#define DEBUG 0         // Debug Mode (set to 0 to disable debug messages)

typedef struct ArrList {
    int list[MAX_LENGTH];
    int nextIndex;
    int size;
} ORDEREDLIST;

// Creates a newOrderList
ORDEREDLIST newList();

// Enqueues the item to the end of the queue
void enqueue(ORDEREDLIST *queue, int item);
// Dequeues the first item of the queue
int dequeue(ORDEREDLIST *queue);

// Prints the entire list
void printList(ORDEREDLIST *queue);

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main() {
    ORDEREDLIST list = newList();
    enqueue(&list, 5);
    enqueue(&list, 4);
    enqueue(&list, 3);
    enqueue(&list, 2);
    enqueue(&list, 1);
    enqueue(&list, 0);
    // dequeue(&list);
    enqueue(&list, 6);
    // dequeue(&list);

    // for (int i = 0; i < MAX_LENGTH; i++){
    //     printf("%d ", list.list[i]);
    // }
    printList(&list);

    printf("\nSize: %d", list.size);
    printf("\nNext Index: %d", list.nextIndex);
}

// ~~ ORDERED LIST CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Creates a newOrderList
ORDEREDLIST newList() {
    ORDEREDLIST list;
    list.nextIndex = 0;
    list.size = 0;

    return list;
}

// ~~ ORDERED LIST FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Enqueues the item to the end of the queue
void enqueue(ORDEREDLIST *queue, int item) {
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
int dequeue(ORDEREDLIST *queue) {
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
    return d_item;
}

void printList(ORDEREDLIST *queue) {
    int ptr = (queue->nextIndex + MAX_LENGTH - queue->size) % MAX_LENGTH;
    printf("List(");

    if (queue->size > 0) {
        for (int i = 0; i < queue->size; i++) {
            printf(" [%d] => %d", i, queue->list[(ptr + i) % MAX_LENGTH]);
            if (i + 1 < queue->size) {
                printf(",");
            }
        }
    }

    printf(" )\n");
}