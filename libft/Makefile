# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:13:53 by meskelin          #+#    #+#              #
#    Updated: 2023/02/13 17:49:01 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIB_NAME = libft.a

FT_PRINT_PATH = ../ft_printf

SRC_FILES = ft_isdigit \
ft_memcpy \
ft_strlcpy \
ft_strlen \
ft_split \
ft_atoi \
ft_memset \
ft_bzero \
ft_calloc \
ft_putchar_fd \
ft_putstr_fd \
ft_putendl_fd

H_FILES = libft

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))
HS = $(addsuffix .h, $(H_FILES))

BUILD_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) -c $(SRC)
	ar rc $(LIB_NAME) $(OBJ)
	ranlib $(LIB_NAME)

clean:
	rm -f $(OBJ) $(B_SRC:.c=.o)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
