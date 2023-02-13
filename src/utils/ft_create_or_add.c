/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_or_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:49:04 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/10 12:50:44 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/headers/ft_printf.h"

void	add_to_stack(t_list **stack, int data)
{
	if (!*stack)
		*stack = ft_lstnew(data);
	else
		ft_lstadd(stack, ft_lstnew(data));
}
