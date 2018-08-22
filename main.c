#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxillary_functions.h"
#include "doubly_linked_list.h"
#include "game_logic.h"
#include "user_interface.h"
#include "sudoku_board.h"
#include "SPBufferset.h"
int test_load(Board* board, char* path);

int test_load_save(Board* board, char* inpath, char* outpath) {
	FILE* fptr = NULL;
	int didload = test_load(board, inpath);

	fptr = fopen(outpath, "w");
		if (fptr == NULL) {
			printf("couldn't open file to write\n");
			return 999;
	}
	if (didload != 0) {
		printf("test_load_save couldn't load\n");
		return 999;
	}

	saveToFile(fptr, board);
	fclose(fptr);
	return 0;
}

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
		printf("ERROR: couldn't open file %s for reading\n", path);
		return 999;
	}

	loadToBoard(fptr, board);
	printBoard(board);
	isErr = isCellErr(board,x,y);
	if (isErr) {
		printf("success: %d,%d is err\n\n", x, y);
	}
	else {
		printf("ERROR: %d,%d suppose to be erroneous but isCellErr == 0\n\n", x, y);
	}
	fclose(fptr);
	return 0;
	}

int test_solve(char* inpath, Board* board, int isErr) {
	/*SOLVE if file not found - check if prints the error and doesn't execute the command*/
	int didsolve = solve(inpath, board);
	if (isErr == 1) {
		if (didsolve != -1) {
			printf("ERROR: solve shouldn't be able to load file, but doesn't return -1");
			return -1;
		}
	}
	else if (isErr == 0) {
		if (didsolve == -1) {
			printf("ERROR: solve returned -1, but should be able to load file");
			return -1;
		}
	}
	/*check if puzzle is in solve mode*/
	if(board->mode != 1 && isErr == 0) {
		printf("ERROR: solve didn't load puzzle in solve mode");
		return -1;
	}

	return 0;
}

int test_edit(char* inpath, Board* board, int isErr, int nopath) {
	/*if file not found - check if prints the error and doesn't execute the command*/
	int didedit = solve(inpath, board);
	if (isErr == 1) {
		if (didedit != -2) {
			printf("ERROR: edit shouldn't be able to load file, but doesn't return -1");
			return -1;
		}
	}
	else if (isErr == 0) {
		if (didedit == -2) {
			printf("ERROR: edit returned -1, but should be able to load file");
			return -1;
		}
	}

	/*check if puzzle is in edit mode*/
	if(board->mode != 2 && isErr == 0) {
		printf("ERROR: edit didn't load puzzle in edit mode");
		return -1;
	}


	/*EDIT if argument is empty, enter with an empty board 9x9, in EDIT mode*/
	if (nopath) {
		if (didedit == -2) {
			printf("ERROR: edit should load an empty board, but returned -2");
			return -1;
		}
		if (board->edgeSize != 9) {
			printf("ERROR: edit should load an empty board, but edgeSize != 9");
			return -1;
		}
	}
	return 0;



}

int main() {

	Board* board = createBoard(2,2);
	char* path1 = "tests\\load1.txt";
	char* empty = "";
	/*char* path2 = "tests\\load2.txt";
	char* path3 = "tests\\load3.txt";
	char* not_err = "tests\\not_err.txt";
	char* err00 = "tests\\err_0_0.txt";
	char* err01 = "tests\\err_0_1.txt";
	char* path23 = "tests\\load_2x3.txt";
	char* save23 = "tests\\saved_2x3.txt";
	char* save1 = "tests\\saved_1.txt";



	printf("test_load for load1\n");
	test_load(board, path1);

	printf("test_load for load2\n");
	test_load(board, path2);

	printf("test_load for load3\n");
	test_load(board, path3);

	printf("test_load for load23\n");
		test_load(board, path23);

	printf("test_load for not_err\n");
		test_load(board, not_err);

	printf("test_load_err for err_0_0\n");
	test_load_err(board, err00, 0,0);

	printf("test_load_err for err_0_1\n");
	test_load_err(board, err01, 0,1);

	printf("test_load_save for save1\n");
	test_load_save(board, path1, save1);

	printf("test_load_save for save23\n");
	test_load_save(board, path23, save23);
	 */
	test_solve(path1,board,0);
	test_solve(empty,board,1);

	destroyBoard(board);
	printf("\ntest finihed!\n");
	return 0;
}
