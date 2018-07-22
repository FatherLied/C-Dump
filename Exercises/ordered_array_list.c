#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_LENGTH 5    // Max Length of an array
#define DEBUG 1         // Debug Mode (set to 0 to disable debug messages)

typedef struct ArrList {
    int list[MAX_LENGTH];
    int size;
} ORDEREDLIST;

ORDEREDLIST newList();      // Creates a new ordered list

int addListItem(ORDEREDLIST *list, int item);       // Adds an item to the list
int removeListItem(ORDEREDLIST *list, int item);    // Removes the first occurence of an item from the list

void printList(ORDEREDLIST list);   // Prints the entire list

int is_numeric(char *str);          // Checks if string is numeric
void input_loop(ORDEREDLIST *list, char mode);      // Input loop

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main() {
    char selection = '\0';
    int selection_is_valid = 1;
    int input_is_valid = 1;

    ORDEREDLIST list = newList();

    do {
        system("cls");
        printf("ORDERED ARRAY LIST\n\n");
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
    list.size = 0;

    return list;
}

// ~~ ORDERED LIST FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Adds an item to the list
int addListItem(ORDEREDLIST *list, int item) {
    int i = 0;

    // Exits if list is full
    if (list->size >= MAX_LENGTH) {
        if (DEBUG) {
            printf("List is full. \n");                     // Debug message
        }
        return 0;       // Returns 0 on failure
    }

    // Iterates the entire list
    for (; i < list->size; i++) {
        // Checks if item is smaller than current
        if (item <= list->list[i]) {
            // Moves the rest of the list left for insert
            for (int j = list->size; j > i; j--) {
                list->list[j] = list->list[j - 1];
            }

            list->list[i] = item;
            list->size++;

            if (DEBUG) {                // Debug message
                printf("Successfully added <%d>. \n", item); 
            }
            return 1;   // Returns 1 on success
        }
    }

    // Inserts item if it is greater than all those in the list 
    list->list[i] = item;
    list->size++;

    if (DEBUG) {                        // Debug message
        printf("Successfully added <%d>. \n", item); 
    }

    return 1;           // Returns 1 on success
}

// Removes the first occurence of an item from the list
int removeListItem(ORDEREDLIST *list, int item) {

    // Exits if list is empty
    if (list->size <= 0) {
        if (DEBUG) {                    // Debug message
            printf("Nothing to remove. \n");                
        }
        return 0;       // Returns 0 on failure
    }

    // Searches for item in the list
    for (int i = 0; i < list->size; i++) {
        if (list->list[i] == item) {
            list->size--;

            // Moves rest of the list right for removal
            for (int j = i; j < list->size; j++) {
                list->list[j] = list->list[j + 1];
            }
            if (DEBUG) {
                printf("Successfully removed <%d>. \n", item);
            }
            return 1;   // Returns 1 on success
        }
    }

    // Exits here if item is not found
    if (DEBUG) {                        // Debug message
        printf("Item not in list. \n");
    }

    return 0;           // Returns 0 on failure
}


// Prints the entire list
void printList(ORDEREDLIST list) {
    printf("List(");

    if (list.size > 0) {
        for (int i = 0; i < list.size; i++) {
            printf(" [%d] => %d", i, list.list[i]);

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