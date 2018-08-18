#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

int main(){

	DLL* list = createEmptyList();
	Step* step = createStep(1,1,1,1);
	Node* node = NULL;

	addLastStep(list, step);
	step = createStep(2,2,2,2);

	addLastStep(list, step);
	printList(list);

	step = createStep(3,3,3,3);
	addFirstListStep(list,step);
	printList(list);


	node = list->head;
	deleteAllNextNodes(list, node);
	printList(list);

	freeList(list);
	return 1;





}
