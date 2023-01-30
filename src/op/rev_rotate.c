/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:15 by meskelin          #+#    #+#             */
/*   Updated: 2023/01/30 16:30:20 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/headers/ft_printf.h"

void	rev_rotate(t_list	**head, char stack)
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
	second_to_last->next = NULL;
	*head = new_first;
	ft_printf("r");
	print_op('r', stack);
}
