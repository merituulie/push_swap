/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:29:32 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/17 12:54:53 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_list **head, char stack)
{
	t_list	*temp;
	t_list	*new_first;
	t_list	*third;

	temp = *head;
	new_first = temp->next;
	third = new_first->next;
	temp->next = third;
	new_first->next = temp;
	if (stack != '\0')
		print_op('s', stack, 1);
	*head = new_first;
	temp = NULL;
	new_first = NULL;
	third = NULL;
}
