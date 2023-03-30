# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alboudje <alboudje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:53:30 by alboudje          #+#    #+#              #
#    Updated: 2023/03/30 15:29:48 by alboudje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	harlFilter
CC 				= 	g++

SRC				= 	main.cpp \
					Harl.cpp
INCLUDES	 	=	Harl.hpp

OBJ 			= 	${SRC:.cpp=.o}
CFLAGS 			= 	-Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ)
	@printf '$(GREEN)Creating $(CYAN)$(NAME)$(END): OK\n'

%.o : %.cpp $(INCLUDES) Makefile
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf '$(GREEN)Compiling $(NAME): $(CYAN)$<: $(GREEN)OK$(END)\n'

clean :
	-rm -f $(OBJ)

fclean : clean
	-rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

END		=\x1b[0m
BOLD	=\x1b[1m
UNDER	=\x1b[4m
REV		=\x1b[7m

# Colors
GREY	=\x1b[30m
RED		=\x1b[31m
GREEN	=\x1b[32m
YELLOW	=\x1b[33m
BLUE	=\x1b[34m
PURPLE	=\x1b[35m
CYAN	=\x1b[36m
WHITE	=\x1b[37m

# Colored backgrounds
IGREY	=\x1b[40m
IRED	=\x1b[41m
IGREEN	=\x1b[42m
IYELLOW	=\x1b[43m
IBLUE	=\x1b[44m
IPURPLE	=\x1b[45m
ICYAN	=\x1b[46m
IWHITE	=\x1b[47m