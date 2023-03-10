/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtadd_to_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:51:56 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/10 11:51:42 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

void	prtadd_to_parts(t_part **stack, int smallest, int biggest, int first_time)
{
	t_part *new;

	new = prtnew(smallest, biggest);
	if (first_time)
		*stack = new;
	else
		prtadd(stack, new);
}
