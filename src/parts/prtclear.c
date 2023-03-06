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

static void	ft_clr_rec(t_part *lst)
{
	if (!lst)
		return ;
	ft_clr_rec(lst->next);
	lst->next = NULL;
	lst->smallest = 0;
	lst->biggest = 0;
	free(lst);
}

void	prtclear(t_part **lst)
{
	if (!lst)
		return ;
	ft_clr_rec(*lst);
	*lst = NULL;
}
