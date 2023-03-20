/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:44:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/20 18:35:51 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static t_rotate	*rotate_or_revrotate(t_list *smaller, t_list *bigger, int size, int to_be_pushed)
{
	int halfway;

	halfway = size / 2;
	ft_printf("Got %i as the smaller node ", smaller->data);
	ft_printf("in index %i and bigger node as %i in index %i ", smaller->index, bigger->data, bigger->index);
	ft_printf("with value %i to be pushed\n", to_be_pushed);
	ft_printf("%i is halfway\n", halfway);
	if (size == 2)
		return (rotate_size2(smaller, to_be_pushed));
	if (size == 3)
		return (rotate_size3(smaller, to_be_pushed));
	if (smaller->index == (size - 1))
		return (rttnew('b', 1, 1, smaller->data));
	if (smaller->index < halfway)
		return (rttnew('b', smaller->index, 0, smaller->data));
	else
		return (rttnew('b', (size - smaller->index - 1), 1, smaller->data));
}

static t_rotate	*find_rotation(int to_be_pushed, t_list *previous, t_list *next, int size)
{
	ft_printf("previous > %i, next > %i\n", previous->data, next->data);
	if (to_be_pushed < previous->data)
		return (rotate_or_revrotate(next, previous, size, to_be_pushed));
	return (rotate_or_revrotate(previous, next, size, to_be_pushed));
}

static t_rotate	*middle_value(t_list **stack, int to_be_pushed, int biggest, int smallest)
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
	ft_printf("biggest %i smallest %i\n", biggest, smallest);
	while (next->next)
	{
		if (n_index != 0)
			p_index = n_index - 1;
		next->index = n_index;
		previous->index = p_index;
		ft_printf("previous %i next %i to be pushed %i\n", previous->data, next->data, to_be_pushed);
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
	return (find_rotation(to_be_pushed, previous, next, lstsize(*stack)));
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
			return (rotate_for_smallest(smallest, size));
		return (rotate_or_revrotate_smallest(smallest, biggest, size, to_be_pushed));
	}
	if (to_be_pushed > biggest->data)
	{
		if (biggest->index == 0 || biggest->index == (size - 1))
			return (rotate_for_biggest(biggest, size));
		return (rotate_or_revrotate_biggest(smallest, biggest, size, to_be_pushed));
	}
	return (middle_value(stack, to_be_pushed, biggest->data, smallest->data));
}

t_rotate	*rotate_b(t_list **b_stack, int to_be_pushed)
{
	int			size;
	t_rotate	*rotate;

	size = lstsize(*b_stack);
	ft_printf("B size %i\n", size);
	if (size <= 1)
		return (rttnew('b', 0, 0, to_be_pushed));
	rotate = find_rotate(b_stack, to_be_pushed, size);
	ft_printf("B rotation %i times rev as %i for value %i\n", rotate->rotations, rotate->rev_rotate, to_be_pushed);
	return (rotate);
}
