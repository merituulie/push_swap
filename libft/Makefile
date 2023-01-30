# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:13:53 by meskelin          #+#    #+#              #
#    Updated: 2023/01/30 16:30:30 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = ft_isdigit \
ft_memcpy \
ft_strlcpy \
ft_strlen \
ft_split \
ft_atoi \
ft_memset \
ft_bzero \
ft_calloc

H_FILES = libft

LIB_NAME = libft.a

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))
HS = $(addsuffix .h, $(H_FILES))

BUILD_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) -c $(SRC) -I $(HS)
	ar rc $(LIB_NAME) $(OBJ)
	ranlib $(LIB_NAME)

clean:
	rm -f $(OBJ) $(B_SRC:.c=.o)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

# $(B_SRC:.c=.o):
# 	cc $(BUILD_FLAGS) -c $(B_SRC) -I $(HS)
# 	ar rus $(NAME) $(B_SRC:.c=.o)

# bonus: $(B_SRC) $(B_SRC:.c=.o)
