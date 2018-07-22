#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DEBUG 1         // Debug Mode (set to 0 to disable debug messages)

// Node structure
typedef struct node {
    int item;
    struct node *next;
} NODE;

// Doubly Linked List
typedef struct llist {
    NODE *head, *tail;
    int size;
} ORDEREDLIST;

ORDEREDLIST newList();

int addListItem(ORDEREDLIST *list, int item);       // Adds an item to the list
int removeListItem(ORDEREDLIST *list, int item);    // Removes the first occurence of an item from the list

void init(NODE *n, int i);          // Initialize a node
void printList(ORDEREDLIST list);   // Prints entire stack

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main () {
    

    return 0;
}

// ~~ ORDERED LIST CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Creates a new ordered list
ORDEREDLIST newList() {
    ORDEREDLIST list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    return list;
}

// Initialize a node
void init(NODE *n, int i) {
    n->item = i;
    n->next = NULL;
}

// ~~ ORDERED LIST FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Adds an item to the list
int addListItem(ORDEREDLIST *list, int item) {
    NODE *new_node = malloc(sizeof(NODE));
    init(new_node, item);

    // If list is empty
    if (list->size <= 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;

        if (DEBUG) {
            printf("Successfully added <%d>. \n", item);
        }

        return 1;
    }

    NODE *ptr = list->head;      // Pointer for traversing list
    NODE *last = list->head;     // Stores last node pointed

    for (int i = 0; ptr!=NULL; ptr = ptr->next, i++){

        // Inserts new node if smaller than current
        if (new_node->item <= ptr->item){
            new_node->next = ptr;

            if (i == 0) {   // Checks if match is the first element of list
                list->head = new_node;
            } else {
                last->next = new_node;
            }

            list->size++;

            if (DEBUG) {
                printf("Successfully added <%d>. \n", item);
            }

            return 1;       // Returns 1 on success
        }

        last = ptr;     // "Remembers" last node accessed
    }

    // Inserts new node at the end of the list
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;

    if (DEBUG) {
        printf("Successfully added <%d>. \n", item);
    }

    return 1;               // Returns 1 on success
}

// Removes the first occurence of an item from the list
int removeListItem(ORDEREDLIST *list, int item) {
    if (list->size <= 0) {
        if (DEBUG) {
            printf("List is empty. \n");
        }
        return 0;       // Returns 0 since there's nothing to remove
    }

    NODE *ptr = list->head;      // Pointer for traversing list
    NODE *last = list->head;     // Stores last node pointed

    for (int i = 0; ptr != NULL; ptr = ptr->next, i++){
        if (ptr->item == item) {
            if (i == 0) {
                list->head = ptr->next;
            } else {
                last->next = ptr->next;
            }

            free(ptr);
            list->size--;

            if (DEBUG) {
                printf("Successfully removed <%d>. \n", item);
            }

            return 1;
        }

        last = ptr;
    }

    if (DEBUG) {
        printf("Item is not in list. \n");
    }

    return 0;           // Returns 0 since query is not in list
}

// Prints entire stack
void printList(ORDEREDLIST list) {
    int i = 0;
    printf("List(");

    if (list.size > 0) {
        for (NODE *ptr = list.head; ptr != NULL; ptr = ptr->next, i++) {
            printf(" [%d] => %d", i, ptr->item);

            // Checks for next item, puts comma if so
            if (i + 1 < list.size) {
                printf(",");
            }
        }
    }

    printf(" )\n");
}