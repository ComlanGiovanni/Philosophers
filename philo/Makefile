# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 15:32:24 by gcomlan           #+#    #+#              #
#    Updated: 2022/09/06 15:59:46 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ VARIABLES ------------------------------

GCC			= gcc -Wall -Wextra -Werror -pthread

NAME		=	philo

RM			=	rm -f

# ------------------------------ SRC ------------------------------

SRC			=		main.c \
					help.c	\
					actions.c \
					threads.c \
					utilities.c \
					initialisation.c

OBJ := $(SRC:.c=.o)

DEP := $(OBJ:.o=.d)

# ------------------------------ Colors ------------------------------

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(PURPLE)Make: $(NO_COLOR)Starting the compilation...\n"

PHILO_COMP	=	echo "\n🚧 $(YELLOW) $(NAME): $(NO_COLOR)Starting the compilation...\n"

PHILO_READY	=	echo "\n🧮 $(BLUE) $(NAME) $(NO_COLOR)ready!\n"

CLEANED		=	echo "\n💧 $(GREEN)Clean: $(NO_COLOR)Removed all the \".o\" files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(GREEN)Fclean: $(NO_COLOR)Removed the executables 🗑\\n"

NEW_LINE	=	echo "\n"

# ------------------------------ Rules ---------------------------------

all : $(NAME)

$(NAME): $(OBJ)
	@$(SO_LONG_COMP)
	$(GCC) -o $(NAME) $(OBJ)
	@$(NEW_LINE)
	@echo "$$ASCII_MANDATORY"
	@$(PHILO_READY)

clean :
	$(RM) *.o
	$(RM) *~
	$(RM) *#
	$(RM) *.d
	@$(CLEANED)

fclean : clean
	$(RM) $(NAME)
	@$(FCLEANED)

re : fclean all

%.o: %.c
	$(GCC) -MMD -o $@ -c $<

-include $(DEP)

# ------------------------------ Ascii ---------------------------------

info: ascii

define ASCII_MANDATORY
$(RED)     PH	  $(NO_COLOR)
$(RED)     HP	  $(NO_COLOR)
$(RED) ,es"PH"so. $(NO_COLOR)
$(RED),RI  HP  IR.$(NO_COLOR)
$(RED)IR   PH   Rl$(NO_COLOR)
$(RED)`RI  HP  IR'$(NO_COLOR)
$(RED) `oimMMmie' $(NO_COLOR)
$(RED)     PH	  $(NO_COLOR)
$(RED)     HP     $(NO_COLOR)
endef
export ASCII_MANDATORY


.PHONY: all clean fclean re bonus
