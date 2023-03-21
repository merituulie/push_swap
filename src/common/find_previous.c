/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_previous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:02:07 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/21 18:02:07 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

t_rotate	*find_previous(int to_be_pushed, t_list *previous, t_list *next, int size)
{
	ft_printf("previous > %i, next > %i\n", previous->data, next->data);
	if (to_be_pushed < previous->data)
		return (rotate_or_revrotate(next, previous, size, to_be_pushed));
	return (rotate_or_revrotate(previous, next, size, to_be_pushed));
}
