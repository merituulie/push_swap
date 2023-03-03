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
#include "../../ft_printf/headers/ft_printf.h"

int	find_smallest(t_list *head)
{
	t_list	*temp;
	t_list	*smallest;

	temp = head;
	smallest = head;
	while (temp)
	{
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

	next_smallest = find_biggest(head);
	smallest = find_smallest(head);
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
