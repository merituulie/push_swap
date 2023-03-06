/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_part_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:11:23 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/06 13:11:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	select_part_count(int select_algorithm, int size)
{
	if (select_algorithm < KINDA_LONG_ALG)
	{
		return (0);
	}
	else if (select_algorithm >= KINDA_LONG_ALG)
	{
		if (size > 100 && size % 10 == 0)
			return (10);
		else if (size % 5 == 0)
			return (5);
		else if (size % 4 == 0)
			return (4);
		else if (size % 3 == 0)
			return (3);
		else if (size % 2 == 0)
			return (2);
		else
			return (1);
	}
}
