/*
 * queue.c
 *
 *  Created on: May 15, 2015
 *      Author: victor
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	int priority;
	struct node *nextNode;
}Node;

typedef struct queue{
	Node *first;
}Queue;

Queue* createQueue(){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->first = NULL;
	return queue;
}

int isEmpty(Queue* queue){
	return (queue->first == NULL);
}

Queue* enqueue(Queue* priorityQueue, int item, int priority){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->priority = priority;
	newNode->value = item;

	if(isEmpty(priorityQueue) || priorityQueue->first->priority < priority){ //insert front
		newNode->nextNode = priorityQueue->first;
		priorityQueue->first = newNode;
	} else {
		Node *current = priorityQueue->first;
		while(current->nextNode != NULL && current->nextNode->priority > priority){ //insert end or mid
			current = current->nextNode;
		}
		newNode->nextNode = current->nextNode;
		current->nextNode = newNode;
	}
	return priorityQueue;
}

int dequeue(Queue* queue){
	if(!isEmpty(queue)){
		int dequeued = queue->first->value;
		Node *current = queue->first;
		queue->first = queue->first->nextNode;
		free(current);
		return dequeued;
	}
	return -1;
}

void printPriorityQueue(Queue* queue){
	Node *current = queue->first;
	while(current != NULL){
		printf("[%d|%d]-", current->value, current->priority);
		current = current->nextNode;
	}
}

void freePriorityQueue(Queue* queue){
	Node *current;
	while(queue->first != NULL){
		current = queue->first;
		printf("[%d|%d]-", queue->first->value, queue->first->priority);
		queue->first = queue->first->nextNode;
		free(current);
	}
}

int main(){
	Queue* queue = createQueue();

	enqueue(queue, 1, 1);
	enqueue(queue, 5, 5);
	enqueue(queue, 2, 2);
	enqueue(queue, 2, 2);
	printPriorityQueue(queue); printf("\n");
	printf("dequeued: %d\n", dequeue(queue));
	enqueue(queue, 3, 3);

	freePriorityQueue(queue);
	return 0;
}
