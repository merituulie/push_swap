/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rttnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:39:23 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/10 14:37:45 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

t_rotate	*rttnew(char stack, int rotations, int rev_rotate, int to_be_pushed)
{
	t_rotate	*new;

	new = (t_rotate *)ft_calloc(1, sizeof(new));
	if (!new)
		return (NULL);
	new->stack = stack;
	new->rotations = rotations;
	new->rev_rotate = rev_rotate;
	new->to_be_pushed = to_be_pushed;
	return (new);
}
