/*contains ???*/

int solve(char* fileName, int* mode) {
	/*filename - full or relative*/
	/*if file not opened return -1*/
	/*changed the mode to solve (1)*/
	/*available in all modes*/
	/*resets doubly linked list*/
	/*change to correct mode*/
	return 0;
}

int edit(char* fileName, int* mode) {
	/*filename - full or relative*/
	/*filename \0 - empty board*/
	/*if file not opened return -2*/
	/*changed the mode to edit (2)*/
	/*available in all modes*/
	return 1;
}

int mark_errors(int x) {
	return 1;
	/*available in solve (1) mode*/
	/*x is 0 or 1!*/
}

int print_board(Board board) {
	/*available in solve, edit (1,2) mode*/
	return 1;
}

int set(int x, int y, int z) {
	/*available in solve, edit (1,2) mode
	 * if x,y,z not in range error (-4)
	 * if x,y, fixed (-5)*/

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
}
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
