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
	int** matrix;
} Board;

Board* createBoard(int block_height, int block_length, int** matrix);
Board* copyBoard(Board* board);
void destroyBoard(Board* board);
void printBoard(Board* board);

#endif /* SUDOKU_BOARD_H_ */
