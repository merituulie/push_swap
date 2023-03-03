/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:04:52 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/24 17:23:15 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exit_success(t_list **a, t_list **b)
{
	clearall_throw(a, b, NULL, 0);
	exit(EXIT_SUCCESS);
}

void	exit_failure(t_list **a, t_list **b, char **str)
{
	clearall_throw(a, b, str, 1);
	exit(EXIT_FAILURE);
}
