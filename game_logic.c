/*contains ???*/

int solve(char* filename) {
	/*filename - full or relative*/
	/*if file not opened return -1*/
	/*changed the mode to solve (1)*/
	/*available in all modes*/
	/*resets doubly linked list*/
	return 0;
}

int edit(char* filename) {
	/*filename - full or relative*/
	/*filename \0 - empty board*/
	/*if file not opened return -2*/
	/*changed the mode to edit (2)*/
	/*available in all modes*/
	return 0;
}

int mark_errors(int x) {
	return 0;
	/*available in solve (1) mode*/
	/*x is 0 or 1!*/
}

int print_board() {
	/*available in solve, edit (1,2) mode*/
	return 0;
}

int set(int x, int y, int z) {
	/*available in solve, edit (1,2) mode
	 * if x,y,z not in range error (-4)
	 * if x,y, fixed (-5)*/

	return 0;
}
