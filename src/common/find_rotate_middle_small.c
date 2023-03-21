/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate_middle_small.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:38:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/20 18:36:10 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotate	*rotate_size2(t_list *node, int to_be_pushed)
{
	if (node->index == 0 && to_be_pushed > node->data)
		return (rttnew('b', 0, 0, node->data));
	if (node->index == 0 && to_be_pushed < node->data)
		return (rttnew('b', 1, 0, node->data));
	else if (node->index == 1 && to_be_pushed > node->data)
		return (rttnew('b', 1, 0, node->data));
	else
		return (rttnew('b', 0, 0, node->data));
}

t_rotate	*rotate_size3(t_list *node, int to_be_pushed)
{
	if (node->index == 0 && to_be_pushed > node->data)
		return (rttnew('b', 0, 0, node->data));
	if (node->index == 0 && to_be_pushed < node->data)
		return (rttnew('b', 1, 0, node->data));
	else if (node->index == 1 && to_be_pushed > node->data)
		return (rttnew('b', 1, 0, node->data));
	else if (node->index == 1 && to_be_pushed < node->data)
		return (rttnew('b', 1, 1, node->data));
	else if (node->index == 2 && to_be_pushed > node->data)
		return (rttnew('b', 2, 0, node->data));
	else
		return (rttnew('b', 0, 0, node->data));
}
