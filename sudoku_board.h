/*
 * sudoku_board.h
 *
 *  Created on: 14 Jul 2018
 *      Author: chen
 */

#ifndef SUDOKU_BOARD_H_
#define SUDOKU_BOARD_H_

typedef struct board_t {

	int blockHeight;

	int blockLength;

	int edgeSize;

	/* 0 - init, 1 - solve, 2 - edit*/
	int mode;

	/* 1 - errors are marked, 0 - errors are not marked*/
	int markErrors;

	/* 1 - there is at least one erroneous value, 0 - no erroneous values*/
	int boardIsErroneous;

	/* the number of solutions to the board according to the last call to num_solutions command*/
	int lastNumOfSolutions;

	/* last set in autofill - used to print the information about the last set operation*/
	int lastXSet;
	int lastYSet;

	/* last hint given */
	int lastHint;

	/* a matrix with the dimensions of the board which contains in each cell:
	 * the single legal value this cell can have according to the board
	 * or 0 if the number of legal values for the cell is not 1.
	 * all this, according to the last call to the command autofill*/
	int** lastAutofillMatrix;

	/* the matrix that represents the sudoku board*/
	int** matrix;

	/* a matrix with the dimensions of the board which contains is each cell:
	 * 1 - if the cell is erroneous, 0 - otherwise*/
	int** isErroneous;

	/* a matrix with the dimensions of the board which contains is each cell:
	 * 1 - if the cell is fixed, 0 - otherwise*/
	int** isFixed;

	/* points to the current state of the sudoku board according to the doubly linked list */
	Node* currNode;

	/* a doubly linked list of type Node* that describes the moves */
	DLL* movesList;

} Board;

/*TODO documentation update for sudoku_board.h
 * creates an empty Board with block_height and block_length.
 * the board is initialized to '0'
 * returns a pointer to the board, or NULL if memory allocation failed
 * */
Board* createBoard(int block_height, int block_length);
Board* copyBoard(Board* board);
void destroyBoard(Board* board);
void printBoard(Board* board);
void clearBoard(Board* board);
void resizeMatrices(Board* board);

#endif /* SUDOKU_BOARD_H_ */
