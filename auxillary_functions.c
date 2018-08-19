#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sudoku_board.h"
#include "doubly_linked_list.h"

/*undo == 1 if last command was undo
 *undo == 0 if last command was redo*/
void printSetUndo(Board* board, int undo) {
	Node* revertedNode;
	if (undo) {
		revertedNode = board->currNode->next;
	}
	else {
		revertedNode = board->currNode;
	}
	if (revertedNode->step->new == 0 && revertedNode->step->old == 0) {
		if (undo) {
			printf("Undo %d,%d: from %s to %s\n", revertedNode->step->j,
							revertedNode->step->i, "_", "_");
		}
		else {
			printf("Redo %d,%d: from %s to %s\n", revertedNode->step->j,
							revertedNode->step->i, "_", "_");
		}

	}
	else if (revertedNode->step->new == 0 && revertedNode->step->old != 0) {
		if (undo) {
			printf("Undo %d,%d: from %s to %d\n", revertedNode->step->j,
							revertedNode->step->i, "_", revertedNode->step->old);
		}
		else {
			printf("Redo %d,%d: from %s to %d\n", revertedNode->step->j,
							revertedNode->step->i, "_", revertedNode->step->old);
		}
	}
	else if (revertedNode->step->new != 0 && revertedNode->step->old == 0) {
		if (undo) {
			printf("Undo %d,%d: from %d to %s\n", revertedNode->step->j,
							revertedNode->step->i, revertedNode->step->new, "_");
		}
		else {
			printf("Redo %d,%d: from %d to %s\n", revertedNode->step->j,
							revertedNode->step->i, revertedNode->step->new, "_");
		}

	}
	else {
		if (undo) {
			printf("Undo %d,%d: from %d to %d\n", revertedNode->step->j,
							revertedNode->step->i, revertedNode->step->new, revertedNode->step->old);
		}
		else {
			printf("Redo %d,%d: from %d to %d\n", revertedNode->step->j,
							revertedNode->step->i, revertedNode->step->new, revertedNode->step->old);
		}
	}
}

/*undo == 1 if last command was undo
 *undo == 0 if last command was redo*/
void printAutofillUndo(Board* board, int undo) {
	Node* innerNode;
	if (undo) {
		innerNode = board->currNode->next->step->list->tail;
	}
	else {
		innerNode = board->currNode->step->list->head;
	}
	while (innerNode != NULL) {
		if (innerNode->step->new == 0 && innerNode->step->old == 0) {
			if (undo) {
				printf("Undo %d,%d: from %s to %s\n", innerNode->step->j,
									innerNode->step->i, "_", "_");
			}
			else {
				printf("Redo %d,%d: from %s to %s\n", innerNode->step->j,
									innerNode->step->i, "_", "_");
			}
		}
		else if (innerNode->step->new == 0 && innerNode->step->old != 0) {
			if (undo) {
				printf("Undo %d,%d: from %s to %d\n", innerNode->step->j,
						innerNode->step->i, "_", innerNode->step->old);
			}
			else {
				printf("Redo %d,%d: from %s to %d\n", innerNode->step->j,
						innerNode->step->i, "_", innerNode->step->old);
			}
		}
		else if (innerNode->step->new != 0 && innerNode->step->old == 0) {
			if (undo) {
				printf("Undo %d,%d: from %d to %s\n", innerNode->step->j,
						innerNode->step->i, innerNode->step->new, "_");
			}
			else {
				printf("Redo %d,%d: from %d to %s\n", innerNode->step->j,
						innerNode->step->i, innerNode->step->new, "_");
			}

		}
		else {
			if (undo) {
				printf("Undo %d,%d: from %d to %d\n", innerNode->step->j,
						innerNode->step->i, innerNode->step->new, innerNode->step->old);
			}
			else {
				printf("Redo %d,%d: from %d to %d\n", innerNode->step->j,
						innerNode->step->i, innerNode->step->new, innerNode->step->old);
			}
		}
		if (undo) {
			innerNode = innerNode->prev;
		}
		else {
			innerNode = innerNode->next;
		}
	}
}

/*todo probably need to change to Board**
 * or to add to sudoku_board.c functions that alter the matrix size*/
int loadToBoard(FILE* fptr, Board* board) {

	/*implement by the instructions in "files format"*/

	/*resets doubly-linked list*/
	int intFromFile,i,j, inputRead;

	/*loads n, m into board*/
	inputRead = fscanf (fptr, "%d", &intFromFile);
	board->blockLength=intFromFile;
	assert(inputRead > 0);

	inputRead = fscanf (fptr, "%d", &intFromFile);
	board->blockHeight=intFromFile;
	assert(inputRead > 0);

	/*changes edgesize according to n,m*/
	board->edgeSize=board->blockHeight*board->blockLength;

	/*maybe frees and recreates matrix, isFixed, etc to the correct size*/
	resizeMatrices(board);

	/*loads cell values into board*/
	for (i=0; i< board->edgeSize; i++) {
		for (j=0; j<board->edgeSize; j++) {
			inputRead = fscanf (fptr, "%d", &intFromFile);
			assert(inputRead > 0);
			board->matrix[i][j] = intFromFile;
		}
	}

	fclose (fptr);
	return 0;
}
/*TODO b add print-board when implementing "new puzzle"*/
int resetBoard(Board* board) {
	return board->blockHeight; /*TODO resetBoard after implementing doubly linked list*/
}

int markAllErrors(Board* board) {
	/*Not sure we need but maybe we will need
	 * marks all the errors on the board*/
	return board->blockHeight;
}
/*note for us: deleted function named isXYErroneous because it is a duplicate of cellIsErroneous*/
int cellIsErroneous(Board* board, int x, int y) {
	/*TODO complete is erroneous function
	 * Called by */
	return board->blockHeight+x+y;
}

int fillXRandomCells(Board* board, int x) {
	int i, row, col, val;
	for (i=0 ; i<x ; i++) {
		int row = rand() % (board->edgeSize);
		int col = rand() % (board->edgeSize);
		int val = rand() % (board->edgeSize);
		board->matrix[row][col] = val;
	}
	return board->blockHeight+x;
}

int ILPSolver(Board* board) {
	return board->blockHeight;
}

int exhaustiveBackTracking(Board* board) {
	return board->blockHeight; /*returns number of solutions*/
}

int eraseAllButYRandomCells(Board* board, int y) {
	return board->blockHeight+y;
}

int saveToFile(FILE* fptr,Board* board) { /*TODO in loading remember to take care of files with multiple spaces between cells*/
	/*if in edit mode, save all cells as fixed*/
	int i,j;
	fprintf(fptr,"%d %d\n",board->blockLength,board->blockHeight);
	for (i=0 ; i<board->edgeSize ; i++) {
		for (j=0 ; j<board->edgeSize ; j++) {
			if (j == board->edgeSize-1) {
				if (board->mode == 2) {
					fprintf(fptr,"%d.\n",board[i][j]);
				}
				else {
					fprintf(fptr,"%d\n",board[i][j]);
				}
			}
			else {
				if (board->mode == 2) {
					fprintf(fptr,"%d. ",board[i][j]);
				}
				else {
					fprintf(fptr,"%d ",board[i][j]);
				}
			}
		}
	}
	return 0;
}

/*
 *
 * Called by:
 * autofill(Board* board) from module game_logic.c
 *
 * Input:
 * Board and cell coordinates - x for the column and y for the row
 *
 * Output:
 * 0 - if the cell has more than one possible values
 * the only possible value - otherwise
 *
 * Remark:
 * Output > 0 iff the cell has one possible solution
 *
 * */
int cellHasOnePossibleValue(Board* board,int x,int y) {
	return board->blockHeight+x+y;
}
