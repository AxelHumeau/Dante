##
## EPITECH PROJECT, 2022
## Bootstrap Sokoban
## File description:
## Makefile
##

SRC =	src/graph.c	\
		src/solve.c	\
		../src/vector.c	\
		src/maze.c	\

OBJ =	$(SRC:.c=.o)

MAIN =	src/main.c

OBJ_MAIN =	$(MAIN:.c=.o)

CC =	gcc

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I../include

LDFLAGS =	-L../lib -lmy

NAME =	solver

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
