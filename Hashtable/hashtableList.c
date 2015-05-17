/*
 * hashtableList.c
 *  Created on: May 17, 2015
 *      Author: victor
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 11

typedef struct element{
	int value;
	int elementKey;
	struct element* nextElement;
}Element;

typedef struct hashtable{
	Element *table[MAX];
}Hashtable;

Hashtable* createTable(){
	Hashtable* newTable = malloc(sizeof(Hashtable));
	int i;
	for(i = 0; i < MAX; i++){
		newTable->table[i] = NULL;
	}
	return newTable;
}

int hashGenerator(int key){
	return (key % 11);
}

void put(Hashtable* ht, int value, int elementKey){
	int h = hashGenerator(elementKey);
	Element* newElement = (Element*)malloc(sizeof(Element));
	newElement->value = value;
	newElement->elementKey = elementKey;
	newElement->nextElement = ht->table[h];
	ht->table[h] = newElement;
}

int get(Hashtable* ht, int elementKey){
	int h = hashGenerator(elementKey);
	Element* current = ht->table[h];
	while(current != NULL && current->elementKey != elementKey){
		current = current->nextElement;
	}
	if(current == NULL){
		return -1;
	} else {
		return current->value;
	}
}
/*
void removeHashItem(Hashtable* ht, int elementKey){
	int h = hashGenerator(elementKey);
	Element *current = ht->table[h];
	Element *previous = current;
	while(current != NULL && current->elementKey != elementKey){
		previous = current;
		current = current->nextElement;
	}
	if(current != NULL){
		printf("%d\n", previous->value);
		printf("%d\n", current->nextElement->value);
		previous->nextElement = current->nextElement;
		free(current);
	}
}
*/
void freeHash(Hashtable *ht){
    int i;
    Element *current, *previous;
    for(i = 0; i < MAX; i++){
		printf("\n[%d.]--", i);
		current = ht->table[i];
		while(current != NULL){
			printf("%d|%d -> ", current->value, current->elementKey);
			previous = current;
			current = current->nextElement;
			free(previous);
		}
    }
}

int main(){
	Hashtable* table = createTable();

	put(table, 22, 1);

	put(table, 13, 3);
	put(table, 22, 4);

	put(table, 77, 6); put(table, 66, 6);
	put(table, 44, 7); put(table, 33, 7);
	put(table, 16, 8);

	freeHash(table);
	return 0;
}
