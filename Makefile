# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 17:09:05 by sephilip          #+#    #+#              #
#    Updated: 2023/09/25 14:35:13 by sephilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC = extra.c oper.c push_swap.c stack1.c

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

INCS = -I ./includes
LIB = ./includes/libft.a

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
#	PUTTING THE OBJECTS IN THEIR FOLDERS
#	-c ==> don't link sorce file to executable, yet.
#	$< ==> first prerequisite file, something.c
#	$@ ==> the target, objects.o

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
#	we link them here

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
