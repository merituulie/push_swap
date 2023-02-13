/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:23:05 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/06 14:49:16 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstsize(t_list *lst, int max)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst && count <= max)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
