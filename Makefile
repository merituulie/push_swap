# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 17:41:46 by meskelin          #+#    #+#              #
#    Updated: 2023/02/13 17:17:46 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FT_PRINT_PATH = ./ft_printf
LIBFT_PATH = ./libft

BUILD_FLAGS = -Wall -Werror -Wextra

UTILS_SRC = print_error \
			ft_lstnew \
			ft_lstclear \
			ft_lstadd \
			ft_lstsize \
			ft_create_or_add \
			print_op \
			ft_clearlst_throw \
			exit

OP_SRC = swap \
		 push \
		 rotate \
		 rev_rotate

SORT_SRC = select_algorithm \
	sort_very_short \
	sort_short \
	sort_medium \
	sort_stack

SRC = create_stack

USRCPRE = $(addprefix ./src/utils/, $(UTILS_SRC))
USRCSUFF = $(addsuffix .c, $(USRCPRE))
OPSRCPRE = $(addprefix ./src/op/, $(OP_SRC))
OPSRCSUFF = $(addsuffix .c, $(OPSRCPRE))
SRCPRE = $(addprefix ./src/, $(SRC))
SRCSUFF = $(addsuffix .c, $(SRCPRE))
SORTSRCPRE = $(addprefix ./src/sort/, $(SORT_SRC))
SORTSRCSUFF = $(addsuffix .c, $(SORTSRCPRE))
HSUFF = $(addsuffix .h, $(H_FILES))

.PHONY = all
all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINT_PATH)
	cc $(BUILD_FLAGS) main.c $(SRCSUFF) $(USRCSUFF) $(OPSRCSUFF) $(SORTSRCSUFF) \
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
