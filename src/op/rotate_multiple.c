/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_multiple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:14:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/20 16:09:56 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	rotate_multiple_both(t_list **a_stack, t_list **b_stack, int count, void (*f)(t_list **head, char stack))
{
	while (count > 0)
	{
		(*f)(a_stack, '\0');
		(*f)(b_stack, 'r');
		count--;
	}
}

static void rotate_both_stacks(t_rotate *bigger_r, t_list **bigger_l, t_rotate *smaller_r, t_list **smaller_l)
{
	int extra_count;

	extra_count = bigger_r->rotations - smaller_r->rotations;
	if (bigger_r->rev_rotate)
	{
		rotate_multiple_both(bigger_l, smaller_l, smaller_r->rotations, rev_rotate);
		rotate_multiple(bigger_l, bigger_r->stack, extra_count, rev_rotate);
		return ;
	}
	rotate_multiple_both(bigger_l, smaller_l, smaller_r->rotations, rotate);
	rotate_multiple(bigger_l, bigger_r->stack, extra_count, rotate);
}

void	rotate_both(t_list **a_stack, t_list **b_stack, t_rotate *a_rotate, t_rotate *b_rotate)
{
	if (!a_rotate && !b_rotate)
		return ;
	if (!b_rotate)
		rotate_one_multiple(a_stack, a_rotate);
	else if (!a_rotate)
		rotate_one_multiple(b_stack, b_rotate);
	else if (a_rotate->rev_rotate != b_rotate->rev_rotate)
		rotate_separate(a_rotate, a_stack, b_rotate, b_stack);
	else if (a_rotate->rotations > b_rotate->rotations)
		rotate_both_stacks(a_rotate, a_stack, b_rotate, b_stack);
	else if (a_rotate->rotations < b_rotate->rotations)
		rotate_both_stacks(b_rotate, b_stack, a_rotate, a_stack);
	else
	{
		if (a_rotate->rev_rotate)
			rotate_multiple_both(a_stack, b_stack, a_rotate->rotations, rev_rotate);
		else
			rotate_multiple_both(a_stack, b_stack, a_rotate->rotations, rotate);
	}
}
