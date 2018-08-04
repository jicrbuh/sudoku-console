#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

int main(){

	Node** head = NULL; /* head will point to the first node of the list*/
	Step* step = createStep(1,2,3,4); /*Step: cell 1,2 changed from 3 to 4*/
	printStep(step); /*this prints the step to stdio*/
	insertFirst(head, step); /*inserts a new node with step data as the first node*/
	printList(head); /*prints the list from head node and forward*/
	step = createStep(1,1,1,1); /*creates a new step*/
	insertLast(head, step); /*inserts the new step last*/
	printList(head);
	deleteLast(head); /*deletes the last node of the list starting at head*/
	printList(head);





}
