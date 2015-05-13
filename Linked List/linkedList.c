#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int item;
	struct node *nextNode;
}Node;

Node* createLinkedList(){
	return NULL;
}

int isEmpty(Node *list){
	return (list == NULL);
}

Node* insertNode(Node *list, int value){
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->item = value;
	newNode->nextNode = list;
	return newNode;
}

void printLinkedList(Node *list){
	Node *p;
	for(p = list; p != NULL; p = p->nextNode){
		printf("[%d]", p->item);
	}
}
void printLInkedListRecursively(Node *list){
	if(!isEmpty(list)){
		printf("(%d)", list->item);
		printLInkedListRecursively(list->nextNode);
	}
}

Node* searchLinkedList(Node *list, int item){
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
	Node* previous = NULL;

	while(current != NULL && current->item != item){
		previous = current;
		current = current->nextNode;
	}
	if(current == NULL){ //If empty or end
		return list;
	} else if(previous == NULL) { //If first
		list = current->nextNode;
	} else { //If middle
		previous->nextNode = current->nextNode;
	}
	free(current);
	return list;
}

void freeList(Node *head) {
    Node *release;
    while(head != NULL){
        release = head;
        head = head->nextNode ;
        free(release);
  }
  puts("\n[Freed!]");
}

/*
int verSubconjunto(Node *lista1, Node* lista2){
    Node *p, *q;
    int num;
    for(p = lista2; p != NULL; p = p->nextNode){
        for(q = lista1; q != NULL; q = q->nextNode){
            if(q->item != p->item)
            printf("\nNao e subconjunto");
            return;
        }
    }
    printf("\nE um subconjunto :)");
    return;
}
Node* inverteLista(Node *lista){
    Node *previous = NULL;
    Node *current = lista;
    Node *ahead = lista->nextNode;

    while(ahead != NULL){
        current->nextNode = previous;
        previous = current;
        current = ahead;
        ahead = current->nextNode;
    }
    current->nextNode = previous;
    return current;
}
Node* ordenaLista(Node *start){
    Node *p, *q, *top, *auxp;
    int changed = 1;
    if( (top = malloc(sizeof(Node))) == NULL) {
        fprintf( stderr, "Memory Allocation error.\n" );
        return;
    }
    top->nextNode = start;
    if( start != NULL && start->nextNode != NULL ) {
        while( changed ) {
            changed = 0;
            q = top;
            p = top->nextNode;
            while( p->nextNode != NULL ) {
                if( p->item > p->nextNode->item ) {
                    auxp = p->nextNode;
                    p->nextNode = auxp->nextNode;
                    auxp->nextNode = p;
                    q->nextNode = auxp;
                    changed = 1;
                }
                q = p;
                if( p->nextNode != NULL )
                    p = p->nextNode;
            }
        }
    }
    p = top->nextNode;
    free( top );
    return p;
}
*/

int main(){
    Node *listA = createLinkedList();

    listA = insertNode(listA, 23);
    listA = insertNode(listA, 33);
    listA = insertNode(listA, 42);
    listA = insertNode(listA, 80);
    listA = insertNode(listA, 22);

    printLinkedList(listA);
    removeNode(listA, 80);
    removeNode(listA, 90);
    //listA = ordenaLista(listA);
    printLInkedListRecursively(listA);

    freeList(listA);
    return 0;
}
