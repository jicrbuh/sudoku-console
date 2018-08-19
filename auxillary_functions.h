/*
 * auxillary_functions.h
 *
 *  Created on: 3 Aug 2018
 *      Author: chen
 */

#ifndef AUXILLARY_FUNCTIONS_H_
#define AUXILLARY_FUNCTIONS_H_

/*
 *
 * Description:
 * Checks whether cell x,y is erroneous
 *
 * Input:
 * Board and cell coordinates - x for the row and y for the column
 *
 * Output:
 * 1 if cell x,y is erroneous
 * 0 otherwise
 *
 * */
int isCellErr(Board* board, int x, int y);


/*
 *
 * Description:
 * initializes a new stack
 *
 * Input:
 * Board and a doubly linked list (as the implementation for the stack)
 *
 * Output:
 * None
 *
 * */
void initStack(Board* board, DLL* stack);


/*
 *
 * Description:
 * Exhausts all possible values for all empty cells of the board, counting all solutions found in this process.
 * Once the algorithm backtracks from the first empty cell it returns the number of solutions found.
 *
 * Input:
 * The Sudoku board
 *
 * Output:
 * The number of solutions to the current Sudoku board
 *
 * */
int exBackTracking(Board* board);


/*
 *
 * Description:
 * Loads a puzzle from a path by updating the Sudoku board struct fields
 *
 * Input:
 * A pointer to a file and the Sudoku board
 *
 * Output:
 * None
 *
 * */
void loadToBoard(FILE* fptr, Board* board);

#endif /* AUXILLARY_FUNCTIONS_H_ */
