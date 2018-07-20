#include <stdio.h>

// Node structure
typedef struct node {
	int item;
	struct node *next, *prev;
} NODE;

// Doubly Linked List Stack
typedef struct llist {
	NODE *head, *tail;
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
	return 0;
}

// ~~ STACK CONSTRUCTOR ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Creates a new stack
STACK newStack() {
	STACK stack;

	stack.head = NULL;
	stack.tail = NULL;
	stack.size = 0;

	return stack;
}

// Initialize a node
void init(NODE *n, int i) {
	n->item = 0;
	n->next = NULL;
	n->prev = NULL;
}

// ~~ STACK FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

// Pushes an item to the stack
int pushStack(STACK *stack, int item) {
	NODE *newNode = malloc(sizeof(NODE));
	init(newNode, item);

	// When stack is empty
	if (stack->size <= 0) {
		stack->head = newNode;
		stack->tail = newNode;
		stack->size++;
		return 1;
	}
	else {
		stack->tail->next = newNode;
		newNode->prev
			stack->size++;
	}

}

// Pops an item from the stack

// Prints entire stack
// void printStack(STACK stack){

// }