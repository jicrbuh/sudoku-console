#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMMAND_LENGTH 257
/*parses user commands and calls the functions from game_logic (maybe)*/

int* parse_command(int mode){
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
		printf("ERROR: invalid command\n");
		return -1;
	}
	/*calls read_command and prints errors if necessary*/
	parse_command(mode);
	/**/
	free(user_input);
	return 1;
}



