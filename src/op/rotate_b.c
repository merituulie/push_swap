/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:44:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/10 17:17:28 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static t_rotate	*rotate_or_revrotate(t_list *node, int half_size)
{
	if (node->index == 0)
		return (rttnew('b', 0, 0, node->data));
	if (node->index <= half_size)
	{
		ft_printf("rotating %i times tto get to value %i\n", node->index, node->data);
		return (rttnew('b', node->index, 0, node->data));
	}
	else
		return (rttnew('b', ((half_size * 2) - node->index), 1, node->data));
}

static t_rotate	*smallest_or_biggest(t_list **stack, int to_be_pushed, int half_size)
{
	t_list *node;

	node = find_smallest(*stack, 1);
	if (to_be_pushed < node->data)
	{
		ft_printf("smallest in b %i in index %i and evaluated against to be pushed %i\n", node->data, node->index, to_be_pushed);
		return (rotate_or_revrotate(node, half_size));
	}
	node = find_biggest(*stack, 1);
	if (to_be_pushed > node->data)
	{
		ft_printf("biggest in b %i in index %i and evaluated against to be pushed %i\n", node->data, node->index, to_be_pushed);
		return (rotate_or_revrotate(node, half_size));
	}
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
	if (to_be_pushed > first->data && to_be_pushed < last->data)
		return (rttnew('b', 0, 0, to_be_pushed));
	if (to_be_pushed < first->data && to_be_pushed > last->data)
		return (rttnew('b', 0, 0, to_be_pushed));
	return (NULL);
}

static t_rotate	*middle_value(t_list **stack, int to_be_pushed, int half_way)
{
	t_list	*node;
	int		index;

	node = *stack;
	index = 0;
	while (node->next)
	{
		node->index = index;
		ft_printf("evaluating %i against %i\n", to_be_pushed, node->data);
		if (to_be_pushed > node->data)
			break ;
		node = node->next;
		index++;
	}
	if (node->index > half_way)
		node->index++;
	ft_printf("found the middle value %i in index %i\n", node->data, node->index);
	return (rotate_or_revrotate(node, half_way));
}

t_rotate	*rotate_b(t_list **b_stack, int to_be_pushed)
{
	int			size;
	t_rotate	*rotate;

	size = lstsize(*b_stack);
	ft_printf("B size %i\n", size);
	if (size <= 1)
		return (rttnew('b', 0, 0, to_be_pushed));
	rotate = smallest_or_biggest(b_stack, to_be_pushed, size / 2);
	if (!rotate)
	{
		ft_printf("%i is not smallest or biggest in B!\n", to_be_pushed);
		rotate = middle_value(b_stack, to_be_pushed, size / 2);
	}
	if (!rotate)
	{
		ft_printf("%i does not belong to the middle B!\n", to_be_pushed);
		rotate = no_rotation(b_stack, to_be_pushed);
	}
	ft_printf("B rotation %i times rev as %i for value %i\n", rotate->rotations, rotate->rev_rotate, to_be_pushed);
	return (rotate);
}
