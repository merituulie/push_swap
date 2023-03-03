/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:10:48 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/24 17:39:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	prtadd(t_part **lst, t_part *new)
{
	if (!*lst)
		*lst = new;
	else
		prtlast(lst)->next = new;
}
