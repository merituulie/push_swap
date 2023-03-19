/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:17:16 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/24 17:24:05 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_clr_rec(t_part *prt)
{
	if (!prt)
		return ;
	ft_clr_rec(prt->next);
	prt->next = NULL;
	prt->smallest = 0;
	prt->biggest = 0;
	free(prt);
}

void	prtclear(t_part **prt)
{
	if (!prt)
		return ;
	ft_clr_rec(*prt);
	*prt = NULL;
}
