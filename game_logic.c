#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku_board.h"
#include "doubly_linked_list.h"
#include "auxillary_functions.h"

int solve(char* fileName, Board* board) {
	/*filename - full or relative*/
	/*if file not opened return -1*/
	/*changed the mode to solve (1)*/
	/*available in all modes*/
	/*resets doubly linked list*/
	/*change to correct mode*/
	FILE* file = NULL;
	file = fopen(fileName,"r"); /*check if opened successfully*/
	if (file == NULL) {
		return -1;
	}
	loadToBoard(file,board);
	board->mode = 1;
	return 1;
}

int edit(char* fileName, Board* board) {
	/*filename - full or relative*/
	/*filename \0 - empty board*/
	/*if file not opened return -2*/
	/*changed the mode to edit (2)*/
	/*available in all modes*/

	FILE* file = NULL;
	if (fileName == NULL) {
		initAsDefaultBoard(board);
		board->mode = 2;
		return 1;
	}
	file = fopen(fileName,"r"); /*check if opened successfully*/
	if (file == NULL) {
		return -2;
	}
	loadToBoard(file,board);
	board->mode = 2;
	return 1;
}

int mark_errors(int x, Board* board) {
	/*verify that x is 1 or 0, else return error value*/
	if (x != 0 && x != 1) {
		return -3;
	}
	board->markErrors = x;
	return 1;
}

int print_board(Board* board) {
	/*available in solve, edit (1,2) mode*/
	printBoard(board);
	return 1;
}

int validate(Board* board) {
	/*check if the board is erroneous, namely, it has 2 cells with same number which are neighbors
	 * if it is erroneous - error (-6)
	 * if it is unsolvable - error(-7)
	 * else, it is valid - message(2) */
	if (isBoardErr(board)) {
		return -6;
	}
	if (1==1) { /*check with ILP if the board is solvable (if it is, go in the if statement)*/
		return 2;
	}
	return -7;
}

int set(int x, int y, int z, Board* board) {
	/*available in solve, edit (1,2) mode
	 * if x,y,z not in range error (-4)
	 * if x,y, fixed (-5)*/
	int oldval;
	/*check if x,y,z are in range*/
	if (x<0 || y<0 || z<0 || x > board->edgeSize-1 || y > board->edgeSize-1 || z > board->edgeSize) {
		return -4;
	}
	/*check if cell is fixed*/
	if (board->isFixed[x][y] == 1) {
		return -5;
	}
	oldval = board->matrix[x][y];
	/*set the value*/
	board->matrix[x][y] = z;
	/*delete all redo moves (all moves after currNode)*/
	deleteAllNextNodes(board->movesList, board->currNode);

	/*add move to the end of the list*/
	addLast(board->movesList, createNode(createStep(x,y,oldval,z,NULL)));

	/*update the tail of the list*/
	board->currNode = board->movesList->tail;

	print_board(board);
	if (board->mode == 1) { /*if we are in solve mode*/
		if (numberOfFilledCells(board) == board->edgeSize*board->edgeSize) { /*if board is full*/
			if (!isBoardErr(board)) {
				board->mode = 0;
				clearList(board->movesList);
				return 10;
			}
			else {
				return 9;
			}
		}
	}
	return 666; /*shouldn't get here, somthing's wrong*/
}

int generate(Board* board, int x, int y) {
	/*if 1000 iterations fail - error (-10)*/
	int errorCounter = 0;
	while (errorCounter < 1000) {
		clearMatrix(board->matrix,board->edgeSize);
		fillXRandomCells(board,x);
		if (ILPSolver(board)){
			eraseAllButYRandomCells(board,y);
			return 1;
		}
		errorCounter++;
	}
	return -10;
}

int undo(Board* board) {
	/*if no moves to undo - error (-11)*/
	if (board->currNode == NULL) {
		return -11;
	}
	/*else if the last command was set (and not autofill) change the values*/
	else if (board->currNode->step->list == NULL) {
		board->matrix[board->currNode->step->i][board->currNode->step->j] = board->currNode->step->old;
	}
	/*else the command is autofill iterate over the list of autofill sets from tail to headand undo them*/
	else {
		Node* innerNode = board->currNode->step->list->tail;
		while (innerNode != NULL) {
			board->matrix[innerNode->step->i][innerNode->step->j] = innerNode->step->old;
			innerNode = innerNode->prev;
		}
	}
	/*move currNode one step backwards*/
	board->currNode = board->currNode->prev;
	return 4;
}

int redo(Board* board) {
	/*if no moves to redo - error (-12)*/
	if (board->currNode->next == NULL || (board->currNode == NULL && board->movesList->head == NULL)) {
		return -12;
	}
	/*currNode is updated to be the node it should be when exiting the function*/
	else if (board->currNode == NULL && board->movesList->head != NULL) {
		board->currNode = board->movesList->head;
	}
	else {
		board->currNode = board->currNode->next;
	}
	/*else if the last undo was set (and not autofill) change the value*/
	if (board->currNode->step->list == NULL) {
		board->matrix[board->currNode->step->i][board->currNode->step->j] = board->currNode->step->new;
	}
	/*else the command is autofill iterate over the list of autofill sets from tail to headand undo them*/
	else {
		Node* innerNode = board->currNode->step->list->head;
		while (innerNode != NULL) {
			board->matrix[innerNode->step->i][innerNode->step->j] = innerNode->step->new;
			innerNode = innerNode->next;
		}
	}
	return 4;
}

int save(Board* board, char* fileName) {
	/*if in edit mode there are 2 possible errors:
	 * 1) if board is erroneous - error (-6)
	 * 2) if it is unsolvable - error (-13)
	 * error that can happen in every mode:
	 * if the file saving fails - error (-14)
	 * if the process finished without problems parse_command will send the corresponding message
	 */
	FILE* fptr = NULL;
	fptr = fopen(fileName, "w");

	if (board->mode == 2) {
		if (isBoardErr(board)) {
			return -6;
		}
		if (!validate(board)) {
			return -13;
		}
	}
	if (fptr == NULL) {
		return -14;
	}
	saveToFile(fptr,board);
	return 1;
}

int hint(Board* board, int x, int y) {
	/*check for the following errors:
	 * 1) check if x or y are out of range (1-N) - error (-4)
	 * 2) check if board has erroneous values - error (-6)
	 * [erroneous values means neighbors with same value]
	 * 3) check if cell (x,y) is fixed - error (-5)
	 * 4) check if cell (x,y) already contains a value - error (-14)
	 * [run ILP now]
	 * 5) if board is unsolvable - error (-15)
	 *
	 * if no error occurred return the value the ILP suggested for cell (x,y) - message (5) + the value!
	 * */
	if (x<0 || y<0 || x > board->edgeSize-1 || y > board->edgeSize-1) {
		return -4;
	}
	if (isBoardErr(board)) {
		return -6;
	}
	if (board->isFixed[x][y]) {
		return -5;
	}
	if (board->matrix[x][y] != 0) {
		return -14;
	}
	if (!ILPSolver(board)) {
		return -15;
	}
	/*TODO after ILP update board->lastHint*/
	return 5;
}

int num_solutions(Board* board) {
	/*check for the following errors:
	 * 1) check if board has erroneous values - error (-6)
	 * [now run exhaustive backtracking which should return the number of solutions]
	 * if no error - message (6) + the value*/
	if (isBoardErr(board)) {
		return -6;
	}
	board->lastNumOfSolutions = exBackTracking(board);
	return 6;
}

int autofill(Board* board, int firstCall, int x, int y, int z) {
	/*check if board has erroneous values - error (-6)*/
	int i,j,val;
	if (isBoardErr(board)) {
		if (!firstCall) printf("PROBLEM: board shouldn't be erroneous in this stage"); /*TODO ZZZ for debug ZZZ*/
		return -6;
	}
	/*if autofill is called by parseCommand (which means it is the first call in the autofill sequence)
	 *then we reset the autofill fields in the board struct, and fill in the new values to these fields */
	if (firstCall) {
		DLL* innerList = createEmptyList();

		/*add all sets in the autofill to innerList*/
		for (i=0 ; i < board->edgeSize; i++) {
			for (j=0 ; j < board->edgeSize ; j++) {
				val = cellHasOnePossibleValue(board,i,j);
				if (val > 0) {
					addLast(innerList,createNode(createStep(i,j,board->matrix[i][j],val,NULL)));
				}
			}
		}
		/* add the list of sets as a single move.
		 * Remark: this add is performed before all the autofill sets in list are done, but it isn't a problem
		 * because no new moves can be done before all the autofill sets in list are done.*/
		addLast(board->movesList, createNode(createStep(0,0,0,0,innerList)));
		return 11;
	}
	else {
		board->matrix[x][y] = z;
		return 11;
	}
}

int reset(Board* board) {
	while (board->currNode != NULL) {
		undo(board);
	}
	clearList(board->movesList);
	return 7;
}

int userExit(Board* board) {
	/*message (8)*/
	/*TODO exit function - free resources, implement after we are sure of all the resources in the program*/
	return board->blockHeight;
}
/*TODO when finishing implementing the functions update the arguments of the functions in the user interface calls functions from here*/
/*calls the right function from game_logic*/
/*prints errors for specific functions*/
/*switch case for printing different errors, starting from -1*/ /*all input can has more parameters than needed and be ok*/

/*solve(x) - x is not empty
 * error (-1) "Error: File doesn't exist or cannot be opened\n"*/

/*edit(x) - x can be empty (\0) or filename
 * error (-2) "Error: File cannot be opened\n" */

/*mark_errors(x) - x should be 0 or 1. mode solve (1)
* handled by parse_command: error (-3) "Error: the error should be 0 or 1\n" */

/*print_board() - no parameteres
* only available in edit and solve modes */

/*set(x,y,z) - available in solve, edit (1,2) mode
 * checks if x,y,z are ints
 * if x,y,z not in range error (-4) "Error: value not in range 0-N\n
 * if x,y is fixed error (-5) "Error: cell is fixed\n"*/
