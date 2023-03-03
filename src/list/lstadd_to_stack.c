/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:49:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/27 14:51:50 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	lstadd_to_stack(t_list **stack, int data)
{
	if (!*stack)
		*stack = lstnew(data);
	else
		lstadd(stack, lstnew(data));
}
