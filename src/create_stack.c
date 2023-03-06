/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:10:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/24 17:21:12 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include "../../ft_printf/includes/ft_printf.h"

static int	validate_data(char	*input)
{
	if (input[0] == '-' && input[1] && input[1] == '1'
		&& input[2] == '\0')
		return (1);
	else
		return (0);
}

t_list	*create_stack(char *input)
{
	static t_list	*stack;
	char			**first;
	char			**input_array;
	int				data;

	input_array = ft_split(input, ' ');
	first = input_array;
	if (!input_array || !*input_array)
		return (clearall_throw(&stack, NULL, first, 1));
	while (*input_array)
	{
		data = ft_atoi(*input_array);
		if (data == -1 && !validate_data(*input_array))
			return (clearall_throw(&stack, NULL, first, 1));
		lstadd_to_stack(&stack, data);
		input_array++;
	}
	clearall_throw(NULL, NULL, first, 0);
	return (stack);
}
