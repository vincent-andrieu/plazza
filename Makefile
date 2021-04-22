##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

SRC =   src/main.cpp														\
		src/Error/Error.cpp													\
		src/Plazza.cpp														\
		src/Serializer/Serializer.cpp										\
		src/Communication/Communication.cpp									\
		src/Encapsulations/Processes/Processes.cpp							\
		src/Encapsulations/Threads/Threads.cpp								\
		src/Encapsulations/Mutex/Mutex.cpp									\
		src/Encapsulations/ConditionalVariables/ConditionalVariables.cpp	\

OBJ =   $(SRC:.cpp=.o)

NAME =	plazza

INCLUDES =	-I include -I include/Interfaces -I src
CXXFLAGS =	$(INCLUDES) -W -Wall -Wextra


all:    $(NAME)

$(NAME):    $(OBJ)
		@$(ECHO)
		@g++ -o $(NAME) $(OBJ) \
		&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT)

clean:
		@rm -f $(OBJ)
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean: clean
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

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