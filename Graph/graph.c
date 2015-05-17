/*
 * graph.c
 *  Created on: May 17, 2015
 *      Author: victor
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct vertex{
	int value;
	struct vertex *nextVertex;
}Vertex;

typedef struct graph{
	Vertex* adjList[MAX];
	short visited[MAX];
}Graph;

Graph* createGraph(){
	Graph* newGraph = (Graph*)malloc(sizeof(Graph));
	int i;
	for(i = 0; i < MAX; i++){
		newGraph->adjList[i] = NULL;
		newGraph->visited[i] = 0;
	}
	return newGraph;
}

void addEdge(Graph* graph, int vx, int vy){
	//Creating (X) and linking (X)<--(Y)
	Vertex *newVertex = (Vertex*)malloc(sizeof(Vertex));
	newVertex->value = vx;
	newVertex->nextVertex = graph->adjList[vy];
	graph->adjList[vy] = newVertex;

	//Creating (Y) and linking to (X)-->(Y)
	newVertex = (Vertex*)malloc(sizeof(Vertex));
	newVertex->value = vy;
	newVertex->nextVertex = graph->adjList[vx];
	graph->adjList[vx] = newVertex;
}

void freeGraph(Graph* graph){
    int i;
    Vertex *current, *previous;
    for(i = 0; i < MAX; i++){
		printf("\n[%d.]--", i);
        current = graph->adjList[i];
        while(current != NULL){
			printf("[%d]->", current->value);
			previous = current;
			current = current->nextVertex;
			free(previous);
        }
    }
}

int main(){
	Graph *graph = createGraph();
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 3, 0);

	freeGraph(graph);

	return 0;
}
