/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:04:52 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/27 13:48:41 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

void	exit_success(void)
{
	exit(EXIT_SUCCESS);
}

void	exit_failure(t_list **a, t_list **b, char **str)
{
	clearall_throw(a, b, str, 1);
	exit(EXIT_FAILURE);
}
