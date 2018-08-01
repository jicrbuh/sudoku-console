/*
 * sudoku_board.h
 *
 *  Created on: 14 Jul 2018
 *      Author: chen
 */

#ifndef SUDOKU_BOARD_H_
#define SUDOKU_BOARD_H_

typedef struct board_t {
	int block_height;
	int block_length;
	int edge_size;
	int** matrix;
	int** isErroneaous;
	int** isFixed;
	int state;

} Board;

/*
 * creates an empty Board with block_height and block_length.
 * the board is initialized to '0'
 * returns a pointer to the board, or NULL if memory allocation failed
 * */
Board* createBoard(int block_height, int block_length);
Board* copyBoard(Board* board);
void destroyBoard(Board* board);
void printBoard(Board* board);

#endif /* SUDOKU_BOARD_H_ */
