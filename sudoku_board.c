#include "sudoku_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyMatrix(int** orig, int** new, int size){
	int i,j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			new[i][j] = orig[i][j];
		}
	}
}

Board* createBoard(int blockHeight, int blockLength) {
	int** mtx = NULL;
	int boardSize = blockHeight*blockLength;
	Board* board = (Board *) calloc(boardSize,sizeof(Board));
	int i;

	if (board == NULL) {
		return NULL; /*if allocation failed, returns NULL*/
	}
	board->blockHeight=blockHeight;
	board->blockLength=blockLength;
	board->edgeSize=boardSize;

	/*allocate memory for the board's matrix*/
	mtx = calloc(boardSize, sizeof(int*));
	if (mtx == NULL) {
		return NULL; /*if allocation failed, returns NULL*/
	}
	for(i = 0;i < boardSize; i++) {
		mtx[i] = calloc(boardSize, sizeof(int));
	}
	board->matrix=mtx;

	return board;
}

/*creates a partial copy of board (only some parameters are copied:
 * blockHeight, blockLength, edgeSize, matrix, isFixed*/
Board* copyBoard(Board* board){
	Board* copied = createBoard(board->blockHeight, board->blockLength);

	if (copied == NULL) {
		return NULL; /*if allocation failed, returns NULL*/
	}

	copied->boardIsErroneous = board->boardIsErroneous;

	copyMatrix(board->matrix,copied->matrix,board->edgeSize);
	copyMatrix(board->isFixed, copied->isFixed, board->edgeSize);

	return copied;
}

/*changed all cells to fixed (if cell isn't empty)*/
void fixAll(Board* board) {
	int i,j;

	for (i=0; i<board->edgeSize; i++) {
		for (j=0; j<board->edgeSize; j++) {
			if (board->matrix[i][j] != 0) {
				board->isFixed[i][j] = 1;
			}
		}
	}

}

/*not sure if needed!*/
Board* deepCopy(Board* board) {
	return NULL;

}

void destroyBoard(Board* board){
	int i;
	/*frees the matrix*/
	for(i=0; i < board->edgeSize; i++ ) {
	    free(board->matrix[i]);
	}

	free(board->matrix);
	free(board);
}

void printBoard(Board* board){
/*board is NxN
 * n-by-m blocks (n rows of blocks, m columns of blocks)
 * board printing format has N+m+1 rows*/
	int i,j;
	printSeperatorRow(board);
	for (i=0 ; i<board->blockLength ; i++) {
		for (j=0 ; j<board->blockHeight ; j++) {
			printRow(board,j);
		}
		printSeperatorRow(board);
	}
}

void printCell(Board* board, int i, int j) {
	if (board->matrix[i][j] == 0) {
		printf("   ");
	}
	else {
		printf(" %2d", board->matrix[i][j]);
	}
	if (board->isFixed[i][j]) {
		printf(".");
	}
	else if (board->mode == 2 || board->markErrors == 1) {
		if (cellIsErr(board,i,j)) {
			printf("*");
		}
		else {
			printf(" ");
		}
	}
}

int isBoardErr(Board* board) {
	int i,j;
	for (i=0 ; i<board->edgeSize ; i++) {
		for (j=0 ; j<board->edgeSize ; j++) {
			if (isCellErr(board,i,j)) {
				return 1;
			}
		}
	}
	return 0;
}
void printRow(Board* board, int rowIdx) {
	int i;
	printf("|");
	for (i=0; i < board->edgeSize; i++) {
		printCell(board,rowIdx,i);
		if ((i+1)%board->blockLength == 0) {
			printf("|");
		}
	}
	printf("\n");
}

void printSeparatorRow(Board* board) {
	int i;
	for (i=0; i < (4*board->edgeSize + board->blockHeight +1); i++) {
		printf("-");
	}
	printf("\n");
}

int numberOfFilledCells(Board* board) {
/*returns the number of filled cells*/
	int i,j;
	int filledNum=0;
	for(i=0; i<board->edgeSize;i++){
		for(j=0;j < board->edgeSize;j++){
			if (board->matrix[i][j] != 0) {
				filledNum++;
			}
		}
	}
	return filledNum;
}

int numberOfBlankCells(Board* board) {
	return board->edgeSize*board->edgeSize - numberOfFilledCells(board);
}


/* Input:
 * A square matrix and its edge size
 *
 * Output:
 * None
 *
 * Description:
 * Sets all the values of matrix to 0*/

/*TODO b(clearMatrix) make sure the pointers stuff are OK and fix*/
void clearMatrix(int** matrix, int edgeSize) {
	int i,j;
	for (i=0 ; i<edgeSize ; i++) {
		for (j=0 ; j<edgeSize ; j++) {
			matrix[i][j] = 0;
		}
	}
}
