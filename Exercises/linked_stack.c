#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DEBUG 1         // Debug Mode (set to 0 to disable debug messages)

// Node structure
typedef struct node {
    int item;
    struct node *next, *prev;
} NODE;

// Doubly Linked List Stack
typedef struct llist {
    NODE *bottom, *top;
    int size;
} STACK;

STACK newStack();       // Creates a new stack

int push(STACK *stack, int item);   // Pushes an item to the stack
int pop(STACK *stack);              // Pops an item from the stack

void init(NODE *n, int i);     // Initialize a node
void printStack(STACK stack);   // Prints entire stack

int is_numeric(char *str);          // Checks if string is numeric
void input_loop(STACK *stack, char mode);      // Input loop

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main()
{
    char selection = '\0';
    int selection_is_valid = 1;
    int input_is_valid = 1;

    STACK list = newStack();

    do {
        system("cls");
        printf("LINKED STACK\n\n");
        printf("\t<1> Push item.\n");
        printf("\t<2> Pop item.\n\n");
        printf("\t<0> Exit.\n\n");

        if (!selection_is_valid){
            printf("\tInvalid choice. Valid keys are labeled with <>.");
        } else {
            printf("\tSelect option in <>.");
        }
        printf("\n\n\t");
        printStack(list);

        selection = getch();

        selection_is_valid = 1;
        switch (selection) {
            case '1':
                input_loop(&list, 'o');     // Push item
                break;
            case '2':
                input_loop(&list, 'x');     // Pop item
                break;
            case '0':
                break;
            default:
                selection_is_valid = 0;
        }
    } while (selection != '0');

    return 0;
}

// ~~ STACK CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Creates a new stack
STACK newStack() {
    STACK stack;

    stack.bottom = NULL;
    stack.top = NULL;
    stack.size = 0;

    return stack;
}

// Initialize a node
void init(NODE *n, int i) {
    n->item = i;
    n->next = NULL;
    n->prev = NULL;
}

// ~~ STACK FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Pushes an item to the stack
int push(STACK *stack, int item) {
    NODE *new_node = malloc(sizeof(NODE));
    init(new_node, item);

    // When stack is empty
    if (stack->size <= 0) {
        stack->bottom = new_node;
        stack->top = new_node;
        stack->size++;
    } else {
        stack->top->next = new_node;
        new_node->prev = stack->top;
        stack->top = new_node;
        stack->size++;
    }

    if (DEBUG) {
        printf("Successfully pushed <%d>\n", item);
    }

    return 1;       // Returns 1 on success
}

// Pops an item from the stack
int pop(STACK *stack) {
    int item = -1;              // Container for popped item
    NODE *trash = stack->top;    // Container to free node

    // When stack is empty
    if (stack->size <= 0){
        if (DEBUG) {
            printf("Stack is empty. \n");       // Debug message
        }
    } else {
        // Retrieves the last item
        item = stack->top->item;
        stack->top = stack->top->prev;
        stack->size--;

        if (DEBUG) {
            printf("Popped <%d>. \n", item);
        }

        if (stack->top == NULL) {
            stack->bottom = NULL;
        } else {  
            stack->top->next = NULL;
        }

        free(trash);
    }


    // Returns item popped out, else -1 by default
    return item;
}

// Prints entire stack
void printStack(STACK stack){
    int i = 0;
    printf("List(");

    if (stack.size > 0) {
        for (NODE *ptr = stack.bottom; ptr != NULL; ptr = ptr->next, i++) {
            printf(" [%d] => %d", i, ptr->item);

            // Checks for next item, puts comma if so
            if (i + 1 < stack.size) {
                printf(",");
            }
        }
    }

    printf(" )\n");

    // Shows top index, else "-1" if stack is empty
    printf("\tTop:    Index is: [%d]\n", (stack.size - 1));
    // Shows bottom index, starts at 0
    printf("\tBottom: Index is: [%d]\n", (stack.size - stack.size));
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
void input_loop(STACK *stack, char mode) {
    int is_valid_input = 1;
    char input[10];

    if (mode == 'o') {
        do {
            system("cls");

            printf("Push Item:\n\n");

            if (!is_valid_input) {
                printf("\tInput is not numeric.\n");
            }
            printf("\tInput: ");
            
            gets(input);
            input[10] = '\0';   // Ensures that input is 10 characters max

            is_valid_input = is_numeric(input);

        } while(!is_valid_input);

        printf("\n\t");
        push(stack, atoi(input));
    } else if (mode == 'x') {
        system("cls");
        printf("Pop Item:\n\n");
        printf("\t");
        pop(stack);
    }

    if (DEBUG){                         // Debug message
        printf("\t");
        system("pause");
    }
}