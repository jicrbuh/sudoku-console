#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve(char* fileName, Board* board) {
	/*filename - full or relative*/
	/*if file not opened return -1*/
	/*changed the mode to solve (1)*/
	/*available in all modes*/
	/*resets doubly linked list*/
	/*change to correct mode*/
	FILE* file = NULL;
	file = fopen(fileName,"r"); /*check if opened successfully*/
	if (file == NULL) {
		return -1;
	}
	loadToBoard(file,board);
	board->mode = 1;
	return 1;
}

int edit(char* fileName, Board* board) {
	/*filename - full or relative*/
	/*filename \0 - empty board*/
	/*if file not opened return -2*/
	/*changed the mode to edit (2)*/
	/*available in all modes*/

	FILE* file = NULL;
	if (fileName == NULL) {
		resetBoard(board);
		board->mode = 2;
		return 1;
	}
	file = fopen(fileName,"r"); /*check if opened successfully*/
	if (file == NULL) {
		return -2;
	}
	loadToBoard(file,board);
	board->mode = 2;
	return 1;
}

int mark_errors(int x, Board* board) {
	/*available in solve (1) mode*/
	/*x is 0 or 1!*/
	if (x != 0 && x != 1) {
		return -3;
	}
	board->mode = x;
	return 1;
}

int print_board(Board* board) {
	/*available in solve, edit (1,2) mode*/
	printBoard(board);
	return 1;
}

int set(int x, int y, int z, Board* board) {
	/*available in solve, edit (1,2) mode
	 * if x,y,z not in range error (-4)
	 * if x,y, fixed (-5)*/
	if (x<0 || y<0 || z<0 || x > board->edgeSize-1 || y > board->edgeSize-1 || z > board->edgeSize) {
		return -4;
	}
	if (board->isFixed[x][y] == 1) {
		return -5;
	}
	/*TODO "Clear any move beyond the current move from the undo/redo list, then add
the new move to the end of the list and mark it as the current move" */
	board->matrix[x][y] = z;

	return 1;
}

int validate(Board board) {
	/*check if the board is erroneous, namely, it has 2 cells with same number which are neighbors
	 * if it is erroneous - error (-6)
	 * if it is unsolvable - error(-7)
	 * else, it is valid - message(2) */

	return 1;
}

int generate(Board board, int x, int y) {
	/*if 1000 iterations fail - error (-10)*/
	return 1;
}

int undo(Board board) {
	/*if no moves to undo - error (-11)*/
	return 1;
}

int redo(Board board) {
	/*if no moves to redo - error (-12)*/
	return 1;
}

int save(Board board, char* fileName, int* mode) {
	/*if in edit mode there are 2 possible errors:
	 * 1) if board is erroneous - error (-6)
	 * 2) if it is unsolvable - error (-13)
	 * error that can happen in every mode:
	 * if the file saving falis - error (-14)
	 * if the process finished without problems parse_command will send the corresponding message
	 */
	return 1;
}

int hint(Board board, int x, int y) {
	/*check for the following errors:
	 * 1) check if x or y are out of range (1-N) - error (-4)
	 * 2) check if board has erroneous values - error (-6)
	 * [erroneous values means neighbors with same value]
	 * 3) check if cell (x,y) is fixed - error (-5)
	 * 4) check if cell (x,y) already conatins a value - error (-14)
	 * [run ILP now]
	 * 5) if board is unsolvable - error (-15)
	 *
	 * if no error occurred return the value the ILP suggested for cell (x,y) - message (5) + the value!
	 * */
	return 1;
}

int num_solutions(Board board) {
	/*check for the following errors:
	 * 1) check if board has erroneous values - error (-6)
	 * [now run exhaustive backtracking which should return the number of solutions]
	 * if no error - message (6) + the value*/
	return 1;
}

int autofill(Board board) {
	/*check if board has erroneous values - error (-6)*/
	return 1;
}

int reset(Board board) {
	/*message (7)*/
	return 1;
}

int exit(Board board) {
	/*message (8)*/
}
/*TODO when finishing implementing the functions update the arguments user interface calls*/
/*calls the right function from game_logic*/
/*prints errors for specific functions*/
/*switch case for printing different errors, starting from -1*/
/*all input can has more parameters than needed and be ok*/

/*solve(x) - x is not empty
 * error (-1) "Error: File doesn't exist or cannot be opened\n"*/

/*edit(x) - x can be empty (\0) or filename
 * error (-2) "Error: File cannot be opened\n" */

/*mark_errors(x) - x should be 0 or 1. mode solve (1)
* handled by parse_command: error (-3) "Error: the error should be 0 or 1\n" */

/*print_board() - no parameteres
* only available in edit and solve modes */

/*set(x,y,z) - available in solve, edit (1,2) mode
 * checks if x,y,z are ints
 * if x,y,z not in range error (-4) "Error: value not in range 0-N\n
 * if x,y is fixed error (-5) "Error: cell is fixed\n"*/
