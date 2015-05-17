/*
 * binarySearchTree.c
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

//Recursively
Binarytree* insertNodeBST(Binarytree* bt, int value){
	if(bt == NULL){
		bt = createBinaryTree(value, NULL, NULL);
	} else if(bt->value > value){
		bt->left = insertNodeBST(bt->left, value);
	} else {
		bt->right = insertNodeBST(bt->right, value);
	}
	return bt;
}

void printInOrder(Binarytree* bt){
	if(bt != NULL){
		printInOrder(bt->left);
		printf("%d ", bt->value);
		printInOrder(bt->right);
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
	Binarytree *binarySearchTree = NULL;
	binarySearchTree = insertNodeBST(binarySearchTree, 3);
	binarySearchTree = insertNodeBST(binarySearchTree, 8);
	binarySearchTree = insertNodeBST(binarySearchTree, 1);
	binarySearchTree = insertNodeBST(binarySearchTree, 6);
	binarySearchTree = insertNodeBST(binarySearchTree, 7);

	printInOrder(binarySearchTree);
	freeBinaryTree(binarySearchTree);
	return 0;
}
