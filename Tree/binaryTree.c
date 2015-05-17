/*
 * binaryTree.c
 *  Created on: May 17, 2015
 *      Author: victor
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree{
	int value;
	struct binarytree *left;
	struct binarytree *right;
}Binarytree;

Binarytree* createBinaryTree(int value, Binarytree* left, Binarytree* right){
	Binarytree* newEdge = (Binarytree*)malloc(sizeof(Binarytree));
	newEdge->value = value;
	newEdge->left = left;
	newEdge->right = right;
	return newEdge;
}

void printInOrder(Binarytree* bt){
	if(bt != NULL){
		printInOrder(bt->left);
		printf("%d ", bt->value);
		printInOrder(bt->right);
	}
}
void printPreOrder(Binarytree* bt){
	if(bt != NULL){
		printf("%d ", bt->value);
		printPreOrder(bt->left);
		printPreOrder(bt->right);
	}
}
void printPostOrder(Binarytree* bt){
	if(bt != NULL){
		printPostOrder(bt->left);
		printPostOrder(bt->right);
		printf("%d ", bt->value);
	}
}
void freeBinaryTree(Binarytree* bt){
	if(bt != NULL){
		freeBinaryTree(bt->left);
		freeBinaryTree(bt->right);
		free(bt);
	}
}

int main(){
	Binarytree* bt = createBinaryTree(0,
			createBinaryTree(3, NULL, NULL),
			createBinaryTree(0,
					createBinaryTree(9, NULL, NULL),
					createBinaryTree(2, NULL, NULL)));
	printPreOrder(bt); printf("\n");
	printInOrder(bt); printf("\n");
	printPostOrder(bt); printf("\n");

	freeBinaryTree(bt);
	return 0;
}


