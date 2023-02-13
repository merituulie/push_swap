/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:48:12 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/13 17:16:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define NO_ALG 1
# define VERY_SHORT_ALG 2
# define SHORT_ALG 3
# define MEDIUM_ALG 5
# define LONG_ALG 6

// # define PUSH 1
// # define SWAP 2
// # define ROTATE 3
// # define REV_ROTATE 4

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

// typedef struct s_tuple
// {
// 	int	count;
// 	int	operation;
// }	t_tuple;

// Utils
void	print_error(void);
void	print_op(char op, char stack);
void	*clearlst_throw(t_list **stack_a, t_list **stack_b, char **str, int throw);
void	exit_failure(t_list **a, t_list **b, char **str);
void	exit_success(t_list **a, t_list **b);

// List
t_list	*ft_lstnew(int data);
void	ft_lstclear(t_list **lst);
void	ft_lstadd(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst, int max);
void	add_to_stack(t_list **stack, int data);

// Operations
void	swap(t_list **head, char stack);
void	rotate(t_list **head, char stack);
void	rev_rotate(t_list	**head, char stack);
void	push(t_list **to_stack, t_list **from_stack, char stack);

// Sorting
int		select_algorithm(t_list **stack);
void	sort_very_short(t_list **head);
void	sort_short(t_list **head);
void	sort_stack(t_list **stack, int sort_algorithm);
void	sort_medium(t_list **head);

// Stack
t_list	*create_stack(char *input);
// delete later
t_list	*create_b_stack(char *input);
#endif
