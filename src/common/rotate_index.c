/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:38:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/19 10:38:59 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotate	*rotate_last_index(t_list *node)
{
	if (node->prev->data < node->data)
		return (rttnew('b', 0, 0, node->data));
	else
		return (rttnew('b', 1, 1, node->data));
}

t_rotate	*rotate_before_halfway(t_list *node)
{
	if (node->next && node->next->data > node->data)
		return (rttnew('b', node->index + 1, 0, node->data));
	else
		return (rttnew('b', node->index, 0, node->data));
}

t_rotate	*rotate_after_halfway(t_list *node, int size)
{
	if (node->next && node->next->data > node->data)
		return (rttnew('b', (size - 1 - node->index), 1, node->data));
	else
		return (rttnew('b', (size - node->index), 1, node->data));
}

t_rotate	*rotate_for_biggest_or_smallest_middle(t_list *other_end, int size, int previous_value)
{
	int halfway;

	halfway = size / 2;
	ft_printf("Got %i as the previous node ", other_end->data);
	ft_printf("in index %i ", other_end->index);
	if (other_end->index == (size - 1))
	{
		if (other_end->prev->data != previous_value)
			return (rttnew('b', 0, 0, previous_value));
		else
			return (rttnew('b', 1, 1, previous_value));
	}
	if (other_end->index < halfway)
	{
		if (other_end->next && other_end->next->data != previous_value)
			return (rttnew('b', other_end->index, 0, previous_value));
		else
			return (rttnew('b', other_end->index + 1, 0, previous_value));
	}
	if (other_end->next && other_end->next->data != previous_value)
		return (rttnew('b', (size - other_end->index), 1, previous_value));
	else
		return (rttnew('b', (size - other_end->index - 1), 1, previous_value));
}

t_rotate	*rotate_first_or_last_bs(t_list *first, t_list *second, int to_be_pushed)
{
	if (first->index == (size - 1))
	{
		if (second->index == 0)
			return (rttnew('b', 0, 0, to_be_pushed));
		else
		{
			ft_printf("Found new first for the previous first %i in last index, rev rotating once.\n", first->data);
			return (rttnew('b', 1, 1, to_be_pushed));
		}
	}
	else if (first->index == 0)
	{
		if (first->next->data == second->data)
			return (rttnew('b', 1, 0, to_be_pushed));
		else
		{
			ft_printf("Found new first for the previous first %i in first index, no rotation.\n", first->data);
			return (rttnew('b', 0, 0, first->data));
		}
	}
}
