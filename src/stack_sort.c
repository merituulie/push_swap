/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:10:00 by meskelin          #+#    #+#             */
/*   Updated: 2023/01/30 16:25:23 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../ft_printf/headers/ft_printf.h"
#include "../libft/libft.h"

t_list	*create_b_stack(char *input)
{
	static t_list	*stack;
	char			**input_array;
	int				data;

	input_array = NULL;
	data = 0;
	ft_printf("split input: %s\n", input);
	input_array = ft_split(input, ' ');
	if (!input_array || !*input_array)
		return (NULL);
	while (*input_array)
	{
		data = ft_atoi(*input_array);
		if (!stack)
		{
			ft_printf("Create first element wiht input %i\n", data);
			stack = ft_lstnew(data);
		}
		else
		{
			ft_printf("Add new element to stack with input %i\n", data);
			ft_lstadd(&stack, ft_lstnew(data));
		}
		input_array++;
	}
	return (stack);
}

t_list	*stack_sort(char *input)
{
	static t_list	*stack;
	char			**input_array;
	int				data;

	data = 0;
	input_array = ft_split(input, ' ');
	if (!input_array || !*input_array)
		return (NULL);
	while (*input_array)
	{
		data = ft_atoi(*input_array);
		if (!stack)
			stack = ft_lstnew(data);
		else
			ft_lstadd(&stack, ft_lstnew(data));
		input_array++;
	}
	return (stack);
}
