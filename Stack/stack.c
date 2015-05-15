/*
 * stack.c
 *
 *  Created on: May 15, 2015
 *      Author: victor
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct stack{
	int currentSize;
	int items[MAX];
}Stack;

Stack* createStack(){
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->currentSize = 0;
	return newStack;
}
void push(Stack* stack, int item){
	if(stack->currentSize < MAX){
		stack->items[stack->currentSize++] = item;
	} else {
		printf("Stack Overflow");
	}
}
int pop(Stack* stack){
	if(stack->currentSize > 0){
		return stack->items[--stack->currentSize];
	}
	return -1;
}
int peek(Stack* stack){
	if(stack->currentSize > 0){
		return stack->items[stack->currentSize - 1];
	}
	return -1;
}

int main(){
	Stack* pilha = createStack();

	push(pilha, 23);
	push(pilha, 33);
	push(pilha, 76);
	push(pilha, 13);
	printf("pop: %d", pop(pilha));
	printf("\npeek: %d", peek(pilha));
	printf("\npop: %d", pop(pilha));
	printf("\npeek: %d", peek(pilha));

	return 0;
}
