# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akittie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 18:41:55 by akittie           #+#    #+#              #
#    Updated: 2019/11/25 20:31:17 by akittie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
      check.c\
      fill_tools.c\
      get_tetr.c\
      utils.c\

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -c -I./ $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
