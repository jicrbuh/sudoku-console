/*
 * user_interface.h
 *
 *  Created on: 3 Aug 2018
 *      Author: chen
 */

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_
#include "sudoku_board.h"
#include "SPBufferset.h"


/* Input:
 * userInput - a command entered by the user
 * board - the Sudoku board
 *
 * Output:
 * returns a value which indicates the state of the program after the command was launched
 * this function serves as a mediator between the interact function and the functions
 * that are responsible for the inner game logic (written in game_logic.c)
 * 11 - in middle of performing autofill: the list of sets is updated in the moves list
 * 		and ready to be auto filled
 * 10 - puzzle solved successfully
 *  9 - puzzle is solved but is erroneous
 *  8 - exiting the program
 *  7 - board is reset
 *  6 - the user asked for the number of solutions, board->numofSolutions is up to date
 *  5 - the user asked for a hint, board->lastHint is up to date
 *  4 - after an undo move
 *  3 - after a redo move
 *  2 - validation passed (board is solvable)
 *  0 - invalid command
 * -1 - unsuccessful try to open a file (doesn't exist or can't be opened)
 * -2 - unsuccessful try to open a file (can't be opened)
 * -3 - unsuccessful try to switch mark errors on/off (argument isn't 1 or 0)
 *
 *
 * Description:
 * parses the user input and calls a function accordingly
 * or notifying there is a problem with the input */
int parseCommand(char* userInput, Board* board);

/* Input:
 * board - the Sudoku board
 *
 * Output:
 *
 *
 * Description:
 *  */
int interact(Board* board);



#endif /* USER_INTERFACE_H_ */
