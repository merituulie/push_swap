/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:12:25 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/10 13:46:27 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_list **to_stack, t_list **from_stack, char stack)
{
	t_list	*org_first_from;

	if (!from_stack)
		return ;
	org_first_from = *from_stack;
	*from_stack = org_first_from->next;
	if (!to_stack || !*to_stack)
		add_to_stack(to_stack, org_first_from->data);
	else
	{
		org_first_from->next = *to_stack;
		*to_stack = org_first_from;
	}
	if (stack != '\0')
		print_op('p', stack);
}
