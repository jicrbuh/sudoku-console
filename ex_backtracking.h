/*
 * ex_backtracking.h
 *
 *  Created on: 11 Aug 2018
 *      Author: chen
 */

#ifndef EX_BACKTRACKING_H_
#define EX_BACKTRACKING_H_

/*returns 1 if erroneous or 0 else*/
int isBlockErr(Board* board, int x, int y);

/*returns 1 if erroneous or 0 else*/
int isColErr(Board* board, int x, int y);

/*returns 1 if erroneous or 0 else*/
int isRowErr(Board* board, int x, int y);


/*returns 1 if cell erroneous or 0 else*/
int isCellErr(Board* board, int x, int y);

#endif /* EX_BACKTRACKING_H_ */
