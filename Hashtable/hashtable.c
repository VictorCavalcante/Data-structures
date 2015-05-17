/*
 * hashtable.c
 *  Created on: May 17, 2015
 *      Author: victor
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 11

typedef struct element{
	int key;
	int value;
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

void put(Hashtable* ht, int value, int key){
	int h = hashGenerator(key), begin = -1;
	while(ht->table[h] != NULL && h != begin){
		if(ht->table[h]->key == key || ht->table[h]->key == -1){
			ht->table[h]->key = key;
			ht->table[h]->value = value;
			break;
		}
		if(begin == -1){
			begin = h;
		}
		h = (h + 1) % MAX;
	}
	Element* newElement = (Element*)malloc(sizeof(Element));
	newElement->key = key;
	newElement->value = value;
	ht->table[h] = newElement;
}

int get(Hashtable* ht, int key){
	int h = hashGenerator(key), begin = -1;
	while(ht->table[h] != NULL && h != begin){
		if(ht->table[h]->key == key){
			return ht->table[h]->value;
		}
		if(begin == -1){
			begin = h;
		}
		h = (h + 1) % MAX;
	}
	return -1;
}

void removeHashItem(Hashtable* ht, int key){
	int h = hashGenerator(key), begin = -1;
	while(ht->table[h] != NULL && h != begin){
		if(ht->table[h]->key == key){
			ht->table[h]->key = -1;
		}
		if(begin == -1){
			begin = h;
		}
		h = (h + 1) % MAX;
	}
}

void freeHash(Hashtable *ht){
    int i;
    for(i = 0; i < MAX; i++){
        free(ht->table[i]);
    }
}
void printHashtable(Hashtable *ht){
    int i;
    for(i = 0; i < MAX; i++){
        if(ht->table[i] == NULL){
            printf("%d. -> [--]\n", i);
        } else if (ht->table[i]->key == -1){
            printf("%d. -> [DEL]\n", i);
        } else {
            printf("%d. -> [%d] | [%d]\n", i, ht->table[i]->key, ht->table[i]->value);
        }
    }
}

int main(){
	Hashtable* table = createTable();

	put(table, 22, 1);
	put(table, 22, 4);
	put(table, 13, 3);
	put(table, 13, 6);
	put(table, 16, 7);
	put(table, 16, 7);
	put(table, 16, 8);
	removeHashItem(table, 6);
	put(table, 77, 6);

	printHashtable(table);
	freeHash(table);
	return 0;
}
