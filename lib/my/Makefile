##
## EPITECH PROJECT, 2020
## makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c) \
		my_printf/my_printf.c \
		my_printf/convert/convert.c \
		my_printf/flags/flags.c \
		my_printf/formater/formater.c \
		my_printf/length/length.c \
		my_printf/precision/precision.c \
		my_printf/specifier/specifier.c \
		my_printf/width/width.c \
		my_printf/include/prototype.h \
		my_printf/include/struct.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
	cp my.h ../../include/

clean:
	find -name "*.o" -delete

fclean:		clean
	rm -f libmy.a
	rm -f ../libmy.a

re:		fclean all