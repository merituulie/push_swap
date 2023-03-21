/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate_bs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:38:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/20 18:36:10 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotate	*rotate_for_smallest(t_list *small, int size)
{
	if (small->index == (size - 1))
		return (rttnew('b', 0, 0, small->data));
	else
		return (rttnew('b', 1, 0, small->data));
}

t_rotate	*rotate_for_smallest_middle(t_list *small, int size)
{
	if (small->index < size / 2)
		return (rttnew('b', small->index + 1, 0, small->data));
	else
		return (rttnew('b', (size - small->index - 1), 1, small->data));
}

t_rotate	*rotate_or_revrotate_biggest(t_list *big, int size)
{
	if (big->index == (size - 1))
		return (rttnew('b', 1, 1, big->data));
	else
		return (rttnew('b', 1, 0, big->data));
}

t_rotate	*rotate_for_biggest_middle(t_list *big, int size)
{
	if (big->index < size / 2)
		return (rttnew('b', big->index, 0, big->data));
	else
		return (rttnew('b', (size - big->index), 1, big->data));
}
