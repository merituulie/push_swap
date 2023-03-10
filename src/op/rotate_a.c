/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:49 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/10 16:32:48 by meskelin         ###   ########.fr       */
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
	if (first_hold && first_hold->index <= halfway && first_hold->index <= rotate_second)
	{
		// ft_printf("rotating forward %i times to get the value %i on top\n", first_hold->index, first_hold->data);
		return (rttnew('a', first_hold->index, 0, first_hold->data));
	}
	else if (second_hold)
	{
		// ft_printf("rotating backwards %i times to get the value %i in index %i on top\n", rotate_second, second_hold->data, second_hold->index);
		return (rttnew('a', rotate_second, 1, second_hold->data));
	}
	return (NULL);
}
