/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:44:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/17 12:26:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static t_rotate	*rotate_or_revrotate(t_list *node, int size, int to_be_pushed)
{
	int halfway;

	halfway = size / 2;
	ft_printf("Got %i as the previous node ", node->data);
	ft_printf("in index %i ", node->index);
	ft_printf("with value %i to be pushed\n", to_be_pushed);
	ft_printf("%i is halfway\n", halfway);
	if (node->index == (size - 1))
		rotate_last_index(node, to_be_pushed);
	if (node->index < halfway)
		rotate_before_halfway(node, to_be_pushed);
	else
		rotate_after_halfway(node, size, to_be_pushed);
	return (rttnew('b', 0, 0, to_be_pushed));
}

static t_list	*find_previous_node(int to_be_pushed, t_list *previous, t_list *next)
{
	if (to_be_pushed < next->data)
	{
		ft_printf("found the previous value %i", previous->data);
		ft_printf("in index  %i\n", previous->index);
		return (previous);
	}
	ft_printf("found the previous value %i", next->data);
	ft_printf("in index %i\n", next->index);
	return (next);
}

static t_list	*middle_value(t_list **stack, int to_be_pushed, int biggest, int smallest)
{
	t_list	*previous;
	t_list	*next;
	int		n_index;
	int		p_index;

	n_index = 0;
	p_index = lstsize(*stack) - 1;
	next = *stack;
	previous = *stack;
	while (previous->next)
		previous = previous->next;
	while (next->next)
	{
		next->index = n_index;
		if (n_index != 0)
			p_index = n_index - 1;
		previous->index = p_index;
		if ((previous->data == biggest && next->data == smallest)
			|| (next->data == biggest && previous->data == smallest))
		{
			if (n_index == 0)
				previous = *stack;
			else
				previous = next;
			next = next->next;
			n_index++;
			continue ;
		}
		else if ((to_be_pushed < previous->data && to_be_pushed > next->data)
			|| (to_be_pushed > previous->data && to_be_pushed < next->data))
			break;
		if (n_index == 0)
			previous = *stack;
		else
			previous = next;
		next = next->next;
		n_index++;
	}
	return (find_previous_node(to_be_pushed, previous, next));
}

static t_rotate	*find_rotate(t_list **stack, int to_be_pushed, int size)
{
	t_list *smallest;
	t_list *biggest;

	smallest = find_smallest(*stack, 1);
	biggest = find_biggest(*stack, 1);
	if (to_be_pushed < smallest->data)
	{
		if (smallest->index == 0 || smallest->index == (size - 1))
			return (rotate_first_or_last_bs(smallest, biggest, to_be_pushed));
		return (rotate_for_biggest_or_smallest_middle(biggest, size, smallest->data));
	}
	if (to_be_pushed > biggest->data)
	{
		if (biggest->index == 0 || biggest->index == (size - 1))
			return (rotate_first_or_last_bs(biggest, smallest, to_be_pushed));
		return (rotate_for_biggest_or_smallest_middle(smallest, size, biggest->data));
	}
	ft_printf("%i not biggest or smallest, checking for the position in the middle\n", to_be_pushed);
	return (rotate_or_revrotate(middle_value(stack, to_be_pushed, biggest->data, smallest->data), size, to_be_pushed));
}

t_rotate	*rotate_b(t_list **b_stack, int to_be_pushed)
{
	int			size;
	t_rotate	*rotate;

	size = lstsize(*b_stack);
	ft_printf("B size %i\n", size);
	if (size <= 1)
		return (rttnew('b', 0, 0, to_be_pushed));
	if (size == 3)
		sort_short(b_stack);
	rotate = find_rotate(b_stack, to_be_pushed, size);
	ft_printf("B rotation %i times rev as %i for value %i\n", rotate->rotations, rotate->rev_rotate, to_be_pushed);
	return (rotate);
}
