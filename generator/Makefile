##
## EPITECH PROJECT, 2022
## Bootstrap Sokoban
## File description:
## Makefile
##

SRC =	src/tool.c
SRC	+=	../src/vector.c
SRC	+=	src/init_maze.c
SRC	+=	src/rand.c
SRC	+=	src/create_maze.c

OBJ =	$(SRC:.c=.o)

MAIN =	src/main.c

OBJ_MAIN =	$(MAIN:.c=.o)

CC =	gcc

CFLAGS =	-Wall -Wextra -g3

CPPFLAGS =	-I ../include

LDFLAGS =	-L ../lib -lmy

NAME =	generator

all:	$(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	make -C ../lib/my/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CPPFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)

fclean:	clean
	$(RM) $(NAME)

debug:	CFLAGS += -g
debug:	fclean all

re:	fclean all

.PHONY:	all re clean fclean debug
