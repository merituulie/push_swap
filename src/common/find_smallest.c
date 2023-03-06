/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:12:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/03 15:18:48 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

int	find_smallest(t_list *head, int add_index)
{
	t_list	*temp;
	t_list	*smallest;
	int		index;

	temp = head;
	smallest = head;
	index = 0;
	while (temp)
	{
		if (add_index)
			temp->index = index++;
		if (temp->data <= smallest->data)
		{
			smallest = temp;
		}
		temp = temp->next;
	}
	temp = NULL;
	return (smallest->data);
}

int find_next_smallest(t_list *head, int smaller)
{
	int		smallest;
	t_list	*next_smallest;

	next_smallest = find_biggest(head, 0);
	smallest = find_smallest(head, 0);
	while (head)
	{
		if (head->data < next_smallest->data
			&& head->data > smaller
			&& head->data != smallest)
			next_smallest = head;
		head = head->next;
	}
	return (next_smallest->data);
}
