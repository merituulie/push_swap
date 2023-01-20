# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 17:41:46 by meskelin          #+#    #+#              #
#    Updated: 2023/01/20 17:51:59 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BUILD_FLAGS = -Wall -Werror -Wextra

SRC_FILES = main

H_FILES = /includes/header

#HS = $(addsuffix .h, $(H_FILES))
SRCSUFF = $(addsuffix .c, $(SRC_FILES))
HSUFF = $(addsuffix .h, $(H_FILES))

.PHONY = all
all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) $(SRCSUFF) -o $(NAME)

.PHONY: clean
clean:
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
