
SRC	=	um_main.c				\


OBJ	=	$(SRC:.c=.o)				\

NAME	=	c.um

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
