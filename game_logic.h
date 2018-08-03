/*
 * game_logic.h
 *
 *  Created on: 3 Aug 2018
 *      Author: chen
 */

#ifndef GAME_LOGIC_H_
#define GAME_LOGIC_H_


int solve(char* fileName, Board* board);
int edit(char* fileName, Board* board);
int mark_errors(int x, Board* board);
int print_board(Board* board);
int set(int x, int y, int z, Board* board);
int validate(Board* board);
int generate(Board* board, int x, int y);
int undo(Board board);
int redo(Board board);


#endif /* GAME_LOGIC_H_ */
