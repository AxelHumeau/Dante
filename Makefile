##
## EPITECH PROJECT, 2022
## Bootstrap Sokoban
## File description:
## Makefile
##

all:
	make -C ./lib/my/
	make -C ./solver
	make -C ./generator

clean:
	make -C clean ./solver
	make -C clean ./generator

fclean:	clean
	make -C fclean ./solver
	make -C fclean ./generator

debug:
	make -C debug ./solver
	make -C debug ./generator

re:
	make -C re ./solver
	make -C re ./generator

.PHONY:	all re clean fclean debug
