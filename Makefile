NAME	=	server
CC	=	gcc
CFLAGS	=
SRC	=	main2.c
OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(OBJ)

re:	fclean all
