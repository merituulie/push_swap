/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:29:32 by meskelin          #+#    #+#             */
/*   Updated: 2023/01/30 13:55:58 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*swap(t_list *org_first, char stack)
{
	t_list	*new_first;
	t_list	*third;

	new_first = org_first->next;
	third = new_first->next;
	org_first->next = third;
	new_first->next = org_first;
	print_op('s', stack);
	return (new_first);
}
