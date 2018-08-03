/*TODO after implementing doubly linked list, go to case 3 in user_interface.c and fill in the correct calls*/

/*try to implement this inside sudoku_board*/
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <stdlib.h>

typedef struct {
	int i;
	int j;
	int old;
	int new;
} Step;

typedef struct {
	Step step;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct {
	Node *head;
	Node *tail;
} DLlist;


void insertFirst(Node** head, Step newStep)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->step = newStep;
    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head) != NULL) /*if the list isn't empty, link head prev to new node*/
        (*head)->prev = newNode;

    (*head) = newNode;
}

void insertAfter(Node* prevNode, Step newStep)
{
	Node* newNode = NULL;
    assert(prevNode != NULL);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->step = newStep;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode; /*link the node after newNode*/
}


void insertLast(Node** head, Step step)
{
	Node* newNode = NULL;
	Node* last = NULL;

    newNode = (Node*)malloc(sizeof(Node));
    last = *head;

    newNode->next = NULL;
    newNode->step = step;


    if (*head == NULL) { /*if list is empty, the new node is head*/
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (last->next != NULL) /*search for the end of the list*/
        last = last->next;

    last->next = newNode;
    newNode->prev = last;

    return;
}

void printStep(Node* node) {
	Step *step = node->step;
	printf("%d,%d: %d -> %d\n", step->i,step->j,step->old, step->new);
}

void printList(Node* node)
{
    Node* last = NULL;
    printf("printing list from start:\n");
    while (node != NULL) {
        printStep(node);
        last = node;
        node = node->next;
    }

    printf("end of list\n");
}



void destroyList(Node *head) {
	Node *curNode= NULL;
	Node *nextNode= NULL;
	curNode = head;
	while(curNode!= NULL) {
		nextNode = curNode->next;
		free(curNode->step);
		free(curNode);
		curNode = nextNode;
	}

}
