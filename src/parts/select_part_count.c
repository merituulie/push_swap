/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_part_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:11:23 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/27 14:00:59 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	select_part_count(int select_algorithm, int size)
{
	int	part_count;

	part_count = 0;
	if (select_algorithm < LONG_ALG)
		return (0);
	else if (select_algorithm >= LONG_ALG)
	{
		if (size % 2 != 0)
			part_count = 1;
		if (size > 100)
			return (part_count + 14);
		else if (size % 5 == 0)
			return (5);
		else if (size % 4 == 0)
			return (part_count + 4);
		else if (size % 3 == 0)
			return (3);
		else if (size % 2 == 0)
			return (part_count + 2);
	}
	return (1);
}
