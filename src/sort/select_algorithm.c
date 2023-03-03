/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:43:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/27 12:08:20 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	select_algorithm(int max_count)
{
	if (max_count <= NO_ALG)
		return (NO_ALG);
	else if (max_count <= VERY_SHORT_ALG)
		return (VERY_SHORT_ALG);
	else if (max_count <= SHORT_ALG)
		return (SHORT_ALG);
	else if (max_count <= KINDA_MEDIUM_ALG)
		return (SHORT_ALG);
	else if (max_count <= MEDIUM_ALG)
		return (MEDIUM_ALG);
	else if (max_count > MEDIUM_ALG && max_count <= LONG_ALG)
		return (KINDA_LONG_ALG);
	else if (max_count > LONG_ALG)
		return (KINDA_LONG_ALG);
	else
		return (LONG_ALG);
}
