# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 17:41:46 by meskelin          #+#    #+#              #
#    Updated: 2023/01/30 16:31:07 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FT_PRINT_PATH = ./ft_printf
LIBFT_PATH = ./libft

BUILD_FLAGS = -Wall -Werror -Wextra

UTILS_SRC = print_error \
print_op \
ft_lstnew \
ft_lstclear \
ft_lstadd

OP_SRC = swap \
		 push \
		 rotate \
		 rev_rotate

SRC = stack_sort

USRCPRE = $(addprefix ./src/utils/, $(UTILS_SRC))
USRCSUFF = $(addsuffix .c, $(USRCPRE))
OPSRCPRE = $(addprefix ./src/op/, $(OP_SRC))
OPSRCSUFF = $(addsuffix .c, $(OPSRCPRE))
SRCPRE = $(addprefix ./src/, $(SRC))
SRCSUFF = $(addsuffix .c, $(SRCPRE))
HSUFF = $(addsuffix .h, $(H_FILES))

.PHONY = all
all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINT_PATH)
	cc $(BUILD_FLAGS) main.c $(SRCSUFF) $(USRCSUFF) $(OPSRCSUFF) \
	-L $(FT_PRINT_PATH) -lftprintf \
	-L $(LIBFT_PATH) -lft -o $(NAME)

.PHONY: clean
clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINT_PATH)
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINT_PATH)
	rm -f $(NAME)

.PHONY: re
re: fclean all
