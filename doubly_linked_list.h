/*
 * doubly_linked_list.h
 *
 *  Created on: 4 Aug 2018
 *      Author: chen
 */

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

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


void insertFirst(Node** head, Step newStep);
void insertAfter(Node* prevNode, Step newStep);
void deleteLast(Node** head);
void insertLast(Node** head, Step step);
void printNode(Node* node);
void printStep(Node* node);
void printList(Node** node);
void destroyNode(Node* node);
void destroyList(Node *head);
Step* createStep(int x, int y, int old, int new);



#endif /* DOUBLY_LINKED_LIST_H_ */
