##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I ../include/

LDFLAGS = -L ../lib -lmy

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

all:
	$(MAKE) $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g

debug:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

.PHONY: all debug clean fclean re re_debug