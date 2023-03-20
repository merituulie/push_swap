/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:59:08 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/20 10:56:14 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*find_biggest(t_list *head, int add_index)
{
	t_list	*temp;
	t_list	*biggest;
	int		index;

	temp = head;
	biggest = head;
	index = 0;
	while (temp)
	{
		if (add_index)
			temp->index = index++;
		if (temp->data >= biggest->data)
		{
			biggest = temp;
		}
		temp = temp->next;
	}
	temp = NULL;
	return (biggest);
}
