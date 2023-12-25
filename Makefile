# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 17:09:05 by sephilip          #+#    #+#              #
#    Updated: 2023/12/25 21:18:05 by sephilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC = aux1.c aux2.c extra.c main.c oper1.c oper2.c oper3.c push_swap.c pushing.c start.c

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
