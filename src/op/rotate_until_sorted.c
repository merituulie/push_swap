/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_until_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:33:03 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 16:13:19 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_until_sorted(t_list **stack, int size)
{
	t_list	*smallest;

	smallest = find_smallest(*stack, 1);
	if (smallest->index == 0)
		return ;
	rotate_multiple(stack, 'b', (size - smallest->index - 1), rev_rotate);
}
