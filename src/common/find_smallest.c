/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:12:13 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 16:05:59 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

t_list	*find_smallest(t_list *head, int add_index)
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
	return (smallest);
}

int	find_next_smallest(t_list *head, int smaller)
{
	t_list	*smallest;
	t_list	*next_smallest;
	t_list	*temp;

	next_smallest = find_biggest(head, 0);
	smallest = find_smallest(head, 0);
	temp = head;
	while (temp)
	{
		if (temp->data < next_smallest->data
			&& temp->data > smaller
			&& temp->data != smallest->data)
			next_smallest = temp;
		temp = temp->next;
	}
	return (next_smallest->data);
}
