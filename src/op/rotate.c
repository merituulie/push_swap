/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:38:23 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/03 15:25:13 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/headers/ft_printf.h"

void	rotate_multiple(t_list **head, char stack, int count, void (*f)(t_list **head, char stack))
{
	while (count > 0)
	{
		(*f)(head, stack);
		count--;
	}
}

void	rotate(t_list **head, char stack)
{
	t_list	*org_first;
	t_list	*new_first;
	t_list	*temp;

	if (!head || !*head)
		return ;
	org_first = *head;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = org_first;
	org_first->prev = temp;
	new_first = org_first->next;
	new_first->prev = NULL;
	org_first->next = NULL;
	if (stack != '\0')
		print_op('r', stack);
	*head = new_first;
	org_first = NULL;
	new_first = NULL;
	temp = NULL;
}
