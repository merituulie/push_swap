/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_separate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:23:44 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/21 18:23:44 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

void	rotate_multiple(t_list **head, char stack, int count, void (*f)(t_list **head, char stack))
{
	while (count > 0)
	{
		(*f)(head, stack);
		count--;
	}
}

void	rotate_separate(t_rotate *a_rotate, t_list **a_stack, t_rotate *b_rotate, t_list **b_stack)
{
	if (a_rotate->rev_rotate)
	{
		rotate_multiple(a_stack, 'a', a_rotate->rotations, rev_rotate);
		rotate_multiple(b_stack, 'b', b_rotate->rotations, rotate);
		return ;
	}
	ft_printf("Rotating b %i times as rev %i and A %i times with rev %i\n", b_rotate->rotations, b_rotate->rev_rotate, a_rotate->rotations, a_rotate->rev_rotate);
	rotate_multiple(a_stack, 'a', a_rotate->rotations, rotate);
	rotate_multiple(b_stack, 'b', b_rotate->rotations, rev_rotate);
}

void	rotate_one_multiple(t_list **head, t_rotate	*rotate)
{
	if (rotate->rev_rotate)
		rotate_multiple(head, rotate->stack, rotate->rotations, rev_rotate);
	else
		rotate_multiple(head, rotate->stack, rotate->rotations, rotate);
}
