/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_first_or_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:19:29 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/13 13:40:30 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	not_first_or_last(t_list **stack, int to_be_pushed)
{
	t_list *temp;
	t_list *second;

	temp = *stack;
	second = *stack;
	while (temp->next)
		temp = temp->next;
	if ((to_be_pushed > second->data && to_be_pushed > temp->data)
		|| (to_be_pushed < second->data && to_be_pushed < temp->data))
		return (0);
	return (1);
}
