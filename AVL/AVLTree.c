/*
 * AVLTree.c
 *  Created on: May 24, 2015
 *      Author: victor
 */
#include <stdio.h>
#include <stdlib.h>

// Binary Search tree ==================================================
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
void printPreOrder(Binarytree* bt){
	if(bt != NULL){
		printf("%d ", bt->value);
		printPreOrder(bt->left);
		printPreOrder(bt->right);
	}
}

void freeBinaryTree(Binarytree* bt){
	if(bt != NULL){
		freeBinaryTree(bt->left);
		freeBinaryTree(bt->right);
		free(bt);
	}
}
// AVL tree ==================================================
/*
int findHeight(){
	return 1;
}
*/

int balanceFactor(Binarytree* tree){
	int bf = findHeight(tree->left) - findHeight(tree->right);
	return (bf >= -1 && bf <= 1);
}

Binarytree* rotateLeft(Binarytree *bt) {
	Binarytree *subtreeRoot = NULL;
	if (bt != NULL && bt->right != NULL) {
		subtreeRoot = bt->right;
		bt->right = subtreeRoot->left;
		subtreeRoot->left = bt;
	}
	//returns the new root
	return subtreeRoot;
}

Binarytree* rotateRight(Binarytree *bt) {
	Binarytree *subtreeRoot = NULL;
	if (bt != NULL && bt->left != NULL) {
		subtreeRoot = bt->left;
		bt->left = subtreeRoot->right;
		subtreeRoot->right = bt;
	}
	//returns the new root
	return subtreeRoot;
}

Binarytree* rotateAVL(Binarytree *node){
	if (balanceFactor(node) == 2) {
		if(balanceFactor(node->left) == -1) { //Left-Left
			node->left = rotateLeft(node->left);
		}
		node = rotateRight(node);
	} else {
		if(balanceFactor(node->right) == 1) { //Right-Right
			node->right = rotateRight(node->right);
		}
		node = rotateLeft(node);
	}
	return node;
}

int main(){
	Binarytree *binarySearchTree = NULL;
	binarySearchTree = insertNodeBST(binarySearchTree, 3);
	binarySearchTree = insertNodeBST(binarySearchTree, 1);
	binarySearchTree = insertNodeBST(binarySearchTree, 5);
	binarySearchTree = insertNodeBST(binarySearchTree, 4);
	binarySearchTree = insertNodeBST(binarySearchTree, 6);
	binarySearchTree = insertNodeBST(binarySearchTree, 8);

	printPreOrder(binarySearchTree);
	binarySearchTree = rotateAVL(binarySearchTree);
	printPreOrder(binarySearchTree);


	freeBinaryTree(binarySearchTree);
	return 0;
}
