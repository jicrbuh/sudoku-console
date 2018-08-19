#include "sudoku_board.h"
#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*returns 1 if erroneous or 0 else*/
int isCellErr(Board* board, int x, int y) {
	if (isRowErr(board,x,y) || isColErr(board,x,y) || isBlockErr(board,x,y)) {
		return 1;
	}
	else {
		return 0;
	}
}

/*returns 1 if erroneous or 0 else*/
int isRowErr(Board* board, int x, int y){
	int i;
	for(i=0;i < board->edgeSize; i++) {
		if (board->matrix[x][i] == board->matrix[x][y]) {
			return 1;
		}
	}
	return 0;
}

/*returns 1 if erroneous or 0 else*/
int isColErr(Board* board, int x, int y){
	int i;
		for(i=0;i < board->edgeSize; i++) {
			if (board->matrix[i][y] == board->matrix[x][y]) {
				return 1;
			}
		}
	return 0;
}

/*returns 1 if erroneous or 0 else*/
int isBlockErr(Board* board, int x, int y){
	int i,j;
	/*[iStart,jStart] is the upper left coordinate of the block*/
	int iStart = board->blockLength*(x/board->blockLength);
	int jStart = board->blockHeight*(y/board->blockHeight);

	for (i=0;i < board->blockLength; i++) {
		for (j=0; j< board->blockHeight ; j++) {
			if (board->matrix[x][y] == board->matrix[iStart+i][jStart+j]) {
				return 1;
			}
		}
	}

	return 0;
}

/**/
void initStack(Board* board, DLL* stack) {
	int i,j;
	for (i=board->edgeSize ; i>0 ; i--) {
		for (j=board->edgeSize ; j>0 ; j--) {
			if (board->matrix[i][j] == 0) {
				/*push*/
				addFirst(stack,i,j,0,0);
			}
		}
	}
}

/* returns -1 if no possible value for cell i,j
 * otherwise returns the smallest value possible for the cell.*/
int solveCell(Board* board, int x, int y) {
	int i = board->matrix[x][y] + 1;
	while (i<board->edgeSize+1) {
		board->matrix[x][y] = i;
		if (isCellErr(board,x,y)) {
			i++;
		}
		else {
			return i;
		}
	}
	board->matrix[x][y] = 0;
	return -1;
}

int exBackTracking(Board* board){
	Board* boardCopy = NULL;
	Node* currNode = NULL;
	DLL* stack = createEmptyList();
	int solutionsNum = 0;
	boardCopy = copyBoard(board);
	/* if board allocation failed, return -999*/
	if (boardCopy == NULL) {
		return -999;
	}
	initStack(boardCopy,stack);
	currNode = stack->head;
	/*while stack isn't empty*/
	while (currNode != NULL) {
		/*if cell couldn't be filled - backtrack to previous cell*/
		if (solveCell(copyBoard, currNode->step->i, currNode->step->j) == -1) {
			currNode = currNode->prev;
		}
		/*if cell filled successfully*/
		else {
			/*if currNode is the last node then the board is successfuly filled hence increment solutionsNum*/
			if (currNode == stack->tail) {
				solutionsNum++;
			}
			/*if there are more cells to fill go to the next one*/
			else {
				currNode = currNode->next;
			}
		}
	}
	freeList(stack);
	freeBoard(copyBoard);
	return solutionsNum;
}
