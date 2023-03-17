/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:44:06 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/13 18:43:55 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static t_rotate	*rotate_or_revrotate(t_list *node, int size)
{
	int	halfway;
	int	size_module;

	halfway = size / 2;
	size_module = size % 2;
	if (node->index == 0)
		return (rttnew('b', 1, 0, node->data));
	if (halfway == 1)
	{
		if (node->index == 1)
		{
			ft_printf("rotating %i times to get to value %i\n", node->index, node->data);
			return (rttnew('b', node->index, 0, node->data));
		}
		else
		{
			ft_printf("rev rotating 1 time to get to value %i\n", node->data);
			return (rttnew('b', 1, 1, node->data));
		}
	}
	if (size_module != 0)
	{
		if (node->index < halfway)
		{
			ft_printf("rotating %i times to get to value %i\n", node->index, node->data);
			return (rttnew('b', node->index, 0, node->data));
		}
		else
		{
			ft_printf("rev rotating %i times to get to value %i\n", node->index, node->data);
			return (rttnew('b', (size - node->index - 1), 1, node->data));
		}
	}
	else
	{
		if (node->index <= halfway)
		{
			ft_printf("rotating %i times to get to value %i\n", node->index, node->data);
			return (rttnew('b', node->index, 0, node->data));
		}
		else
		{
			ft_printf("rev rotating %i times to get to value %i\n", (size - node->index), node->data);
			return (rttnew('b', (size - node->index), 1, node->data));
		}
	}
}

static t_rotate	*smallest_or_biggest(t_list **stack, int to_be_pushed, int size)
{
	t_list *node;

	node = find_smallest(*stack, 1);
	if (to_be_pushed < node->data)
	{
		ft_printf("smallest in b %i in index %i and evaluated against to be pushed %i\n", node->data, node->index, to_be_pushed);
		return (rotate_or_revrotate(node, size));
	}
	node = find_biggest(*stack, 1);
	if (to_be_pushed > node->data)
	{
		ft_printf("biggest in b %i in index %i and evaluated against to be pushed %i\n", node->data, node->index, to_be_pushed);
		return (rotate_or_revrotate(node, size));
	}
	return (NULL);
}

static int	fits_middle_fslb(t_list *middle_node, t_list *first, t_list *last)
{
	if (!middle_node)
		return (0);
	if ((last->data - first->data) <= (last->data - middle_node->data))
		return (0);
	return (1);
}

static int	fits_middle_fbls(t_list *middle_node, t_list *first, t_list *last)
{
	if (!middle_node)
		return (0);
	if ((first->data - last->data) <= (first->data - middle_node->data))
		return (0);
	return (1);
}

static t_list	*middle_value(t_list **stack, int to_be_pushed)
{
	t_list	*node;
	int		index;

	node = *stack;
	index = 0;
	while (node)
	{
		node->index = index;
		ft_printf("evaluating %i against %i\n", to_be_pushed, node->data);
		if (to_be_pushed > node->data)
		{
			if (!node->next || to_be_pushed < node->next->data)
			{
				if (node->data != find_smallest(*stack, 0)->data && node->data != find_smallest(*stack, 0)->data)
					break ;
			}
		}
		else if (to_be_pushed < node->data)
		{
			if (!node->next || to_be_pushed > node->next->data)
			{
				if (node->data != find_smallest(*stack, 0)->data && node->data != find_smallest(*stack, 0)->data)
				{
					node->index++;
					break ;
				}
			}
		}
		node = node->next;
		index++;
	}
	ft_printf("found the middle value %i in index %i\n", node->data, node->index);
	return (node);
}

static t_rotate	*find_rotate(t_list **stack, int to_be_pushed, int size)
{
	t_list		*first;
	t_list		*last;
	t_list		*middle_node;

	first = *stack;
	last = *stack;
	middle_node = middle_value(stack, to_be_pushed);
	while (last->next)
		last = last->next;
	if (to_be_pushed > first->data && to_be_pushed < last->data
		&& !fits_middle_fslb(middle_node, first, last))
		return (rttnew('b', 0, 0, to_be_pushed));
	if (to_be_pushed < first->data && to_be_pushed > last->data
		&& !fits_middle_fbls(middle_node, first, last))
		return (rttnew('b', 0, 0, to_be_pushed));
	return (rotate_or_revrotate(middle_node, size));
}

t_rotate	*rotate_b(t_list **b_stack, int to_be_pushed)
{
	int			size;
	t_rotate	*rotate;

	size = lstsize(*b_stack);
	ft_printf("B size %i\n", size);
	if (size <= 1)
		return (rttnew('b', 0, 0, to_be_pushed));
	rotate = smallest_or_biggest(b_stack, to_be_pushed, size);
	if (!rotate)
	{
		ft_printf("%i is not the biggest or smallest B!\n", to_be_pushed);
		rotate = find_rotate(b_stack, to_be_pushed, size);
	}
	ft_printf("B rotation %i times rev as %i for value %i\n", rotate->rotations, rotate->rev_rotate, to_be_pushed);
	return (rotate);
}
