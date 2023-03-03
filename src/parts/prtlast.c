/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:47:21 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/27 15:13:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_part	*prtlast(t_part **lst)
{
	t_part	*ptr;

	ptr = *lst;
	if (!ptr)
		return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
