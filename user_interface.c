#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMMAND_LENGTH 257
/*parses user commands and calls the functions from game_logic (maybe)*/

int parse_command(int* mode, char *userInput, Board board){
	char *endptr1, *endptr2, *endptr3, *firstArgument, *firstArgumentAsInt, *secondArgumentAsInt, *thirdArgumentAsInt, *command;
	command = strtok(userInput," \t\r\n");
	firstArgument = strtok(NULL," \t\r\n");
	firstArgumentAsInt = (int)strtol(strtok(NULL," \t\r\n"),&endptr1,10);
	secondArgumentAsInt = (int)strtol(strtok(NULL," \t\r\n"),&endptr2,10);
	thirdArgumentAsInt = (int)strtol(strtok(NULL," \t\r\n"),&endptr3,10);
	if (strcmp(userInput,"solve") == 0) {
		if (firstArgument == NULL) return 0; /*check validity of argument: argument is not NULL*/
		return solve(firstArgument, mode); /*if we got here argument is valid, call the command's function*/
	}
	else if (strcmp(userInput,"edit") == 0) {
		return edit(firstArgument, mode); /*no need to check validity, if NULL then solve knows its with 0 argument*/
	}
	else if (strcmp(userInput,"mark_errors")) {
		if (mode != 1) return 0;
		if (*endptr1 == NULL) return -3; /*check validity: check if argument is zero (atoi function problem)*/
		else return mark_errors(firstArgumentAsInt); /*mark errors will check if it is 0/1 or not*/
	}
	else if (strcmp(userInput,"print_board")) {
		if (mode == 0) return 0; /*not allowed in init mode*/
		return print_board(board);
	}
	else if (strcmp(userInput, "set")) {
		if (mode == 0) return 0; /*not allowed in init mode*/
		if (endptr1 == NULL || endptr2 == NULL || endptr3 == NULL) return -4; /*verify that all arguments are integers*/
		return set(firstArgumentAsInt,secondArgumentAsInt,thirdArgumentAsInt); /*set will check if the arguments are in range*/
	}
	else if (strcmp(userInput,"validate")) {
		if (mode == 0) return 0; /*not allowed in init mode*/
		return validate(board);
	}
	else if (strcmp(userInput,"generate")) {
		if (mode != 2) return 0; /*only allowed in edit mode*/
		if (endptr1 == NULL || endptr2 == NULL || firstArgumentAsInt > numberOfEmptyCells(board)) return -8;
		/*asked in the forum if need to check y is a valid int (same we did for x). in the instructions they say only for x but
		 * we think its a mistake and should be checked for y's value also*/
		if (numberOfCellsFilled(board) == 0) return -9;
		return generate(board,firstArgumentAsInt,secondArgumentAsInt);
	}
	else if (strcmp(userInput,"undo")) {
		if (mode == 0) return 0; /*not allowed in init mode*/
		return undo(board);
	}
	else if (strcmp(userInput,"redo")) {
		if (mode == 0) return 0; /*not allowed in init mode*/
		return redo(board);
	}
	else if (strcmp(userInput,"save")) {
		if (mode == 0) return 0; /*not allowed in init mode*/
		int retVal = save(board,firstArgument,mode);
		if (retVal==1) printf("Save to: %s\n", firstArgument);
		return retVal;
	}

	return 1;
}

int read_command(int mode){
	/*scanf + calls parse_command*/

	return 1;
}

int read_print_error(int mode, Board board){
	char user_input[COMMAND_LENGTH]  = {0};
	/*prints 'please enter a command'*/
	printf("please enter a command\n");
	fgets(user_input,COMMAND_LENGTH,stdin);
	if (user_input[COMMAND_LENGTH] != 0) {
		printf("ERROR: invalid command\n"); /*command too long - returning -1*/
		return -1;
	}
	/*calls read_command and prints errors if necessary*/
	switch(parse_command(mode)) {
		case (4):
			printf("Undo %d,%d: from %d to %d\n",0,0,0,0); /*change the d values according to linked list*/
			break;
		case (3):
			printf("Undo %d,%d: from %d to %d\n",0,0,0,0); /*change the d values according to linked list*/
			break;
		case (2):
			printf("Validation passed: board is solvable\n");
			break;
		case (0):
			printf("ERROR: invalid command\n");
			break;
		case (-1):
			printf("Error: File doesn't exist or cannot be opened\n");
			break;
		case (-2):
			printf("Error: File cannot be opened\n");
			break;
		case (-3):
			printf("Error: the error should be 0 or 1\n");
			break;
		case (-4):
			printf("Error: value not in range 0-%d\n",board.edge_size);
			break;
		case (-5):
			printf("Error: cell is fixed\n");
			break;
		case (-6):
			printf("Error: board contains erroneous values\n");
			break;
		case (-7):
			printf("Validation failed: board is unsolvable\n");
			break;
		case (-8):
			printf("Error: value not in range 0-%d\n",numberOfEmptyCells(board));
			break;
		case (-9):
			printf("Error: board is not empty\n"); /*in the instructions file (in generate) there is a probably mistaken extra space */
			break;
		case (-10):
			printf("Error: puzzle generator failed\n");
			break;
		case (-11):
			printf("Error: no moves to undo\n");
			break;
		case (-12):
			printf("Error: no moves to redo\n");
			break;
		case (-13):
			printf("Error: board validation failed\n");
	}
	/**/
	free(user_input);
	return 1;
}



