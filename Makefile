##
## EPITECH PROJECT, 2021
## makefile
## File description:
## project makefile
##

MY_PLAZZA_DIR = src/Plazza/
MY_UTILS_DIR = src/Utils/
MY_DISPLAY_DIR = src/Display/

SRC =   src/main.cpp																	\
		${MY_PLAZZA_DIR}Pizza/Pizza.cpp													\
		${MY_PLAZZA_DIR}Pizza/Factory/Factory.cpp										\
		${MY_PLAZZA_DIR}Pizza/PizzaType/Americana/Americana.cpp							\
		${MY_PLAZZA_DIR}Pizza/PizzaType/Fantasia/Fantasia.cpp							\
		${MY_PLAZZA_DIR}Pizza/PizzaType/Margarita/Margarita.cpp							\
		${MY_PLAZZA_DIR}Pizza/PizzaType/Regina/Regina.cpp								\
        ${MY_PLAZZA_DIR}Order/Order.cpp													\
        ${MY_PLAZZA_DIR}Kitchen/Kitchen.cpp												\
        ${MY_PLAZZA_DIR}Reception/Reception.cpp											\
        ${MY_PLAZZA_DIR}Restaurant/Restaurant.cpp										\
        ${MY_PLAZZA_DIR}Stock/Stock.cpp													\
		${MY_UTILS_DIR}Error/Error.cpp													\
		${MY_UTILS_DIR}Serializer/Serializer.cpp										\
		${MY_UTILS_DIR}Communication/Communication.cpp									\
		${MY_UTILS_DIR}Encapsulations/Process/Process.cpp								\
		${MY_UTILS_DIR}Encapsulations/Threads/Threads.cpp								\
		${MY_UTILS_DIR}Encapsulations/Mutex/Mutex.cpp									\
		${MY_UTILS_DIR}Encapsulations/ConditionalVariables/ConditionalVariables.cpp		\
		${MY_UTILS_DIR}CommandInterpreter/CommandInterpreter.cpp						\
		${MY_DISPLAY_DIR}DLLoader/DLLoader.cpp											\
		${MY_DISPLAY_DIR}DLLib/DLLib.cpp												\
		${MY_DISPLAY_DIR}UserInput/UserInput.cpp										\
		${MY_DISPLAY_DIR}CoreDisplay/CoreDisplay.cpp									\
		${MY_DISPLAY_DIR}Vector.cpp														\

OBJ =   $(SRC:.cpp=.o)

NAME =	plazza

INCLUDES =	-I include -I src/Plazza -I src/Utils -I src/Display
CXXFLAGS =	$(INCLUDES) -W -Wall -Wextra


all:	$(NAME)

$(NAME):	$(OBJ)
		@$(ECHO)
		@g++ -o $(NAME) $(OBJ) -lpthread -ldl -lncurses	\
		&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) || ($(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT) && exit 1)

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

.PHONY: all clean fclean re debug


ECHO	=	   /bin/echo -e
DEFAULT =	   "\033[00m"

DEFAULT =	   "\e[0m"
BOLD	=	   "\e[1m"
DIM	 	=	   "\e[2m"
UNDLN   =	   "\e[4m"
SHINE   =	   "\e[5;37m"
RODE	=	   "\e[9;37m"

BLACK   =	   "\e[30m"
RED	 	=	   "\e[31m"
GREEN   =	   "\e[32m"
YELLOW  =	   "\e[33m"
BLUE	=	   "\e[34m"
MAGEN   =	   "\e[35m"
CYAN	=	   "\e[36m"
WHITE   =	   "\e[1;37m"

LIGHT_RED	   	=	   "\e[91m"
LIGHT_GREEN	 	=	   "\e[92m"
LIGHT_YELLOW	=	   "\e[93m"
LIGHT_BLUE	  	=	   "\e[94m"
LIGHT_MAGEN	 	=	   "\e[95m"
LIGHT_CYAN	  	=	   "\e[96m"
