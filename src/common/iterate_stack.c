/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:05:05 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 16:06:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	iterate_indexes(t_list **previous, t_list **next,
			int n_index, int p_index)
{
	if (n_index != 0)
		p_index = n_index - 1;
	(*next)->index = n_index;
	(*previous)->index = p_index;
}

int	iterate_stack(t_list **previous, t_list **next,
		t_list **stack, int n_index)
{
	if (n_index == 0)
		*previous = *stack;
	else
		*previous = *next;
	*next = (*next)->next;
	n_index++;
	return (n_index);
}
