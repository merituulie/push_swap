/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:48:12 by meskelin          #+#    #+#             */
/*   Updated: 2023/01/30 16:29:59 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

// Utils
void	print_error(void);
void	print_op(char op, char stack);

// Operations
t_list	*swap(t_list *org_first, char stack);
void	rotate(t_list **head, char stack);
void	rev_rotate(t_list	**head, char stack);
void	push(t_list **to_stack, t_list **from_stack, char stack);

// List
t_list	*ft_lstnew(int data);
void	ft_lstclear(t_list **lst);
void	ft_lstadd(t_list **lst, t_list *new);

t_list	*stack_sort(char *input);
// delete later
t_list	*create_b_stack(char *input);
#endif
