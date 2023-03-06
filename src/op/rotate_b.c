/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:44:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/06 13:44:06 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_rotate	*rotate_or_revrotate(t_list *node, int half_size)
{
	if (node->index == 0)
		return ;
	if (node->index < half_size)
		return (rttcreate('b', node->index, 0));
	else
		return (rttcreate('b', (size - node->index - 1), 1));
}

static t_rotate	*smallest_or_biggest(t_list **stack, int to_be_pushed, int half_size)
{
	t_list *node;

	node = find_smallest(b_stack, 1);
	if (to_be_pushed < smallest)
		return (rotate_or_revrotate(b_stack, node, half_size));
	node = fing_biggest(b_stack, 1);
	if (to_be_pushed > biggest)
		return (rotate_or_revrotate(b_stack, node, half_size));
	return (NULL);
}

static t_rotate	*no_rotation(t_list **stack, int to_be_pushed)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	if (to_be_pushed > first->data && to_be_pushed < last)
		return (rrcreate('b', 0, 0));
	if (to_be_pushed < first->data && to_be_pushed > last)
		return (rrcreate('b', 0, 0));
	return (NULL);
}

static void	middle_value(t_list **stack, int to_be_pushed, int half_way)
{
	t_list	*node;
	int		index;

	node = *stack;
	index = 0;
	while (node->next)
	{
		node->index = index++;
		if (to_be_pushed > node->data && to_be_pushed < node->next->data)
			break ;
		node = node->next;
	}
	if (node->index > half_way)
		node->index++;
	return (rotate_or_revrotate(stack, node, half_way));
}

void	rotate_b(t_list **b_stack, int to_be_pushed)
{
	int			size;
	t_rotate	*rotate;

	size = listsize(b_stack);
	if (size <= 1)
		return ;
	rotate = smallest_or_biggest(b_stack, to_be_pushed, size / 2);
	if (rotate)
		return ;
	rotate = no_rotation(b_stack, to_be_pushed);
	if (rotate)
		return ;
	rotate = middle_value(b_stack, to_be_pushed, size / 2);
	return (rotate);
}
