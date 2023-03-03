/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:59:08 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/27 12:01:01 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*find_biggest(t_list *head)
{
	t_list	*temp;
	t_list	*biggest;

	temp = head;
	biggest = head;
	while (temp)
	{
		if (temp->data >= biggest->data)
		{
			biggest = temp;
		}
		temp = temp->next;
	}
	temp = NULL;
	return (biggest);
}
