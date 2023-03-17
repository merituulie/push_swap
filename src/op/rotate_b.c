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

static t_rotate	*rotate_or_revrotate(t_list *node, int size)
{
	int	halfway;

	halfway = size / 2;
	if (node->index == 0)
	{
		ft_printf("Node found in index 0, rotating once\n");
		return (rttnew('b', 1, 0, node->data));
	}
	else if (node->index == (size - 1))
	{
		ft_printf("Node found in last index %i, no need for rotation\n");
		return (rttnew('b', 0, 0, node->index));
	}
	if (node->index < halfway)
	{
		ft_printf("Node before halfway.\n");
		ft_printf("Rotating %i times to push.\n", node->index + 1);
		return (rttnew('b', node->index + 1, 0, node->data));
	}
	else
	{
		ft_printf("Node in the middle or after halfway.\n");
		ft_printf("Rotating %i times to push.\n", (size - node->index));
		return (rttnew('b', (size - node->index), 1, node->data));
	}
}

static t_list	*middle_value(t_list **stack, int to_be_pushed, int biggest, int smallest)
{
	t_list	*previous;
	t_list	*next;
	int		index;

	index = 0;
	next = *stack;
	previous = *stack;
	while (previous->next)
		previous = previous->next;
	while (next->next)
	{
		next->index = index;
		if (to_be_pushed < previous->data || to_be_pushed > next->data)
		{
			if (index == 0)
				previous = *stack;
			else
				previous = next;
			next = next->next;
			index++;
		}
		else if (previous->data == smallest || next->data == biggest)
		{
			if (index == 0)
				previous = *stack;
			else
				previous = next;
			next = next->next;
			index++;
		}
		else
			break ;
	}
	ft_printf("found the middle value %i in index %i\n", next->data, next->index);
	return (next);
}

static t_rotate	*biggest_or_smallest(t_list **stack, int to_be_pushed, int size)
{
	t_list *smallest;
	t_list *biggest;

	smallest = find_smallest(*stack, 1);
	biggest = find_biggest(*stack, 1);
	if (to_be_pushed < smallest->data)
	{
		if (smallest->index == (size - 1))
		{
			ft_printf("Found new smallest for the previous smallest %i in last index, rev rotating once.\n", smallest->data);
			return (rttnew('b', 1, 1, to_be_pushed));
		}
		else if (smallest->index == 0)
		{
			ft_printf("Found new smallest for the previous smallest %i in first index, no rotation.\n", smallest->data);
			return (rttnew('b', 0, 0, smallest->data));
		}
		return (rotate_or_revrotate(smallest, size));
	}
	if (to_be_pushed > biggest->data)
	{
		if (biggest->index == (size - 1))
		{
			ft_printf("Found new biggest for the previous biggest %i in last index, rev rotating once.\n", biggest->data);
			return (rttnew('b', 1, 1, to_be_pushed));
		}
		else if (biggest->index == 0)
		{
			ft_printf("Found new biggest for the previous biggest %i in first, no rotation.\n", biggest->data);
			return (rttnew('b', 0, 0, biggest->data));
		}
		return (rotate_or_revrotate(biggest, size));
	}
	return (rotate_or_revrotate(middle_value(stack, to_be_pushed, biggest->data, smallest->data), size));
}

t_rotate	*rotate_b(t_list **b_stack, int to_be_pushed)
{
	int			size;
	t_rotate	*rotate;

	size = lstsize(*b_stack);
	ft_printf("B size %i\n", size);
	if (size <= 1)
		return (rttnew('b', 0, 0, to_be_pushed));
	rotate = biggest_or_smallest(b_stack, to_be_pushed, size);
	ft_printf("B rotation %i times rev as %i for value %i\n", rotate->rotations, rotate->rev_rotate, to_be_pushed);
	return (rotate);
}
