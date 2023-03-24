/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:49:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 16:12:29 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	reinit_indexes(t_list *first_hold, t_list *second_hold)
{
	if (first_hold)
		first_hold->index = -1;
	if (second_hold)
		second_hold->index = -1;
}

static int	just_break(int max_count, t_list **a_stack,
				t_list **b_stack)
{
	t_rotate	*rotation;

	if (max_count == 0)
		return (1);
	if (max_count == 1)
	{
		rotation = rotate_b(b_stack, (*a_stack)->data);
		if (rotation)
		{
			if (rotation->rev_rotate)
				rotate_multiple(b_stack, rotation->stack,
					rotation->rotations, rev_rotate);
			else
				rotate_multiple(b_stack, rotation->stack,
					rotation->rotations, rotate);
			free(rotation);
		}
		push(b_stack, a_stack, 'b');
		return (1);
	}
	return (0);
}

static void	rotate_stacks(t_list **a_stack, t_list **b_stack,
				t_list *first_hold, t_list *second_hold)
{
	int			max_count;
	t_rotate	*a_rotate;
	t_rotate	*b_rotate;

	a_rotate = NULL;
	b_rotate = NULL;
	max_count = get_listsize(a_stack);
	a_rotate = rotate_a(first_hold, second_hold, max_count);
	b_rotate = rotate_b(b_stack, a_rotate->to_be_pushed);
	rotate_both(a_stack, b_stack, a_rotate, b_rotate);
	free(a_rotate);
	free(b_rotate);
}

static void	search_push_rotate(t_list **b_stack, t_list **a_stack,
				int smallest, int biggest)
{
	t_list	*first_hold;
	t_list	*second_hold;
	int		max_count;

	while (1)
	{
		first_hold = NULL;
		second_hold = NULL;
		max_count = get_listsize(a_stack);
		if (just_break(max_count, a_stack, b_stack))
			break ;
		first_hold = search_from_top(a_stack, smallest, biggest, max_count);
		second_hold = search_from_bottom(a_stack, smallest,
				biggest, max_count);
		if (!first_hold && !second_hold)
			break ;
		rotate_stacks(a_stack, b_stack, first_hold, second_hold);
		reinit_indexes(first_hold, second_hold);
		push(b_stack, a_stack, 'b');
	}
}

void	sort_long(t_list **head, int part_count)
{
	t_part	*parts;
	t_part	*parts_head;
	t_list	*b;

	parts = NULL;
	b = NULL;
	parts = init_parts(head, part_count);
	parts_head = parts;
	while (parts)
	{
		search_push_rotate(&b, head, parts->smallest,
			parts->biggest);
		parts = parts->next;
	}
	rotate_until_sorted(&b, lstsize(b));
	while (b)
		push(head, &b, 'a');
	prtclear(&parts_head);
	clearall_throw(head, &b, NULL, 0);
}
