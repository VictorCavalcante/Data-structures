#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int item;
	struct node *nextNode;
	struct node *previousNode;
}Node;

Node* createDoublyLinkedList(){
	return NULL;
}

int isEmpty(Node *list){
	return (list == NULL);
}

Node* insertNode(Node *list, int value){
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->item = value;
	newNode->nextNode = list;
	newNode->previousNode = NULL;
	if(!isEmpty(list)){
		list->previousNode = newNode;
	}
	return newNode;
}

void printList(Node *list){
	Node *p;
	for(p = list; p != NULL; p = p->nextNode){
		printf("[%d]", p->item);
	}
}

void printListBackwards(Node *list){
	if(!isEmpty(list)){
		Node *p = list;
		while(p->nextNode != NULL){
			p = p->nextNode;
		}
		while(p != NULL){
			printf("[%d]", p->item);
			p = p->previousNode;
		}
	}
}

Node* searchNode(Node *list, int item){
    Node *p;
    for(p = list; p != NULL; p = p->nextNode){
        if(p->item == item){
            return p;
        }
    }
    return NULL;
}

Node* removeNode(Node *list, int item){
	Node* current = list;

	while(current != NULL && current->item != item){
		current = current->nextNode;
	}
	if(current == NULL){ //If empty or end
		return list;
	} else if(current->previousNode == NULL) { //If first
		list = current->nextNode;
	} else { //If middle
		current->previousNode->nextNode = current->nextNode;
	}
	if(current->nextNode != NULL){
		current->nextNode->previousNode = current->previousNode;
	}
	free(current);
	return list;
}

void freeList(Node *head) {
    Node *release;
    while(head != NULL){
        release = head;
        head = head->nextNode;
        free(release);
  }
  printf("\n[Freed!]");
}

int main(){
	Node *list = createDoublyLinkedList();

	list = insertNode(list, 23);
	list = insertNode(list, 33);

	list = removeNode(list, 23);
	list = insertNode(list, 42);
	list = insertNode(list, 33);
	list = insertNode(list, 39);

	printList(list); printf("\n");
	printListBackwards(list); printf("\n");

	freeList(list);
    return 0;
}
