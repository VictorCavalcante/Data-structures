/*
 * stack.c
 *
 *  Created on: May 15, 2015
 *      Author: victor
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int item;
	struct node *nextNode;
}Node;

typedef struct stack{
	Node *top;
}Stack;

Stack* createStack(){
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->top = NULL;
	return newStack;
}

Stack* push(Stack* stack, int item){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->nextNode = stack->top;
	stack->top = newNode;
	return stack;
}

int pop(Stack* stack){
	if(stack->top != NULL){
		Node* temp = stack->top;
		int poppedItem = temp->item;
		stack->top = stack->top->nextNode;
		free(temp);
		return poppedItem;
	}
	return -1;
}

int peek(Stack* stack){
	if(stack->top != NULL){
		return stack->top->item;
	}
	return -1;
}

void freeStack(Stack* stack){
	while(stack->top != NULL){
		pop(stack);
	}
	printf("\nFree!");
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

	freeStack(pilha);
	return 0;
}
