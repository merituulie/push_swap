/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:49:26 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/03 13:00:47 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	print_op(char op, char stack)
{
	char	output[4];

	output[0] = op;
	output[1] = stack;
	output[2] = '\n';
	output[3] = '\0';
	ft_printf(output);
}
