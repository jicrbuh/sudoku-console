#include "sudoku_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*use this https://stackoverflow.com/questions/105653/int-matrix-with-pointers-in-c-memory-allocation-confusion*/
Board* createBoard(int blockHeight, int blockLength, int** mtx) {

	Board board = (Board *) calloc(sizeof(Board));
	if (board == NULL) {
		return NULL;
	}
	board->block_height=blockHeight;
	board->block_length=blockLength;

	int boardSize = blockHeight*blockLength;
	mtx = calloc(boardSize, 1+sizeof(int*)); /* alloc one extra ptr*/
	if (mtx == NULL) {
		return NULL;
	}
	for(int i = 0;i<boardSize;i++) {
		mtx[i] = calloc(boardSize, sizeof(int));
	}
	mtx[boardSize] = NULL; /* set the extra ptr to NULL*/
	for(int i = 0;i<boardSize;i++) {
		for(int j = 0;j<boardSize;j++) {
			mtx[i][j] = i*boardSize+j;
		}
	}
	board.matrix=mtx;

	return board;

	return NULL;
}
Board* copyBoard(Board* board){
	return NULL;
}
void destroyBoard(Board* board){

	for( int i=0; board[i] != NULL; i++ ) {
	    free(board[i]);
	}
	free(board->matrix);
	free(board->block_height); /*maybe can't free those because they aren't pointers?*/
	free(board->block_length);
}
void printBoard(Board* board){

}
void printBoard(Board* board){

}
