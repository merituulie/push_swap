/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:48:38 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/27 16:51:36 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"
#include "../../ft_printf/headers/ft_printf.h"

t_part	*prtnew(int smallest, int biggest)
{
	t_part	*new;

	new = (t_part *)ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->smallest = smallest;
	new->biggest = biggest;
	new->next = NULL;
	return (new);
}
