/*
 * game_logic.h
 *
 *  Created on: 3 Aug 2018
 *      Author: chen
 */

#ifndef GAME_LOGIC_H_
#define GAME_LOGIC_H_

#include "sudoku_board.h"

/*
 * Description:
 * Loads a puzzle from a file and enters solve mode
 *
 * Input:
 * fileName = a path, full or relative, and the Sudoku board
 *
 * Output:
 * -1 if the file didn't open successfully
 *  1 otherwise and this means the function successfully finished
 *
 * */
int solve(char* fileName, Board* board);

/*
 * Description:
 * Loads a puzzle from a file and enters edit mode
 *
 * Input:
 * fileName = a path, full or relative, and the Sudoku board
 *
 * Output:
 * -2 if the file didn't open successfully
 *  1 otherwise and this means the function successfully finished
 *
 * */
int edit(char* fileName, Board* board);

/*
 *
 * Description:
 * sets the mark errors field on/off
 *
 * Input:
 * x - the value to set the mark errors field to and the board
 *
 * Output:
 * -3 if x is not 0 or 1
 *  1 otherwise and this means the function successfully finished
 *
 * */
int mark_errors(int x, Board* board);

/*
 *
 * Description:
 * Prints the board to the user
 *
 * Input:
 * The Sudoku board
 *
 * Output:
 * always 1 - to be consistent with a successful exit from a function
 *
 * */
int print_board(Board* board);

/*
 * Description:
 * Determines whether the board is:
 * 1) erroneous
 * 2) not erroneous but unsolvable
 * 3) not erroneous and solvable
 *
 * Input:
 * The Sudoku board
 *
 * Output:
 * 1) -6
 * 2) -7
 * 3) 2
 *
 * */
int validate(Board* board);

/*
 * Description:
 * Sets the value of cell x,y to z or empties a cell by using z==0.
 * If the board is finished successfully the function restarts the game to init mode.
 *
 * Input:
 * x,y - coordinates of a cell, x for row and y for column
 * z - a value to be set in cell x,y
 * The Sudoku board
 *
 * Output:
 * -4 if the x,y or z are not in range
 * -5 if cell x,y is fixed
 * 10 if the board is full and correct
 *  9 if the board is full but erroneous
 *
 * */
int set(int x, int y, int z, Board* board);

/*
 * Description:
 * Generates a solvable board with y empty cells
 *
 * Input:
 * x - number of cells to fill before running ILP
 * y - number of cells to delete after running ILP
 * The Sudoku board
 *
 * Output:
 * -10 if the function failed to generate the board
 *  1 if the process ended successfully
 *
 *  */
int generate(Board* board, int x, int y);
int undo(Board* board);
int redo(Board* board);
int save(Board* board, char* fileName);
int hint(Board* board, int x, int y);
int num_solutions(Board* board);
int autofill(Board* board, int firstCall, int x, int y, int z);
int reset(Board* board);
int userExit(Board* board);


#endif /* GAME_LOGIC_H_ */
