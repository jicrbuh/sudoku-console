int loadToBoard(FILE* filename, Board* board) {
	/*implement by the instructions in "files format"*/
	/*resets doubly-linked list*/
	return 0;
}
/*TODO add print-board when implementing "new puzzle"*/
int resetBoard(Board* board) {
	return 0; /*TODO resetBoard after implementing doubly linked list*/
}

int markAllErrors(Board* board) {
	/*Not sure we need but maybe we will need
	 * marks all the errors on the board*/
	return 0;
}

int cellIsErronous(Board* board, int x, int y) {
	/*TODO complete is erroneous function*/
	return 0;
}

int fillXRandomCells(Board* board, int x) {
	return 0;
}

int ILPSolver(Board* board) {
	return 0;
}

int exhaustiveBackTracking(Board* board) {
	return 0; /*returns number of solutions*/
}

int eraseAllButYRandomCells(Board* board, int y) {
	return 0;
}

int saveToFile(FILE* fptr,Board* board) { /*TODO in loading remember to take care of files with multiple spaces between cells*/
	/*if in edit mode, save all cells as fixed*/
	int i,j;
	fprintf(fptr,"%d %d\n",board->blockLength,board->blockHeight);
	for (i=0 ; i<board->edgeSize ; i++) {
		for (j=0 ; j<board->edgeSize ; j++) {
			if (j == board->edgeSize-1) {
				if (board->mode == 2) {
					fprintf(fptr,"%d.\n",board[i][j]);
				}
				else {
					fprintf(fptr,"%d\n",board[i][j]);
				}
			}
			else {
				if (board->mode == 2) {
					fprintf(fptr,"%d. ",board[i][j]);
				}
				else {
					fprintf(fptr,"%d ",board[i][j]);
				}
			}
		}
	}
	return 0;
}


int autofillBoard(Board* board) {
	/*iterates over all the empty cells and fills ones that
	 * has only one solution and prints a message for each set done */
	return 0;
}
