/*
 * newDLL.c
 *
 *  Created on: 6 Aug 2018
 *      Author: chen
 */
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <assert.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

DLL* createEmptyList() {
	DLL* list = (DLL*)malloc(sizeof(DLL));
	list->head=NULL;
	list->tail=NULL;


	return list;
}

void printList(DLL* list) {

	Node* node = NULL;
	assert(list != NULL);
	printf("\nprinting list from beginning:\n");
	if(list->head == NULL) {
		printf("list if empty\n");
	}
	else {
		node = list->head;
		while(node != NULL) {
			printStep(node->step);
			node =(Node*) node->next;
		}
	}
	printf("\n");
}

void printListFromTail(DLL* list) {

	Node* node = NULL;
	assert(list != NULL);
	printf("\nprinting list from tail:\n");
	if(list->head == NULL) {
		printf("list if empty\n");
	}
	else {
		node = list->tail;
		while(node != NULL) {
			printStep(node->step);
			node = node->prev;
		}
	}
	printf("\n");
}

void freeStep(Step* step) {
	free(step);
}

void freeNode(Node* node) {
	freeStep(node->step);
	free(node);
}

void freeList (DLL* list) {
	Node* curr = NULL;
	Node* next = NULL;

	curr = list->head;
	while (curr != NULL) {
		next = curr->next;
		freeNode(curr);
		curr = next;
	}
	free(list);

}

Step* createStep (int i, int j, int old, int new) {
	Step* step = (Step*)malloc(sizeof(Step));

	step->i = i;
	step->j = j;
	step->old = old;
	step->new = new;

	return step;
}

void printStep(Step* step) {
	printf("(%d,%d): %d -> %d\n", step->i,step->j,step->old,step->new);
}

Node* createNode(int i, int j, int old, int new) {
	Node* node = NULL;
	Step* step = createStep(i,j,old,new);

	return createNode(step);
}

Node* createNode(Step *step) {
	Node* node = NULL;

	node = (Node*)malloc(sizeof(Node));/*change the node->step to point at step*/
	node->next = NULL;
	node->prev = NULL;
	node->step = step;
	return node;
}

void addLast(DLL* list, Step *step) {
	Node* node = createNode(step);
	printf("adding node to the tail of the list\n");
	if (list->head == NULL) { /*if the list is empty*/
		assert(list->tail == NULL); /*if head is null, tail should be null, because list is empty*/
		list->head = node;
		list->tail = node;
	}
	else { /*if list isn't empty*/
		(list->tail)->next =  node;
		node->prev = (Node*) list->tail;
		list->tail = node;
	}
}

void addLast(DLL* list, int i, int j, int old, int new) {
	Step* step = createStep( i,  j,  old,  new);
	addLast(list, step);
}

void addFirst (DLL* list, Step *step) {

	Node* node = createNode(step);
	printf("adding node to the head of the list\n");
	if (list->head == NULL) { /*if the list is empty*/
			assert(list->tail == NULL); /*if head is null, tail should be null, because list is empty*/
			list->head = node;
			list->tail = node;
		}

	else { /*if list isn't empty*/
		(list->head)->prev = node;
		node->next = list->head;

		list->head = node;
		node->prev = NULL;
	}
}

void addFirst(DLL* list, int i, int j, int old, int new) {
	Step* step = createStep( i,  j,  old,  new);
	addFirst(list, step);
}

void deleteAllNextNodes(DLL* list, Node* node) {
	Node* curr = NULL;
	Node* next = NULL;

	list->tail = node; /*node will be the last in the list*/

	curr = node->next;
	node->next = NULL;
	while (curr != NULL) {/*deleteing all nodes after node*/
		next = curr->next;
		freeNode(curr);
		curr = next;
	}
}

void deleteLast(DLL* list) {
	Node* node = NULL;
	printf("deleting last node\n");
	if (list->head == NULL) { /*if list is empty, do nothing*/
		printf("attempting to delete last item of an empty list");
		return;
	}
	else {
		node = list->tail;
		list->tail = node->prev;
		(list->tail)->next = NULL;
		freeNode(node);
	}
}

void deleteFirst(DLL* list) {
	Node* node = NULL;
	printf("deleting first node\n");
	if (list->head == NULL) { /*if list is empty, do nothing*/
		printf("attempting to delete first item of an empty list");
		return;
	}
	else {
		node = list->head; /*saving first node pointer*/
		list->head = node->next; /*first node is now the next node*/
		(list->head)->prev = NULL; /*there's nothing before the first node*/
		list->head->next = node->next->next; /*connecting the head->next to the right node*/
		freeNode(node);
	}
}
