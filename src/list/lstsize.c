/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:23:05 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/03 15:29:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

int	lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst)
	{
		ft_printf("[%i]\n", lst->data);
		count++;
		lst = lst->next;
	}
	return (count);
}

int	get_listsize(t_list **head)
{
	int size;

	size = lstsize(*head);
	if (size == 0 || size == 1 || size % 2 == 0)
		return (size);
	else
		return (size + 1);
}
