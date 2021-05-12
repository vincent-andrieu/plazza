##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

all:
		@(cd ncurses && make -s)
		#@(cd sfml && make -s)
		@(cd sdl2 && make -s)

clean:
		@(cd ncurses && make clean -s)
		#@(cd sfml && make clean -s)
		@(cd sdl2 && make clean -s)

fclean: clean
		@(cd ncurses && make fclean -s)
		#@(cd sfml && make fclean -s)
		@(cd sdl2 && make fclean -s)

re: fclean all

.PHONY: all clean fclean