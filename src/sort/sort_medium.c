/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:43:43 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/13 17:32:51 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_smallest(t_list *head)
{
	t_list *temp;
	t_list *smallest;
	int count;

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
	return (count);
}

static void	rotate_a(t_list **head, int index, int first_time)
{
	if (index == 0)
		return ;
	if (index == 1)
		rotate(head, 'a');
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
	if (index == 4)
		rev_rotate(head, 'a');
}

void	sort_medium(t_list **head)
{
	t_list	*b;
	int		index;

	b = NULL;
	index = find_smallest(*head);
	rotate_a(head, index, 1);
	push(&b, head, 'b');
	index = find_smallest(*head);
	rotate_a(head, index, 0);
	push(&b, head, 'b');
	sort_short(head);
	push(head, &b, 'a');
	push(head, &b, 'a');
	exit_success(head, &b);
}
