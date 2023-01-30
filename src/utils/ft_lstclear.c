/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:53:34 by meskelin          #+#    #+#             */
/*   Updated: 2023/01/27 16:29:18 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_clr_rec(t_list *lst)
{
	if (!lst)
		return ;
	ft_clr_rec(lst->next);
	lst->next = NULL;
	lst->data = 0;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	ft_clr_rec(*lst);
	*lst = NULL;
}
