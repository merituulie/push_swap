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
	int	halfway;

	halfway = size / 2;
	to_be_pushed = 0;
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
		if (size == 3 && node->index == 1)
		{
			ft_printf("Node found halfway with stack size 3, rev rotating once to get %i to the bottom\n");
			return (rttnew('b', 1, 1, node->index));
		}
		ft_printf("Node in the middle or after halfway.\n");
		ft_printf("Rotating %i times to push.\n", (size - node->index));
		return (rttnew('b', (size - node->index - 1), 1, node->data));
	}
}

static t_list	*middle_value(t_list **stack, int to_be_pushed, int biggest, int smallest)
{
	t_list	*previous;
	t_list	*next;
	int		n_index;
	int		p_index;

	n_index = 0;
	p_index = lstsize(*stack);
	next = *stack;
	previous = *stack;
	while (previous->next)
		previous = previous->next;
	while (next->next)
	{
		next->index = n_index;
		previous->index = p_index;
		ft_printf("biggest %i\n", biggest);
		ft_printf("smallest %i\n", smallest);
		ft_printf("to_be_pushed %i\n", to_be_pushed);
		ft_printf("previous %i\n", previous->data);
		ft_printf("next %i\n\n", next->data);
		if ((previous->data == biggest && next->data == smallest)
			|| (next->data == biggest && previous->data == smallest))
		{
			if (n_index == 0)
				previous = *stack;
			else
				previous = next;
			p_index = n_index;
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
		p_index = n_index;
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
			ft_printf("Found new smallest for the previous smallest %i in last index, rev rotating once.\n", smallest->data);
			return (rttnew('b', 1, 1, to_be_pushed));
		}
		else if (smallest->index == 0)
		{
			ft_printf("Found new smallest for the previous smallest %i in first index, no rotation.\n", smallest->data);
			return (rttnew('b', 0, 0, smallest->data));
		}
		return (rotate_or_revrotate(smallest, size, to_be_pushed));
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
		return (rotate_or_revrotate(biggest, size, to_be_pushed));
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
	rotate = find_rotate(b_stack, to_be_pushed, size);
	ft_printf("B rotation %i times rev as %i for value %i\n", rotate->rotations, rotate->rev_rotate, to_be_pushed);
	return (rotate);
}
