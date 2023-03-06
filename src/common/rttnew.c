/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rttnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:39:23 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/06 18:39:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_rotate	*rttnew(char stack, int rotations, int rev_rotate)
{
	t_rotate	*new;

	new = (t_rotate)ft_calloc(1, sizeof(rotation));
	if (!new)
		return (NULL);
	new->stack = stack;
	new->rotations = rotations;
	new->rev_rotate = rev_rotate;
	return (new);
}
