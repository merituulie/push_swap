/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_previous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:02:07 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/27 13:58:53 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotate	*find_previous(int to_be_pushed, t_list *previous,
				t_list *next, int size)
{
	if (to_be_pushed < previous->data)
		return (rotate_or_revrotate(next, size, to_be_pushed));
	return (rotate_or_revrotate(previous, size, to_be_pushed));
}
