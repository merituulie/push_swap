/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_until_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:33:03 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/10 12:16:50 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_until_revsorted(t_list **stack)
{
	t_list *smallest;
	int		r_count;
	int		size;

	size = lstsize(*stack);
	smallest = find_smallest(*stack, 1);
	if (smallest->index == (size - 1))
		return ;
	r_count = size - smallest->index - 1;
	rotate_multiple(stack, 'b', r_count, rev_rotate);
}
