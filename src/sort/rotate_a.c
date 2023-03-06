/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:18:49 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/06 17:18:49 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotate	*rotate_a(t_list **a_stack, t_list *first_hold, t_list *second_hold, int max_count)
{
	int			rotate_second;
	int			halfway;
	t_rotate	*rotation;

	rotate_second = 1;
	halfway = max_count / 2;
	rotate_second = halfway;
	if (second_hold)
		rotate_second = max_count - second_hold->index;
	if ((first_hold && first_hold->index == 0)
		|| (second_hold && second_hold->index == 0))
	{
		return (rttcreate('a', 0, 0));
	}
	if (first_hold && first_hold->index < halfway && first_hold->index < rotate_second)
	{
		//ft_printf("rotating forward %i times to get the value %i on top\n", first_hold->index, first_hold->data);
		return (rttcreate('a', first_hold->index, 0));
	}
	else if (second_hold && second_hold->index >= halfway)
	{
		//ft_printf("rotating backwards %i times to get the value %i on top\n", rotate_second, second_hold->data);
		return (rttcreate('a', rotate_second, 1));
	}
	return (NULL);
}
