/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:15 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/27 15:45:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/headers/ft_printf.h"

void	rev_rotate(t_list **head, char stack)
{
	t_list	*org_first;
	t_list	*second_to_last;
	t_list	*new_first;

	if (!head || !*head)
		return ;
	org_first = *head;
	second_to_last = *head;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	new_first = second_to_last->next;
	new_first->next = org_first;
	org_first->prev = new_first;
	new_first->prev = NULL;
	second_to_last->next = NULL;
	*head = new_first;
	if (stack != '\0')
	{
		ft_printf("r");
		print_op('r', stack);
	}
	org_first = NULL;
	second_to_last = NULL;
	new_first = NULL;
}
