#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMMAND_LENGTH 257
/*parses user commands and calls the functions from game_logic (maybe)*/

int parse_command(int mode, char *userInput){
	char *endptr, *firstArgument, *secondArgument, *thirdArgument, *commandName;
	commandName = strtok(userInput," \t\r\n");
	firstArgument = strtok(NULL," \t\r\n");
	secondArgument = strtok(NULL," \t\r\n");
	thirdArgument = strtok(NULL," \t\r\n");
	/*
	 * TODO
	 *
	 * add mode checks to the cases below*/
	if (strcmp(userInput,"solve") == 0) {
		if (firstArgument == NULL) return 0; /*check validity of argument: argument is not NULL*/
		return solve(firstArgument); /*if we got here argument is valid, call the command's function*/
	}
	else if (strcmp(userInput,"edit") == 0) {
		return edit(firstArgument); /*no need to check validity, if NULL then solve knows its with 0 argument*/
	}
	else if (strcmp(userInput,"mark_errors")) {
		int firstArgumentAsInt = (int)strtol(firstArgument,&endptr,10);
		if (*endptr == NULL) return -3; /*check validity: check if argument is zero (atoi function problem)*/
		else return mark_errors(firstArgumentAsInt); /*mark errors will check if it is 0/1 or not*/
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

	return 1;
}

int read_command(int mode){
	/*scanf + calls parse_command*/

	return 1;
}

int read_print_error(int mode){
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
		case (0) :
			printf("ERROR: invalid command\n");
			break;
		case (-1) :
			printf("Error: File doesn't exist or cannot be opened\n");
			break;
		case (-2) :
			printf("Error: File cannot be opened\n");
			break;
		case (-3) :
			printf("Error: the error should be 0 or 1\n");
			break;
		case (-4) :
			printf("Error: value not in range 0-N\n");
			break;
		case (-5) :
			printf("Error: cell is fixed\n");
			break;
	}
	/**/
	free(user_input);
	return 1;
}



