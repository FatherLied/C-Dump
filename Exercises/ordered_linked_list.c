#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DEBUG 1         // Debug Mode (set to 0 to disable debug messages)

// Node structure
typedef struct node {
    int item;
    struct node *next;
} NODE;

// Single Linked List
typedef struct llist {
    NODE *head, *tail;
    int size;
} ORDEREDLIST;

ORDEREDLIST newList();

int addListItem(ORDEREDLIST *list, int item);       // Adds an item to the list
int removeListItem(ORDEREDLIST *list, int item);    // Removes the first occurence of an item from the list

void init(NODE *n, int i);          // Initialize a node
void printList(ORDEREDLIST list);   // Prints entire stack

int is_numeric(char *str);          // Checks if string is numeric
void input_loop(ORDEREDLIST *list, char mode);      // Input loop

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main () {
    char selection = '\0';
    int selection_is_valid = 1;
    int input_is_valid = 1;

    ORDEREDLIST list = newList();

    do {
        system("cls");
        printf("ORDERED LINKED LIST\n\n");
        printf("\t<1> Add item.\n");
        printf("\t<2> Remove item.\n\n");
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
                input_loop(&list, 'a');
                break;
            case '2':
                input_loop(&list, 'r');
                break;
            case '0':
                break;
            default:
                selection_is_valid = 0;
        }
    } while (selection != '0');

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

        if (DEBUG) {                    // Debug message
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

            if (DEBUG) {                // Debug message
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
        if (DEBUG) {                    // Debug message
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

            if (DEBUG) {                // Debug message
                printf("Successfully removed <%d>. \n", item);
            }

            return 1;
        }

        last = ptr;
    }

    if (DEBUG) {                        // Debug message
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
void input_loop(ORDEREDLIST *list, char mode) {
    int is_valid_input = 1;
    char input[10];

    do {
        system("cls");

        if (mode == 'a') {           // 'a' for adding items
            printf("Add Item:\n\n");
        } else if (mode == 'r') {    // 'r' for removing items
            printf("Remove Item:\n\n");
        } else {
            return; // Failsafe in case non-valid mode is entered
        }

        if (!is_valid_input) {
            printf("\tInput is not numeric.\n");
        }
        printf("\tInput: ");
        
        gets(input);
        input[10] = '\0';   // Ensures that input is 10 characters max

        is_valid_input = is_numeric(input);

    } while(!is_valid_input);

    if (mode == 'a') {
        printf("\n\t");
        addListItem(list, atoi(input));
    } else if (mode == 'r') {
        printf("\n\t");
        removeListItem(list, atoi(input));
    }

    if (DEBUG){                         // Debug message
        printf("\t");
        system("pause");
    }
}