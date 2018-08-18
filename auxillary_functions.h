/*
 * auxillary_functions.h
 *
 *  Created on: 3 Aug 2018
 *      Author: chen
 */

#ifndef AUXILLARY_FUNCTIONS_H_
#define AUXILLARY_FUNCTIONS_H_

void printSetUndo(Board* board);

void printAutofillUndo(Board* board);

int loadToBoard(FILE* fptr, Board* board);

int resetBoard(Board* board);

int markAllErrors(Board* board);

int cellIsErronous(Board* board, int x, int y);

int fillXRandomCells(Board* board, int x);

int ILPSolver(Board* board);

int exhaustiveBackTracking(Board* board);

int eraseAllButYRandomCells(Board* board, int y);

int saveToFile(FILE* fptr,Board* board);

int cellHasOnePossibleValue(Board* board,int x,int y);

#endif /* AUXILLARY_FUNCTIONS_H_ */
