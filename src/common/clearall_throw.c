/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearall_throw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:14:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/24 17:22:50 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
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

void	clear_parts(t_part **parts)
{
	if (parts)
		prtclear(parts);
}

void	*clearall_throw(t_list **stack_a, t_list **stack_b,
			char **str, int throw)
{
	if (str)
		clear_input(str);
	if (stack_a)
		lstclear(stack_a);
	if (stack_b)
		lstclear(stack_b);
	if (throw)
		print_error();
	return (NULL);
}
