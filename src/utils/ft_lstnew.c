/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:09:31 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/06 14:13:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
