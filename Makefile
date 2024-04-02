# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 17:09:05 by sephilip          #+#    #+#              #
#    Updated: 2024/04/02 14:33:05 by sephilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC = aux1.c aux2.c extra.c main.c oper1.c oper2.c oper3.c push_swap.c pushing.c new_split.c start.c free.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

INCS = -I ./includes -I ./includes/libft
LIBFT = includes/libft/libft.a
LIBFT_PATH = ./include/libft

all:	$(LIBFT) $(OBJ_PATH) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
#	we link them here

$(LIBFT):
		make -C libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
#	PUTTING THE OBJECTS IN THEIR FOLDERS
#	-c ==> don't link sorce file to executable, yet.
#	$< ==> first prerequisite file, something.c
#	$@ ==> the target, objects.o

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re:	 fclean all

.PHONY: all clean fclean re
