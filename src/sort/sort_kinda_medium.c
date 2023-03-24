/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_kinda_medium.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:51:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 14:29:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_smallest_index(t_list *head)
{
	t_list	*temp;
	t_list	*smallest;
	int		count;

	temp = head;
	smallest = head;
	while (temp)
	{
		if (temp->data <= smallest->data)
			smallest = temp;
		temp = temp->next;
	}
	temp = head;
	count = 0;
	while (temp)
	{
		if (temp->data == smallest->data)
			break ;
		count++;
		temp = temp->next;
	}
	temp = NULL;
	smallest = NULL;
	return (count);
}

static void	rotate_middle(t_list **head, int index)
{
	if (index == 2)
	{
		rotate(head, 'a');
		rotate(head, 'a');
	}
	if (index == 3)
	{
		rev_rotate(head, 'a');
		rev_rotate(head, 'a');
	}
}

static void	rotate_a_middle(t_list **head, int index)
{
	if (index == 0)
		return ;
	if (index == 1)
		rotate(head, 'a');
	if (index == 2 || index == 3)
		rotate_middle(head, index);
	if (index == 4)
		rev_rotate(head, 'a');
}

void	sort_kinda_medium(t_list **head)
{
	t_list	*b;
	int		index;

	b = NULL;
	index = find_smallest_index(*head);
	rotate_a_middle(head, index);
	push(&b, head, 'b');
	sort_short(head, 1);
	push(head, &b, 'a');
	clearall_throw(head, &b, NULL, 0);
}
