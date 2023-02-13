/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:43:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/13 18:29:35 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/headers/ft_printf.h"
#include "./includes/push_swap.h"

static int	is_sorted(t_list *stack)
{
	if (!stack->next)
		return (1);
	while (stack)
	{
		if (stack->next && stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	has_duplicates(t_list **stack)
{
	t_list *temp_a;
	t_list *temp_b;

	temp_a = *stack;
	temp_b = temp_a->next;
	while (temp_a)
	{
		while (temp_b)
		{
			if (temp_a->data == temp_b->data)
				return (1);
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int i;
	int algorithm;
	t_list *stack;

	if (argc <= 1)
		return (0);
	i = 1;
	algorithm = 0;
	while (argv[i])
	{
		stack = create_stack(argv[i]);
		if (!stack)
			exit(EXIT_FAILURE);
		i++;
	}
	if (is_sorted(stack))
		exit_success(&stack, NULL);
	if (has_duplicates(&stack))
		exit_failure(&stack, NULL, NULL);
	algorithm = select_algorithm(&stack);
	sort_stack(&stack, algorithm);
	exit_success(&stack, NULL);
}
