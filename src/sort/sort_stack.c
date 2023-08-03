/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:31:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/27 14:01:42 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stack(t_list **stack, int sort_algorithm, int part_count)
{
	if (sort_algorithm == NO_ALG)
		return ;
	else if (sort_algorithm == VERY_SHORT_ALG)
		sort_very_short(stack);
	else if (sort_algorithm == SHORT_ALG)
		sort_short(stack, 0);
	else if (sort_algorithm == KINDA_MEDIUM_ALG)
		sort_kinda_medium(stack);
	else if (sort_algorithm == MEDIUM_ALG)
		sort_medium(stack);
	else if (sort_algorithm >= LONG_ALG)
		sort_long(stack, part_count);
}
