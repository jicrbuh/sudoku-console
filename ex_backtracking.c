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

int exBackTracking(Board* board){
	int** boardCopy = NULL;
	DLL* stack = createEmptyList();
	int solutionsNum = 0;


	boardCopy = copyBoard(board);
	if (boardCopy == NULL) { /* if board allocation failed, return -2*/
		return -2;
	}


	return 666;
}
