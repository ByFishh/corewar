##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CFLAGS = -I ../include/

LDFLAGS = -L ../lib -lmy -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

SRC	=	$(wildcard src/*.c) \
		$(wildcard src/instr/*.c)	\
		$(wildcard src/graphics/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

all:
	$(MAKE) $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g

debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

.PHONY: all debug clean fclean re re_debug