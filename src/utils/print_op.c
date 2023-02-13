/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:49:26 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/13 17:53:07 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

void	print_op(char op, char stack)
{
	char	output[3];

	output[0] = op;
	output[1] = stack;
	output[2] = '\0';
	ft_putendl_fd(output, 1);
}
