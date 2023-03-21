/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotate_middle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:58:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/21 17:58:22 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

t_rotate	*rotate_or_revrotate(t_list *smaller, t_list *bigger, int size, int to_be_pushed)
{
	int halfway;

	halfway = size / 2;
	ft_printf("Got %i as the smaller node ", smaller->data);
	ft_printf("in index %i and bigger node as %i in index %i ", smaller->index, bigger->data, bigger->index);
	ft_printf("with value %i to be pushed\n", to_be_pushed);
	ft_printf("%i is halfway\n", halfway);
	if (size == 2)
		return (rotate_size2(smaller, to_be_pushed));
	if (size == 3)
		return (rotate_size3(smaller, to_be_pushed));
	if (smaller->index == (size - 1))
		return (rttnew('b', 1, 1, smaller->data));
	if (smaller->index < halfway)
		return (rttnew('b', smaller->index, 0, smaller->data));
	else
		return (rttnew('b', (size - smaller->index), 1, smaller->data));
}
