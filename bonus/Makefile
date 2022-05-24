##
## EPITECH PROJECT, 2022
## Bootstrap Sokoban
## File description:
## Makefile
##

SRC =	../solver/src/graph.c	\
		src/solve.c	\
		src/fifo.c	\
		../src/vector.c	\

OBJ =	$(SRC:.c=.o)

MAIN =	../solver/src/main.c

OBJ_MAIN =	$(MAIN:.c=.o)

CC =	gcc

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I../include

LDFLAGS =	-L../lib -lmy

NAME =	solver_bonus

all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(OBJ_MAIN)

fclean:	clean
	rm -f $(NAME)

debug:	CFLAGS += -g
debug:	fclean all

re:	fclean all

.PHONY:	all re clean fclean debug
