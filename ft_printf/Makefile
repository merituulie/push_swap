# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 18:49:30 by meskelin          #+#    #+#              #
#    Updated: 2023/02/06 13:13:59 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB_NAME = libftprintf.a

BUILD_FLAGS = -Wall -Werror -Wextra -c

SRC_FILES = ft_printf_str \
ft_printf_nbr \
ft_printf_hx \
ft_printf_ptr \
ft_printf

H_FILES = /includes/ft_printf

HS = $(addsuffix .h, $(H_FILES))
SRCSUFF = $(addsuffix .c, $(SRC_FILES))
SRCSO = $(SRCSUFF:.c=.o)
SRCSPRE = $(addprefix ./src/, $(SRCSUFF))

.PHONY = all
all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) $(SRCSPRE)
	ar rc $(LIB_NAME) $(SRCSO)
	ranlib $(LIB_NAME)

.PHONY: clean
clean:
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	rm -f $(LIB_NAME)

.PHONY: re
re: fclean all
