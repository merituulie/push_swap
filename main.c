/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:43:22 by meskelin          #+#    #+#             */
/*   Updated: 2023/01/30 16:22:18 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/headers/ft_printf.h"
#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int i;
	t_list *stack;
	t_list *swap_stack;
	t_list *push_a_stack;
	t_list *push_b_stack;
	t_list *rotate_a_stack;
	t_list *rev_rotate_b_stack;

	if (argc <= 1)
		return (0);
	ft_printf("Let's start!\n");
	i = 1;
	while (argv[i])
	{
		ft_printf("input to argument [%i] > %s\n", i, argv[i]);
		stack = stack_sort(argv[i]);
		i++;
	}
	swap_stack = stack;
	ft_printf("After creation:\n");
	while (stack)
	{
		ft_printf("[%i]\n", stack->data);
		stack = stack->next;
	}
	swap_stack = swap(swap_stack, 'a');
	push_a_stack = swap_stack;
	ft_printf("After swap for A:\n");
	while (swap_stack)
	{
		ft_printf("[%i]\n", swap_stack->data);
		swap_stack = swap_stack->next;
	}
	ft_printf("Creating another stack...\n");
	t_list *b_stack = create_b_stack("1   2 3 4 5   ");
	push_b_stack = b_stack;
	ft_printf("Original b stack:\n");
	while (b_stack)
	{
		ft_printf("[%i]\n", b_stack->data);
		b_stack = b_stack->next;
	}
	swap_stack = push_a_stack;
	b_stack = push_b_stack;
	push(&swap_stack, &b_stack, 'a');
	push_b_stack = b_stack;
	rev_rotate_b_stack = push_b_stack;
	push_a_stack = swap_stack;
	ft_printf("B stack after push:\n");
	while (push_b_stack)
	{
		ft_printf("[%i]\n", push_b_stack->data);
		push_b_stack = push_b_stack->next;
	}
	ft_printf("A stack after push:\n");
	while (swap_stack)
	{
		ft_printf("[%i]\n", swap_stack->data);
		swap_stack = swap_stack->next;
	}
	ft_printf("A after 3 rotations:\n");
	rotate(&push_a_stack, 'a');
	rotate(&push_a_stack, 'a');
	rotate(&push_a_stack, 'a');
	rotate_a_stack = push_a_stack;
	while (push_a_stack)
	{
		ft_printf("[%i]\n", push_a_stack->data);
		push_a_stack = push_a_stack->next;
	}
	ft_printf("B after 3 reverse rotations:\n");
	rev_rotate(&rev_rotate_b_stack, 'b');
	rev_rotate(&rev_rotate_b_stack, 'b');
	rev_rotate(&rev_rotate_b_stack, 'b');
	while (rev_rotate_b_stack)
	{
		ft_printf("[%i]\n", rev_rotate_b_stack->data);
		rev_rotate_b_stack = rev_rotate_b_stack->next;
	}
	return (0);
}
