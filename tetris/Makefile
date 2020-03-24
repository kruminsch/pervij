##
## EPITECH PROJECT, 2019
## dante
## File description:
## makefile
##

NAME    =	tetris

SRC     =	./src/main.c			\

OBJ	=	$(SRC:.c=.o)

all:    	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

CFLAGS += -g3 -Werror -Wextra -Wall -ansi -pedantic -std=gnu11

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		clean all fclean re
