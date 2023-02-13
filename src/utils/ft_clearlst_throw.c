/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearlst_throw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:14:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/13 14:01:50 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/headers/ft_printf.h"
#include "../../libft/libft.h"

static void	clear_input(char **str_array)
{
	char	**temp;

	temp = str_array;
	while (temp && *temp != '\0')
	{
		free(*temp);
		temp++;
	}
	free(str_array);
}

void	*clearlst_throw(t_list **stack_a, t_list **stack_b, char **str, int throw)
{
	if (str)
		clear_input(str);
	if (stack_a && *stack_a)
		ft_lstclear(stack_a);
	if (stack_b && *stack_b)
		ft_lstclear(stack_b);
	if (throw)
		print_error();
	return (NULL);
}
