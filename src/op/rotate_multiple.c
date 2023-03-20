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

void	rotate_multiple(t_list **head, char stack, int count, void (*f)(t_list **head, char stack))
{
	while (count > 0)
	{
		(*f)(head, stack);
		count--;
	}
}

static void rotate_separate(t_rotate *a_rotate, t_list **a_stack, t_rotate *b_rotate, t_list **b_stack)
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
	{
		if (a_rotate->rev_rotate)
			rotate_multiple(a_stack, a_rotate->stack, a_rotate->rotations, rev_rotate);
		else
			rotate_multiple(a_stack, a_rotate->stack, a_rotate->rotations, rotate);
		return ;
	}
	else if (!a_rotate)
	{
		if (b_rotate->rev_rotate)
			rotate_multiple(b_stack, b_rotate->stack, b_rotate->rotations, rev_rotate);
		else
			rotate_multiple(b_stack, b_rotate->stack, b_rotate->rotations, rotate);
		return ;
	}
	if (a_rotate->rev_rotate != b_rotate->rev_rotate)
	{
		rotate_separate(a_rotate, a_stack, b_rotate, b_stack);
		return ;
	}
	if (a_rotate->rotations > b_rotate->rotations)
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
