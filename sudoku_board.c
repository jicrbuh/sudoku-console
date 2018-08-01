#include "sudoku_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Board* createBoard(int blockHeight, int blockLength) {
	Board board = (Board *) calloc(sizeof(Board));
	int** mtx = NULL;
	int boardSize = blockHeight*blockLength;
	int i;

	if (board == NULL) {
		return NULL; /*if allocation failed, returns NULL*/
	}
	board->block_height=blockHeight;
	board->block_length=blockLength;
	board->edge_size=boardSize;

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

Board* copyBoard(Board* board){
	Board* copied = createBoard(board->block_height, board->block_length);
	if (copied == NULL) {
		return NULL; /*if allocation failed, returns NULL*/
	}
	copyMatrix(board,copied,board->edge_size);
	return copied;
}
void destroyBoard(Board* board){
	int i;
	/*frees the matrix*/
	for(i=0; i < board->edge_size; i++ ) {
	    free(board->matrix[i]);
	}

	free(board->matrix);
	free(board->block_height); /*maybe can't free those because they aren't pointers?*/
	free(board->block_length);
	free(board);
}
void printBoard(Board* board){
/*board is NxN
 * n-by-m blocks (n rows of blocks, m columns of blocks)
 * board printing format has N+n+1 rows*/
	printSeparatorRow(board->block_height,board->edge_size);
	printCellRow(board, 1);
}

/*todo should know if in edit mode or not! maybe add to the struct?*/
void printCell(Board* board, int i, int j) {
	if (board->state == 0) {

	}

}

void printCellRow(Board* board, int rowIdx) {
	int i;
	printf("|");
	for (i=0; i < board->edge_size; i++) {
		printf("%2d",board->matrix[rowIdx][i]);
		if ((i+1)%board->block_length == 0) {
			printf("|");
		}
	}
	printf("\n");

}

void printSeparatorRow(int n, int N) {
	int i;

	for (i=0; i < (4*N + n +1); i++) {
		printf("-");
	}
	printf("\n");
}

int numberOfFilledCells(Board* board) {
/*returns the number of filled cells*/
	int i,j;
	int filledNum=0;
	for(i=0; i<board->edge_size;i++){
		for(j=0;j < board->edge_size;j++){
			if (board->matrix[i][j] != 0) {
				filledNum++;
			}
		}
	}
	return filledNum;
}

int numberOfBlankCells(Board* board) {
	return board->edge_size*board->edge_size - numberOfFilledCells(board);
}

void copyMatrix(int** orig, int** new, int size){
	int i,j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			new[i][j] = orig[i][j];
		}
	}
}
