/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:58:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/27 13:59:04 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotate	*rotate_or_revrotate(t_list *smaller, int size, int to_be_pushed)
{
	int	halfway;

	halfway = size / 2;
	if (size == 2)
		return (rotate_size2(smaller, to_be_pushed));
	if (size == 3)
		return (rotate_size3(smaller, to_be_pushed));
	if (smaller->index == (size - 1))
		return (rttnew('b', 1, 1, smaller->data));
	if (smaller->index < halfway)
		return (rttnew('b', smaller->index, 0, smaller->data));
	else
		return (rttnew('b', (size - smaller->index), 1, smaller->data));
}
