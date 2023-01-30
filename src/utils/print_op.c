/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:49:26 by meskelin          #+#    #+#             */
/*   Updated: 2023/01/30 16:27:33 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/headers/ft_printf.h"

void	print_op(char op, char stack)
{
	char	output[4];

	output[0] = op;
	output[1] = stack;
	output[2] = '\n';
	output[3] = '\0';
	ft_printf(output);
}
