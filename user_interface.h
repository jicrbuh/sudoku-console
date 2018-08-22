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



int parseCommand(char* userInput, Board* board);
int interact(Board* board);



#endif /* USER_INTERFACE_H_ */
