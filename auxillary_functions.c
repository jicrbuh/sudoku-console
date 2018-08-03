
/*todo probably need to change to Board**
 * or to add to sudoku_board.c functions that alter the matrix size*/
int loadToBoard(FILE* fptr, Board* board) {


	/*implement by the instructions in "files format"*/

	/*resets doubly-linked list*/
	int intFromFile,i,j, inputRead;

	/*loads n, m into board*/
	inputRead = fscanf (fptr, "%d", &intFromFile);
	board->blockLength=intFromFile;
	assert(inputRead > 0);

	inputRead = fscanf (fptr, "%d", &intFromFile);
	board->blockHeight=intFromFile;
	assert(inputRead > 0);

	/*changes edgesize according to n,m*/
	board->edgeSize=board->blockHeight*board->blockLength;

	/*maybe frees and recreates matrix, isFixed, etc to the correct size*/
	resizeMatrices(board);

	/*loads cell values into board*/
	for (i=0; i< board->edgeSize; i++) {
		for (j=0; j<board->edgeSize; j++) {
			inputRead = fscanf (fptr, "%d", &intFromFile);
			assert(inputRead > 0);
			board->matrix[i][j] = intFromFile;
		}
	}

	fclose (fptr);
	return 0;
}
/*TODO add print-board when implementing "new puzzle"*/
int resetBoard(Board* board) {
	return 0;
}

int markAllErrors(Board* board) {
	/*Not sure we need but maybe we will need
	 * marks all the errors on the board*/
	return 0;
}

<<<<<<< HEAD
int isXYErronous(Board* board, int x, int y) {
	/*TODO*/
=======
int cellIsErronous(Board* board, int x, int y) {
	/*TODO complete iserroneous function*/
	return 0;
}

int fillXRandomCells(Board* board, int x) {
	return 0;
}

int ILPSolver(Board* board) {
	return 0;
}

int eraseAllButYRandomCells(Board* board, int y) {
	return 0;
}

int saveToFile(FILE* fptr,Board* board) {
	/*if in edit mode, save all cells as fixed*/
>>>>>>> 9021f7a91050afbd975acf0a78719b69be6e1901
	return 0;
}
