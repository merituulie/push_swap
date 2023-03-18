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

static t_rotate	*rotate_or_revrotate_biggest(t_list *smallest, int size, int biggest)
{
	int halfway;

	halfway = size / 2;
	ft_printf("Got %i as the previous node ", smallest->data);
	ft_printf("in index %i ", smallest->index);
	if (smallest->index == (size - 1))
	{
		if (smallest->prev->data != biggest)
			return (rttnew('b', 0, 0, biggest));
		else
			return (rttnew('b', 1, 1, biggest));
	}
	if (smallest->index < halfway)
	{
		if (smallest->next && smallest->next->data != biggest)
		{
			return (rttnew('b', smallest->index, 0, biggest));
		}
		else
			return (rttnew('b', smallest->index + 1, 0, biggest));
	}
	else
	{
		if (smallest->next && smallest->next->data != biggest)
		{
			return (rttnew('b', (size - smallest->index), 1, biggest));
		}
		else
			return (rttnew('b', (size - smallest->index - 1), 1, biggest));
	}
	return (rttnew('b', 0, 0, biggest));
}

static t_rotate	*rotate_or_revrotate_smallest(t_list *biggest, int size, int smallest)
{
	int halfway;

	halfway = size / 2;
	ft_printf("Got %i as the previous node ", biggest->data);
	ft_printf("in index %i ", biggest->index);
	if (biggest->index == (size - 1))
	{
		if (biggest->prev->data != smallest)
			return (rttnew('b', 0, 0, smallest));
		else
			return (rttnew('b', 1, 1, smallest));
	}
	if (biggest->index < halfway)
	{
		if (biggest->next && biggest->next->data != smallest)
		{
			return (rttnew('b', biggest->index, 0, smallest));
		}
		else
			return (rttnew('b', biggest->index + 1, 0, smallest));
	}
	else
	{
		if (biggest->next && biggest->next->data != smallest)
		{
			return (rttnew('b', (size - biggest->index), 1, smallest));
		}
		else
			return (rttnew('b', (size - biggest->index - 1), 1, smallest));
	}
	return (rttnew('b', 0, 0, smallest));
}

static t_rotate	*rotate_or_revrotate(t_list *node, int size, int to_be_pushed)
{
	int halfway;

	halfway = size / 2;
	ft_printf("Got %i as the previous node ", node->data);
	ft_printf("in index %i ", node->index);
	ft_printf("with value %i to be pushed\n", to_be_pushed);
	ft_printf("%i is halfway\n", halfway);
	if (node->index == (size - 1))
	{
		if (node->prev->data < node->data)
			return (rttnew('b', 0, 0, to_be_pushed));
		else
			return (rttnew('b', 1, 1, to_be_pushed));
	}
	if (node->index < halfway)
	{
		if (node->next && node->next->data > node->data)
		{
			return (rttnew('b', node->index + 1, 0, to_be_pushed));
		}
		else
			return (rttnew('b', node->index, 0, to_be_pushed));
	}
	else
	{
		if (node->next && node->next->data > node->data)
		{
			return (rttnew('b', (size - 1 - node->index), 1, to_be_pushed));
		}
		else
			return (rttnew('b', (size - node->index), 1, to_be_pushed));
	}
	return (rttnew('b', 0, 0, to_be_pushed));
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
	if (to_be_pushed < next->data)
	{
		ft_printf("found the previous value %i", previous->data);
		ft_printf("in index  %i\n", previous->index);
		return (previous);
	}
	else
	{
		ft_printf("found the previous value %i", next->data);
		ft_printf("in index %i\n", next->index);
		return (next);
	}
}

static t_rotate	*find_rotate(t_list **stack, int to_be_pushed, int size)
{
	t_list *smallest;
	t_list *biggest;

	smallest = find_smallest(*stack, 1);
	biggest = find_biggest(*stack, 1);
	if (to_be_pushed < smallest->data)
	{
		if (smallest->index == (size - 1))
		{
			if (biggest->index == 0)
				return (rttnew('b', 0, 0, to_be_pushed));
			else
			{
				ft_printf("Found new smallest for the previous smallest %i in last index, rev rotating once.\n", smallest->data);
				return (rttnew('b', 1, 1, to_be_pushed));
			}
		}
		else if (smallest->index == 0)
		{
			if (smallest->next->data == biggest->data)
				return (rttnew('b', 1, 0, to_be_pushed));
			else
			{
				ft_printf("Found new smallest for the previous smallest %i in first index, no rotation.\n", smallest->data);
				return (rttnew('b', 0, 0, smallest->data));
			}
		}
		return (rotate_or_revrotate_smallest(biggest, size, smallest->data));
	}
	if (to_be_pushed > biggest->data)
	{
		if (biggest->index == (size - 1))
		{
			if (smallest->index == 0)
				return (rttnew('b', 0, 0, to_be_pushed));
			else
				return (rttnew('b', 1, 1, to_be_pushed));
		}
		else if (biggest->index == 0)
		{
			if (biggest->next->data != smallest->data)
			{
				ft_printf("Found new biggest for the previous biggest %i in first, no rotation.\n", biggest->data);
				return (rttnew('b', 0, 0, biggest->data));
			}
			else
				return (rttnew('b', 1, 0, biggest->data));
		}
		return (rotate_or_revrotate_biggest(smallest, size, biggest->data));
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
