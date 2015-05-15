/*
 * queue.c
 *
 *  Created on: May 15, 2015
 *      Author: victor
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue{
	int first;
	int last;
	int currentSize;
	int items[MAX];
}Queue;

Queue* createQueue(){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->first = 0;
	queue->last = MAX - 1;
	queue->currentSize = 0;
	return queue;
}

int isEmpty(Queue* queue){
	return (queue->currentSize == 0);
}

void enqueue(Queue* queue, int item){
	if(queue->currentSize < MAX){
		queue->last = (queue->last + 1) % MAX;
		queue->items[queue->last] = item;
		queue->currentSize++;
	} else {
		printf("Full house!");
	}
}

int dequeue(Queue* queue){
	if(!isEmpty(queue)){
		int currentItem = queue->items[queue->first];
		queue->first = (queue->first + 1) % MAX;
		queue->currentSize--;
		return currentItem;
	}
	return -1;
}

int main(){
	Queue* queue = createQueue();

	enqueue(queue, 22);
	enqueue(queue, 22);
	enqueue(queue, 33);
	enqueue(queue, 14);
	printf("dequeued: %d", dequeue(queue));
	printf("\ndequeued: %d", dequeue(queue));
	printf("\ndequeued: %d", dequeue(queue));
	enqueue(queue, 99);
	printf("\ndequeued: %d", dequeue(queue));
	enqueue(queue, 99);
	printf("\ndequeued: %d", dequeue(queue));
	printf("\ndequeued: %d", dequeue(queue));

	return 0;
}
