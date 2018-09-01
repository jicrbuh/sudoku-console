all: sudoku-console
CC = gcc
OBJS = main.o auxiliary_functions.o doubly_linked_list.o \
game_logic.o sudoku_board.o user_interface.o ilp_solver.o
EXEC = sudoku-console
COMP_FLAG = -ansi -Wall -Wextra \
-Werror -pedantic-errors
GUROBI_COMP = -I/usr/local/lib/gurobi563/include
GUROBI_LIB = -L/usr/local/lib/gurobi563/lib -lgurobi56

$(EXEC): $(OBJS)
	$(CC) $(OBJS) $(GUROBI_LIB) -o $@ -lm
main.o: main.c auxiliary_functions.h doubly_linked_list.h \
game_logic.h sudoku_board.h user_interface.h SPBufferset.h
	$(CC) $(COMP_FLAGS) $(GUROBI_COMP) -c $*.c
auxiliary_functions.o: auxiliary_functions.c auxiliary_functions.h \
doubly_linked_list.h sudoku_board.h
	$(CC) $(COMP_FLAGS) $(GUROBI_COMP) -c $*.c
doubly_linked_list.o: doubly_linked_list.c doubly_linked_list.h
	$(CC) $(COMP_FLAGS) $(GUROBI_COMP) -c $*.c
game_logic.o: game_logic.c game_logic.h doubly_linked_list.h \
auxiliary_functions.h sudoku_board.h ilp_solver.h
	$(CC) $(COMP_FLAGS) $(GUROBI_COMP) -c $*.c
sudoku_board.o: sudoku_board.c sudoku_board.h doubly_linked_list.h
	$(CC) $(COMP_FLAGS) $(GUROBI_COMP) -c $*.c
user_interface.o: user_interface.c user_interface.h sudoku_board.h \
doubly_linked_list.h game_logic.h auxiliary_functions.h
	$(CC) $(COMP_FLAGS) $(GUROBI_COMP) -c $*.c
ilp_solver.o: ilp_solver.c sudoku_board.h
	$(CC) $(COMP_FLAGS) $(GUROBI_COMP) -c $*.c
clean:
	rm -f $(OBJS) $(EXEC)
