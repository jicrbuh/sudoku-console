/*
 * newDLL.h
 *
 *  Created on: 6 Aug 2018
 *      Author: chen
 */

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

typedef struct Step{
	int i;
	int j;
	int old;
	int new;
	DLL* list;
} Step;

typedef struct Node  {
	Step* step;
	struct Node* next;
	struct Node* prev;
} Node;



typedef struct DLL {
	Node* head;
	Node* tail;
} DLL;

DLL* createEmptyList();
Step* createStep (int i, int j, int old, int new);
Node* createNode(Step *step);
Node* createNode(int i, int j, int old, int new);

void addLast(DLL* list, Step *step);
void addLast(DLL* list, int i, int j, int old, int new);
void addFirst (DLL* list, Step *step);
void addFirst(DLL* list, int i, int j, int old, int new);

void deleteFirst(DLL* list);
void deleteLast(DLL* list);
void deleteAllNextNodes(DLL* list, Node* node);


void printStep(Step* step);
void printList(DLL* list);
void printListFromTail(DLL* list);

void freeList (DLL* list);
void freeNode(Node* node);
void freeStep(Step* step);
#endif /* DOUBLY_LINKED_LIST_H_*/
