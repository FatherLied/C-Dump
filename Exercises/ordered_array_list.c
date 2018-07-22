#include <stdio.h>

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

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main() {
    ORDEREDLIST list = newList();
    printf("Size: %d\n", list.size);
    addListItem(&list, 1);
    addListItem(&list, 5);
    addListItem(&list, 3);
    addListItem(&list, 2);
    addListItem(&list, 2);
    printf("Size: %d\n", list.size);
    printList(list);
    removeListItem(&list, 5);
    removeListItem(&list, 5);
    printList(list);
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
            if (DEBUG) {
                printf("Successfully added <%d>. \n", item); // Debug message
            }
            return 1;   // Returns 1 on success
        }
    }

    // Inserts item if it is greater than all those in the list 
    list->list[i] = item;
    list->size++;

    return 1;           // Returns 1 on success
}

// Removes the first occurence of an item from the list
int removeListItem(ORDEREDLIST *list, int item) {

    // Exits if list is empty
    if (list->size <= 0) {
        if (DEBUG) {
            printf("Nothing to remove. \n");                // Debug message
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
    if (DEBUG) {
        printf("Item not in list. \n");                     // Debug message
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