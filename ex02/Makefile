# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tecker <tecker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 12:19:12 by tecker            #+#    #+#              #
#    Updated: 2024/12/19 14:46:00 by tecker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	PmergeMe

CC				=	c++

CFLAGS			=	-Wall -Werror -Wextra -std=c++17
DEBUGFLAGS      =   -DDEBUG

SRC_FILES		=	main.cpp \
					PmergeMe.cpp \
					PmergeMe_sort_vec.cpp \
					PmergeMe_sort_deq.cpp \

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