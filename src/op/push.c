/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:12:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/27 13:59:57 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	handle_from(t_list **from_stack)
{
	if ((*from_stack)->next)
	{
		*from_stack = (*from_stack)->next;
		(*from_stack)->prev = NULL;
	}
	else
		*from_stack = NULL;
}

void	push(t_list **to_stack, t_list **from_stack, char stack)
{
	t_list	*org_first_from;
	t_list	*org_first_to;

	if (!from_stack)
		return ;
	org_first_from = *from_stack;
	org_first_to = *to_stack;
	handle_from(from_stack);
	*to_stack = org_first_from;
	if (!org_first_to)
	{
		org_first_from->next = NULL;
		org_first_from->prev = NULL;
	}
	else
	{
		org_first_from->next = org_first_to;
		org_first_from->prev = NULL;
		org_first_to->prev = org_first_from;
	}
	if (stack != '\0')
		print_op('p', stack, 1);
}
