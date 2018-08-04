/*TODO after implementing doubly linked list, go to case 3 in user_interface.c and fill in the correct calls*/

/*try to implement this inside sudoku_board*/
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <assert.h>
#include <stdlib.h>
#include "doubly_linked_list.h"


void insertFirst(Node** head, Step newStep)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->step = newStep;
    newNode->next = *head;
    newNode->prev = NULL;

    if ((*head) != NULL) /*if the list isn't empty, link head prev to new node*/
        (*head)->prev = newNode;

    (*head) = newNode;
}

void insertAfter(Node* prevNode, Step newStep)
{
	Node* tempNode = NULL;
	Node* newNode = NULL;
    assert(prevNode != NULL);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->step = newStep;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != NULL){  /*link the node after newNode*/
    	tempNode = newNode->next;
    	tempNode->prev = newNode;

       /* (newNode->next)->prev = newNode;*/
    }
}

void deleteLast(Node** head){

	Node* last = NULL;
	Node* beforeLast = NULL;
	last = *head;


	if (*head == NULL) { /*if list is empty, do nothing*/
		return;
	}

	if ((*head)->next == NULL) { /*if the list has only one node, make (*head) point at NULL*/
		free(*head);
		head = NULL;
	}
	while (last->next != NULL) /*search for the end of the list*/
		last = last->next;

	beforeLast = last->prev;
	free(last);					/*delete last node*/
	beforeLast->next = NULL;	/*make new last->next = NULL*/

	return;

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


void printNode(Node* node) {
	Step *step = node->step;
	printStep(step);
}

void printStep(Step* step) {
	printf("%d,%d: %d -> %d\n", step->i,step->j,step->old, step->new);
}


void printList(Node** head)
{
    Node* last = NULL;
    Node* node = *head;

    printf("printing list from start:\n");
    while (node != NULL) {
        printStep(node);
        last = node;
        node = node->next;
    }

    printf("end of list\n");
}

destroyNode(Node* node){
	return;
}

void destroyList(Node **head) {
	Node *curNode= NULL;
	Node *nextNode= NULL;
	curNode = *head;
	while(curNode!= NULL) {
		nextNode = curNode->next;
		free(curNode->step);
		free(curNode);
		curNode = nextNode;
	}

}

Step* createStep(int x, int y, int old, int new) {
	Step* step = (Step*)malloc(sizeof(Step));
	step->i = x;
	step->j = y;
	step->old = old;
	step->new = new;

	return step;
}
