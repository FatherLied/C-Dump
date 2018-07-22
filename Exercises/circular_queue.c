#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_LENGTH 5    // Max Length of an array
#define DEBUG 1         // Debug Mode (set to 0 to disable debug messages)

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

int is_numeric(char *str);          // Checks if string is numeric
void input_loop(QUEUE *queue, char mode);      // Input loop

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main() {
    char selection = '\0';
    int selection_is_valid = 1;
    int input_is_valid = 1;

    QUEUE list = newQueue();

    do {
        system("cls");
        printf("CIRCULAR QUEUE\n\n");
        printf("\t<1> Enqueue item.\n");
        printf("\t<2> Dequeue item.\n\n");
        printf("\t<0> Exit.\n\n");

        if (!selection_is_valid){
            printf("\tInvalid choice. Valid keys are labeled with <>.");
        } else {
            printf("\tSelect option in <>.");
        }
        printf("\n\n\t");
        printList(list);

        selection = getch();

        selection_is_valid = 1;
        switch (selection) {
            case '1':
                input_loop(&list, 'e');
                break;
            case '2':
                input_loop(&list, 'd');
                break;
            case '0':
                break;
            default:
                selection_is_valid = 0;
        }
    } while (selection != '0');

    return 0;
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

    // Shows true index of the head, based on circular array
    printf("\tHead: True index is [%d] \n", head_index);
    // Shows true index of the tail, based on circular array
    printf("\tTail: True index is [%d] \n", tail_index);
}

// ~~ HELPER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Checks if string is numeric
int is_numeric (char *str) {
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')){
            return 0;
        }
    }

    if (i <= 0) {
        return 0;
    } else {
        return 1;
    }
}

// Input loop
void input_loop(QUEUE *queue, char mode) {
    int is_valid_input = 1;
    char input[10];

    if (mode == 'e') {
        do {
            system("cls");

            printf("Enqueue Item:\n\n");

            if (!is_valid_input) {
                printf("\tInput is not numeric.\n");
            }
            printf("\tInput: ");
            
            gets(input);
            input[10] = '\0';   // Ensures that input is 10 characters max

            is_valid_input = is_numeric(input);

        } while(!is_valid_input);

        printf("\n\t");
        enqueue(queue, atoi(input));
    } else if (mode == 'd') {
        system("cls");
        printf("Dequeue Item:\n\n");
        printf("\t");
        dequeue(queue);
    }

    if (DEBUG){                         // Debug message
        printf("\t");
        system("pause");
    }
}