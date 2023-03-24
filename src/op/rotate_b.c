/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:44:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 16:16:05 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_list	*find_last(t_list *previous, t_list **stack)
{
	previous = *stack;
	while (previous->next)
		previous = previous->next;
	return (previous);
}

static t_rotate	*middle_value(t_list **stack, int to_be_pushed,
					int biggest, int smallest)
{
	t_list	*previous;
	t_list	*next;
	int		n_index;
	int		p_index;

	n_index = 0;
	p_index = lstsize(*stack) - 1;
	next = *stack;
	previous = NULL;
	previous = find_last(previous, stack);
	while (next->next)
	{
		iterate_indexes(&previous, &next, n_index, p_index);
		if (is_bs(previous, next, biggest, smallest))
		{
			n_index = iterate_stack(&previous, &next, stack, n_index);
			continue ;
		}
		else if (is_middle(to_be_pushed, previous, next))
			break ;
		n_index = iterate_stack(&previous, &next, stack, n_index);
	}
	return (find_previous(to_be_pushed, previous, next, lstsize(*stack)));
}

static t_rotate	*find_rotate(t_list **stack, int to_be_pushed, int size)
{
	t_list	*smallest;
	t_list	*biggest;

	smallest = find_smallest(*stack, 1);
	biggest = find_biggest(*stack, 1);
	if (to_be_pushed < smallest->data)
	{
		if (smallest->index == 0 || smallest->index == (size - 1))
			return (rotate_for_smallest(smallest, size));
		return (rotate_for_smallest_middle(smallest, size));
	}
	if (to_be_pushed > biggest->data)
	{
		if (biggest->index == 0 || biggest->index == (size - 1))
			return (rotate_for_biggest(biggest, size));
		return (rotate_for_biggest_middle(biggest, size));
	}
	return (middle_value(stack, to_be_pushed, biggest->data, smallest->data));
}

t_rotate	*rotate_b(t_list **b_stack, int to_be_pushed)
{
	int			size;
	t_rotate	*rotate;

	size = lstsize(*b_stack);
	if (size <= 1)
		return (rttnew('b', 0, 0, to_be_pushed));
	rotate = find_rotate(b_stack, to_be_pushed, size);
	return (rotate);
}
