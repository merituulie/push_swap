/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:49 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 16:16:26 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

t_rotate	*rotate_a(t_list *first_hold, t_list *second_hold, int max_count)
{
	int			rotate_second;
	int			halfway;

	halfway = max_count / 2;
	rotate_second = halfway;
	if (second_hold)
		rotate_second = max_count - second_hold->index;
	if (first_hold && first_hold->index == 0)
		return (rttnew('a', 0, 0, first_hold->data));
	if (second_hold && second_hold->index == 0)
		return (rttnew('a', 0, 0, second_hold->data));
	if (first_hold && first_hold->index <= halfway
		&& first_hold->index <= rotate_second)
		return (rttnew('a', first_hold->index, 0, first_hold->data));
	else if (second_hold)
		return (rttnew('a', rotate_second, 1, second_hold->data));
	return (NULL);
}
