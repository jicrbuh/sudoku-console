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
	struct DLL* list;
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

/*
 * Input:
 * None
 *
 * Output:
 * Empty doubly linked list */
DLL* createEmptyList();

/*
 * Input:
 * i,j - coordinates of the cell in the board, i for row, j - for column.
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 *
 * Output:
 * a pointer to the step described above */
Step* createStep (int i, int j, int old, int new);

/*
 * Input:
 * i,j - coordinates of the cell in the board, i for row, j - for column.
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 * list - a doubly linked list.
 *
 * Output:
 * a pointer to the step described above */
Step* createListStep (int i, int j, int old, int new, DLL* list);

/* Input:
 * a Step
 *
 * Output:
 * Node* that points to Step */
Node* createNodeByStep(Step *step);

/*
 * Input:
 * i,j - coordinates of the cell in the board, i for row, j - for column.
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 *
 * Output:
 * Node that points to createStep(i, j, old, new, list) */
Node* createListNode(int i, int j, int old, int new, DLL* list);

/*
 * Input:
 * i,j - coordinates of the cell in the board, i for row, j - for column.
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 *
 * Output:
 * Node that points to createStep(i, j, old, new) */
Node* createNode(int i, int j, int old, int new);

/* Input:
 * pointer to a doubly linked list, step - pointer to a step to be added as the content of a new last node
 *
 * Output:
 * None
 *
 * Description:
 * adds a node to the end of list*/
void addLastStep(DLL* list, Step *step);

/* Input:
 * pointer to a doubly linked list,
 * i,j - coordinates of the cell in the board, i for row, j - for column that
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 *
 * Output:
 * None
 *
 * Description:
 * adds a node to the end of list*/
void addLast(DLL* list, int i, int j, int old, int new);

/* Input:
 * list - pointer to a doubly linked list,
 * i,j - coordinates of the cell in the board, i for row, j - for column that
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 * innerList - pointer to inner doubly linked list.
 *
 * Output:
 * None
 *
 * Description:
 * adds a node to the end of list*/
void addLastList(DLL* list, int i, int j, int old, int new, DLL* innerList);

/* Input:
 * pointer to a doubly linked list, step - pointer to a step to be added as the content of a new last node
 *
 * Output:
 * None
 *
 * Description:
 * adds a node to the beginning of list*/
void addFirstListStep (DLL* list, Step *step);

/* Input:
 * pointer to a doubly linked list,
 * i,j - coordinates of the cell in the board, i for row, j - for column that
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 *
 * Output:
 * None
 *
 * Description:
 * adds a node to the beginning of list*/
void addFirst(DLL* list, int i, int j, int old, int new);

/* Input:
 * list - pointer to a doubly linked list.
 * i,j - coordinates of the cell in the board, i for row, j - for column that
 * new - matrix[i][j] current value, old - matrix[i][j] as was before added the new value.
 * innerList - pointer to inner doubly linked list
 *
 * Output:
 * None
 *
 * Description:
 * adds a node to the beginning of list*/
void addFirstList(DLL* list, int i, int j, int old, int new, DLL* innerList);

/* Input:
 * Doubly linked list
 *
 * Output:
 * None
 *
 * Description:
 * deletes the first node in list and frees all resources used by the node*/
void deleteFirst(DLL* list);

/* Input:
 * Doubly linked list
 *
 * Output:
 * None
 *
 * Description:
 * deletes the last node in list and frees all resources used by the node*/
void deleteLast(DLL* list);

/* Input:
 * list - doubly linked list, node - the node to be last after the operation
 *
 * Output:
 * None
 *
 * Description:
 * deletes all the nodes after node (not including node),
 * and frees all resources used by all the deleted nodes*/
void deleteAllNextNodes(DLL* list, Node* node);

/* Input:
 * step - a step to be printed
 *
 * Output:
 * None
 *
 * Description:
 * prints step in the following format:
 * "(i,j): old -> new\n"*/
void printStep(Step* step);

/* Input:
 * list - a list to be printed
 *
 * Output:
 * None
 *
 * Description:
 * calls printStep(step) for all the nodes' steps in list from first to last */
void printList(DLL* list);

/* Input:
 * list - a list to be printed
 *
 * Output:
 * None
 *
 * Description:
 * calls printStep(step) for all the nodes' steps in list from last to first */
void printListFromTail(DLL* list);

/* Input:
 * a doubly linked list
 *
 * Output:
 * None
 *
 * Description:
 * frees all resources used by the list */
void freeList (DLL* list);

/* Input:
 * node - a list to be printed
 *
 * Output:
 * None
 *
 * Description:
 * frees all resources used by the node */
void freeNode(Node* node);

/* Input:
 * node - a list to be printed
 *
 * Output:
 * None
 *
 * Description:
 * frees all resources used by the step */
void freeStep(Step* step);

#endif /* DOUBLY_LINKED_LIST_H_*/
