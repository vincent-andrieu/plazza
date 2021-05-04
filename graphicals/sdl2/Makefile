##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

SRC =  	src/SdlModule/SdlModule.cpp			\
		../../src/Display/Vector.cpp

OBJ =   $(SRC:.cpp=.o)

NAME =	arcade_sdl2.so

INCLUDES =	-I include -I ../../include -I ../../include/Interfaces -I src
CXXFLAGS =	$(INCLUDES) -Wall -Wextra -fPIC -Bstatic -lSDL2 -lSDL2_gfx -Bdynamic -lSDL2main -lSDL2_ttf


all:    $(NAME)

$(NAME):    $(OBJ)
		@$(ECHO)
		@g++ -shared -o $(NAME) $(OBJ) -lSDL2main -lSDL2 -lSDL2_ttf \
		&& $(ECHO) $(BOLD) $(GREEN)"► SDL2 BUILD SUCCESS !"$(DEFAULT) || ($(ECHO) $(BOLD) $(RED)"► SDL2 BUILD FAILED"$(DEFAULT) && exit 1)
		@mkdir -p ../../lib && mv $(NAME) ../../lib

clean:
		@rm -f $(OBJ)
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" SDL2 CLEAN "$(DEFAULT))

fclean: clean
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" SDL2 FCLEAN "$(DEFAULT))
		@rm -f ../../lib/$(NAME)

re: fclean all

debug: CXXFLAGS += -g
debug: re

%.o :		%.cpp
		@g++ -c -o $@ $^ $(CXXFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev

.PHONY: all clean fclean


ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"

DEFAULT =       "\e[0m"
BOLD    =       "\e[1m"
DIM     =       "\e[2m"
UNDLN   =       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;37m"

BLACK   =       "\e[30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGEN   =       "\e[35m"
CYAN    =       "\e[36m"
WHITE   =       "\e[1;37m"

LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGEN     =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"
