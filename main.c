#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxillary_functions.h"
#include "doubly_linked_list.h"
#include "game_logic.h"
#include "user_interface.h"
#include "sudoku_board.h"
#include "SPBufferset.h"

int test_load(Board* board, char* path) {
	FILE* fptr = NULL;
	fptr = fopen(path, "r");
	if (fptr == NULL) {
		printf("couldn't open file to read\n");
		return 999;
	}

	loadToBoard(fptr, board);
	printBoard(board);
	fclose(fptr);
	return 0;
	}

int test_load_err(Board* board, char* path, int x, int y) {
	int isErr = 0;
	FILE* fptr = NULL;
	fptr = fopen(path, "r");

	if (fptr == NULL) {
		printf("ERROR:couldn't open file %s for reading\n", path);
		return 999;
	}

	loadToBoard(fptr, board);
	printBoard(board);
	isErr = isCellErr(board,x,y);
	if (isErr) {
		printf("succebss: %d,%d is err\n", x, y);
	}
	else {
		printf("ERROR: %d,%d suppose to be erroneous but isCellErr == 0\n", x, y);
	}
	fclose(fptr);
	return 0;
	}

int main() {

	/*
	char* path1 = "tests\\load1.txt";
	char* path2 = "tests\\load2.txt";
	char* path3 = "tests\\load3.txt";
	char* err00 = "tests\\err_0_0.txt";
	char* err01 = "tests\\err_0_1.txt";*/
	Board* board = createBoard(3,3);


	printf("test_load for load1\n");
	/*test_load(board, path1);

	printf("test_load for load2\n");
	test_load(board, path2);

	printf("test_load for load3\n");
	test_load(board, path3);

	printf("test_load_err for err_0_0\n");
	test_load_err(board, err00, 0,0);

	printf("test_load_err for err_0_1\n");
	test_load_err(board, err01, 0,1);*/

	destroyBoard(board);

	return 0;
}
