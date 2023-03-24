# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 17:41:46 by meskelin          #+#    #+#              #
#    Updated: 2023/03/24 10:24:51 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FT_PRINT_PATH = ./ft_printf
LIBFT_PATH = ./libft

BUILD_FLAGS = -Wall -Wextra -Werror

COMMON_SRC = print_error \
			print_op \
			clearall_throw \
			find_smallest \
			find_biggest \
			search_from_top \
			search_from_bottom \
			rttnew \
			validate_middle_value \
			find_previous \
			find_rotate_bs \
			find_rotate_middle_small \
			find_rotate_middle \
			iterate_stack \
			not_first_or_last \
			exit

PART_SRC = prtnew \
			prtclear \
			prtadd \
			prtlast \
			prtadd_to_parts \
			select_part_count \
			init_parts

LST_SRC = 	lstnew \
			lstclear \
			lstadd \
			lstsize \
			lstlast \
			lstadd_to_stack

OP_SRC = swap \
		 push \
		 rotate \
		 rev_rotate \
		 rotate_multiple \
		 rotate_one_multiple \
		 rotate_a \
		 rotate_b \
		 rotate_until_sorted

SORT_SRC = select_algorithm \
	sort_very_short \
	sort_short \
	sort_kinda_medium \
	sort_medium \
	sort_long \
	sort_stack

SRC = create_stack

COMMONSRCPRE = $(addprefix ./src/common/, $(COMMON_SRC))
COMMONSRCSUFF = $(addsuffix .c, $(COMMONSRCPRE))
PARTSRCPRE = $(addprefix ./src/parts/, $(PART_SRC))
PARTSRCSUFF = $(addsuffix .c, $(PARTSRCPRE))
LISTRCPRE = $(addprefix ./src/list/, $(LST_SRC))
LISTRCSUFF = $(addsuffix .c, $(LISTRCPRE))
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
	cc $(BUILD_FLAGS) main.c $(COMMONSRCSUFF) $(PARTSRCSUFF) \
	$(LISTRCSUFF) $(OPSRCSUFF) $(SORTSRCSUFF) $(SRCSUFF) \
	-L $(FT_PRINT_PATH) -lftprintf \
	-L $(LIBFT_PATH) -lft -o $(NAME)

.PHONY: clean
clean:
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINT_PATH)
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINT_PATH)
	rm -f $(NAME)

.PHONY: re
re: fclean all

