/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:48:12 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/20 18:13:05 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define NO_ALG 1
# define VERY_SHORT_ALG 2
# define SHORT_ALG 3
# define KINDA_MEDIUM_ALG 4
# define MEDIUM_ALG 5
# define LONG_ALG 6

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_part
{
	int				smallest;
	int				biggest;
	struct s_part	*next;
}	t_part;

typedef struct s_rotate
{
	char	stack;
	int		rotations;
	int		rev_rotate;
	int		to_be_pushed;
}	t_rotate;

// Common
void		print_error(void);
void		print_op(char op, char stack, int endl);
void		*clearall_throw(t_list **stack_a,
				t_list **stack_b, char **str, int throw);
void		exit_failure(t_list **a, t_list **b, char **str);
void		exit_success(t_list **a, t_list **b);
void		clear_parts(t_part **parts);
t_list		*find_biggest(t_list *head, int add_index);
t_list		*find_smallest(t_list *head, int add_index);
int			find_next_smallest(t_list *head, int smaller);
t_list		*search_from_bottom(t_list **a_stack, int smallest,
			int biggest, int max_count);
t_list		*search_from_top(t_list **a_stack, int smallest, int biggest, int max_count);
t_rotate	*rttnew(char stack, int rotations, int rev_rotate, int to_be_pushed);
t_rotate	*rotate_for_biggest_or_smallest_middle(t_list *other_end, int size, int previous_value);
t_rotate	*rotate_first_or_last_bs(t_list *first, t_list *second, int to_be_pushed);
t_rotate	*rotate_size3(t_list *node, int to_be_pushed);
t_rotate	*rotate_size2(t_list *node, int to_be_pushed);
t_rotate	*rotate_for_smallest(t_list *small, int size);
t_rotate	*rotate_for_biggest(t_list *big, int size);
t_rotate	*rotate_for_smallest_middle(t_list *small, int size);
t_rotate	*rotate_for_biggest_middle(t_list *big, int size);
t_rotate	*rotate_or_revrotate(t_list *smaller, t_list *bigger, int size, int to_be_pushed);
int			is_bs(t_list *previous, t_list *next, int biggest, int smallest);
int			is_middle(int to_be_pushed, t_list *previous, t_list *next);
void		iterate_indexes(t_list **previous, t_list **next, int n_index, int p_next);
int			iterate_stack(t_list **previous, t_list **next, t_list **stack, int n_index);
t_rotate	*find_previous(int to_be_pushed, t_list *previous, t_list *next, int size);

// List
t_list	*lstnew(int data);
void	lstclear(t_list **lst);
void	lstadd(t_list **lst, t_list *new);
int		lstsize(t_list *lst);
int		get_listsize(t_list **head);
t_list	*lstlast(t_list **lst);
void	lstadd_to_stack(t_list **stack, int data);

// Parts
int		select_part_count(int select_algorithm, int size);
t_part	*prtnew(int smallest, int biggest);
void	prtclear(t_part **lst);
void	prtadd(t_part **lst, t_part *new);
t_part	*prtlast(t_part **lst);
void	prtadd_to_parts(t_part **stack, int smallest, int biggest, int first_time);
t_part	*init_parts(t_list **head, int part_count);

// Operations
void	swap(t_list **head, char stack);
void	rotate(t_list **head, char stack);
void	rev_rotate(t_list	**head, char stack);
void	push(t_list **to_stack, t_list **from_stack, char stack);
void	rotate_multiple(t_list **head, char stack, int count,
			void (*f)(t_list **head, char stack));

// Sorting
int			select_algorithm(int max_count);
void		sort_very_short(t_list **head);
void		sort_short(t_list **head);
void		sort_medium(t_list **head);
t_rotate	*rotate_a(t_list *first_hold, t_list *second_hold, int max_count);
t_rotate	*rotate_b(t_list **b_stack, int to_be_pushed);
void		rotate_both(t_list **a_stack, t_list **b_stack, t_rotate *a_rotate, t_rotate *b_rotate);
void		rotate_until_sorted(t_list **stack);
void		sort_kinda_medium(t_list **head);
void		sort_long(t_list **head, int part_count);
void		sort_stack(t_list **stack, int sort_algorithm, int part_count);

// Stack
t_list	*create_stack(char *input);
#endif
