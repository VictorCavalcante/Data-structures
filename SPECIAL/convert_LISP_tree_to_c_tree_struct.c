/*
 * convert_LISP_tree_to_c_tree_struct.c
 *  Created on: May 21, 2015
 *      Author: Victor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VAL 10
#define MAX_INP 90

// BINARY TREE =================================================
typedef struct binarytree{
	char value[MAX_VAL];
	struct binarytree *left;
	struct binarytree *right;
}Binarytree;

void freeBinaryTree(Binarytree* bt){
	if(bt != NULL){
		freeBinaryTree(bt->left);
		freeBinaryTree(bt->right);
		printf("%s ", bt->value);
		free(bt);
	}
}

// STACK =======================================================
typedef struct node{
	char item[MAX_VAL];
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

Stack* push(Stack* stack, char* item){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->item, item);
	newNode->nextNode = stack->top;
	stack->top = newNode;
	return stack;
}

void pop(Stack* stack){
	if(stack->top != NULL){
		Node* temp = stack->top;
		stack->top = stack->top->nextNode;
		free(temp);
	}
}
void freeStack(Stack* stack){
	while(stack->top != NULL){
		pop(stack);
	}
}
//==============================================================

char *strrev(char *str){
      char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

Binarytree* createBinaryTreeByInput(Binarytree* bt, Stack* pilha){
	if(strcmp(pilha->top->item, "(") == 0){
		pop(pilha);
		if(strcmp(pilha->top->item, ")") != 0){
			Binarytree* newEdge = (Binarytree*)malloc(sizeof(Binarytree));
			strcpy(newEdge->value, pilha->top->item);
			pop(pilha);
			newEdge->left = createBinaryTreeByInput(newEdge, pilha);  //R1 5 - (4 //R2 4 - ()
			newEdge->right = createBinaryTreeByInput(newEdge, pilha);
			if(strcmp(pilha->top->item, ")") == 0){
				pop(pilha);
				return newEdge;
			}
		} else {
			pop(pilha);
			return NULL;
		}
	}
}

int main(){
	Stack *pilha = createStack();
	Binarytree* bt = NULL;
	int i;
	char inputTree[MAX_INP] = "(5(4(11(7()())(2()()))())(8(13()())(4()(1()()))))";
	char temp[MAX_VAL] = "";
	char aux[2];
	aux[1] = '\0';
	strrev(inputTree);

	//Push to stack
	for(i = 0; i < strlen(inputTree); i++){
		aux[0] = inputTree[i];
		strcat(temp, aux);
		while((inputTree[i] != ')' && inputTree[i] != '(') && (inputTree[i+1] != ')' && inputTree[i+1] != '(')){
			aux[0] = inputTree[i+1];
			strcat(temp, aux);
			i++;
		}
		strrev(temp);
		push(pilha, temp);
		strcpy(temp, "");
	}
	//Create binary tree
	bt = createBinaryTreeByInput(bt, pilha);

	//Free
	freeBinaryTree(bt);
	freeStack(pilha);
	return 0;
}

