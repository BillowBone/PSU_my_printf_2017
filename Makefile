##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC	=	./src/my_binary.c	\
		./src/my_hexadecimal.c	\
		./src/my_octal.c	\
		./src/my_printf.c	\
		./src/my_printf2.c	\
		./src/my_printf3.c	\
		./src/my_putchar.c	\
		./src/my_put_long.c	\
		./src/my_put_nbr.c	\
		./src/my_putstr.c	\
		./src/my_put_unsigned.c	\
		./src/my_strlen.c	\
		./src/my_revstr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -pedantic -I./include/

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -c  $(SRC) $(CFLAGS)
		ar rc $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
		rm -f ./*.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all
