/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:53:34 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/27 12:31:00 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	ft_clr_rec(t_list *lst)
{
	if (!lst)
		return ;
	ft_clr_rec(lst->next);
	lst->next = NULL;
	lst->prev = NULL;
	lst->data = 0;
	free(lst);
}

void	lstclear(t_list **lst)
{
	if (!lst)
		return ;
	ft_clr_rec(*lst);
	*lst = NULL;
}
