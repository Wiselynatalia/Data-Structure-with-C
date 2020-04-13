#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stackNode {
	stackElementT elements[50];
	int count;
};

typedef struct stackNode *stackADT;

stackADT EmptyStack() {
    stackADT stack;
	stack = (stackADT) malloc (sizeof(*stack));
    stack->count = 0;
    return stack;
}

void Push(stackADT stack, stackElementT element) {
    stack->elements[(stack->count)++] = element;
    // you'll do this urself
}

char Pop(stackADT stack) {
    return (stack->elements[--(stack->count)]);
    // try this part yourself too
} 

int StackDepth(stackADT stack) {
    return stack->count;
}

int StackIsEmpty(stackADT stack) {
    return (stack->count == 0 ? 1 : 0); //if empty, return 1, else return 0
}


