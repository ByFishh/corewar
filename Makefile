##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

LDFLAGS = -L lib -lmy

all:
	$(MAKE) -C lib/my/
	$(MAKE) -C asm/
	$(MAKE) -C corewar/

debug: CFLAGS += -g

debug:
	$(MAKE) -C lib/my/
	$(MAKE) -C asm/ debug
	$(MAKE) -C corewar/ debug

clean:
	find -name "*.o" -delete
	find -name "vgcore.*" -delete
	$(MAKE) -C lib/my/ clean

fclean:	clean
	rm -f asm/asm
	rm -f corewar/corewar
	$(MAKE) -C lib/my/ fclean

re: fclean all

re_debug: fclean debug

.PHONY: all debug clean fclean re re_debug