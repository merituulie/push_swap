/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:43:43 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 14:51:54 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_index(t_list *node, int smallest)
{
	int	count;

	count = 0;
	while (node)
	{
		if (node->data == smallest)
			break ;
		count++;
		node = node->next;
	}
	return (count);
}

static void	rotate_middle(t_list **head, int index, int first_time)
{
	if (index == 2)
	{
		if (first_time)
		{
			rotate(head, 'a');
			rotate(head, 'a');
		}
		else
		{
			rev_rotate(head, 'a');
			rev_rotate(head, 'a');
		}
	}
	if (index == 3)
	{
		if (first_time)
		{
			rev_rotate(head, 'a');
			rev_rotate(head, 'a');
		}
		else
			rev_rotate(head, 'a');
	}
}

static void	rotate_a_medium(t_list **head, int index, int first_time)
{
	if (index == 0)
		return ;
	if (index == 1)
		rotate(head, 'a');
	if (index == 2 || index == 3)
		rotate_middle(head, index, first_time);
	if (index == 4)
		rev_rotate(head, 'a');
}

void	sort_medium(t_list **head)
{
	t_list	*b;
	int		index;
	int		smallest;

	b = NULL;
	smallest = find_smallest(*head, 0)->data;
	index = count_index(*head, smallest);
	rotate_a_medium(head, index, 1);
	push(&b, head, 'b');
	smallest = find_smallest(*head, 0)->data;
	index = count_index(*head, smallest);
	rotate_a_medium(head, index, 0);
	push(&b, head, 'b');
	sort_short(head, 1);
	push(head, &b, 'a');
	push(head, &b, 'a');
	clearall_throw(head, &b, NULL, 0);
}
