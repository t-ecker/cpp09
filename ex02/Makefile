# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 12:19:12 by tecker            #+#    #+#              #
#    Updated: 2024/12/19 01:47:08 by tomecker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	PmergeMe

CC				=	c++

CFLAGS			=	-Wall -Werror -Wextra -std=c++17
DEBUGFLAGS      =   -DDEBUG

SRC_FILES		=	main.cpp \
					PmergeMe.cpp

OBJ_DIR			=	./obj

OBJ_FILES		= 	$(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

all:	$(NAME)

debug:  CFLAGS += $(DEBUGFLAGS)
debug:  clean $(NAME)  

$(NAME):	$(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all