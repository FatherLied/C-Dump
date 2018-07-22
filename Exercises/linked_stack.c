#include <stdio.h>
#include <stdlib.h>
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

// ~~ PROGRAM MAIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

int main()
{
    STACK stack = newStack();
    pop(&stack);
    push(&stack, 5);
    push(&stack, 3);
    push(&stack, 6);
    push(&stack, 1);
    push(&stack, -1);

    printStack(stack);

    pop(&stack);

    printStack(stack);
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

    printf("\tTOP: [%d] => %d \n", (stack.size - 1), stack.top->item);
}