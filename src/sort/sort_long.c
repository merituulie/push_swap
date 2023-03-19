/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:49:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/13 14:20:58 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	reinit_indexes(t_list *first_hold, t_list *second_hold)
{
	if (first_hold)
	{
		//ft_printf("found %i at the top, no rotation, just push\n", first_hold->data);
		first_hold->index = -1;
	}
	if (second_hold)
	{
		//ft_printf("found %i at the top, no rotation, just push\n", second_hold->data);
		second_hold->index = -1;
	}
}

static int	just_break(int max_count, t_list **a_stack, t_list **b_stack)
{
	t_rotate *rotation;
	if (max_count == 0)
		return (1);
	if (max_count == 1)
	{
		rotation = rotate_b(b_stack, (*a_stack)->data);
		if (rotation)
		{
			if (rotation->rev_rotate)
				rotate_multiple(b_stack, rotation->stack, rotation->rotations, rev_rotate);
			else
				rotate_multiple(b_stack, rotation->stack, rotation->rotations, rotate);
			free(rotation);
		}
		push(b_stack, a_stack, 'b');
		return (1);
	}
	return (0);
}

static void	rotate_stacks(t_list **a_stack, t_list **b_stack, t_list *first_hold, t_list *second_hold)
{
	int			max_count;
	t_rotate	*a_rotate;
	t_rotate	*b_rotate;

	a_rotate = NULL;
	b_rotate = NULL;
	max_count = get_listsize(a_stack);
	a_rotate = rotate_a(first_hold, second_hold, max_count);
	b_rotate = rotate_b(b_stack, a_rotate->to_be_pushed);
	//ft_printf("A needs to be rotated %i times in reverse: %i for value %i \n", a_rotate->rotations, a_rotate->rev_rotate, a_rotate->to_be_pushed);
	// if (b_rotate)
	// 	ft_printf("B needs to be rotated %i times in reverse: %i\n", b_rotate->rotations, b_rotate->rev_rotate);
	rotate_both(a_stack, b_stack, a_rotate, b_rotate);
	ft_printf("out of rotation\n");
	free(a_rotate);
	free(b_rotate);
}

static void	search_push_rotate(t_list **b_stack, t_list **a_stack,
				int smallest, int biggest)
{
	t_list	*first_hold;
	t_list	*second_hold;
	int		max_count;
	t_list	*b_temp;

	while (1)
	{
		b_temp = *b_stack;
		ft_printf("B stack:\n");
		while (b_temp)
		{
			ft_printf("[%i]\n", b_temp->data);
			b_temp = b_temp->next;
		}
		first_hold = NULL;
		second_hold = NULL;
		max_count = get_listsize(a_stack);
		if (just_break(max_count, a_stack, b_stack))
			break ;
		first_hold = search_from_top(a_stack, smallest, biggest, max_count);
		// if (first_hold)
		// 	ft_printf("first hold %i\n", first_hold->data);
		second_hold = search_from_bottom(a_stack, smallest, biggest, max_count);
		// if (second_hold)
		// 	ft_printf("second hold %i\n", second_hold->data);
		if (!first_hold && !second_hold)
			break ;
		rotate_stacks(a_stack, b_stack, first_hold, second_hold);
		reinit_indexes(first_hold, second_hold);
		ft_printf("pushing %i to b\n", (*a_stack)->data);
		push(b_stack, a_stack, 'b');
	}
}

void	sort_long(t_list **head, int part_count)
{
	t_part	*parts;
	t_part	*parts_temp;
	t_list	*b;
	t_list	*temp;
	t_list	*b_temp;

	parts = NULL;
	b = NULL;
	parts = init_parts(head, part_count);
	parts_temp = parts;
	temp = *head;
	ft_printf("A stack:\n");
	while (temp)
	{
		ft_printf("[%i]\n", temp->data);
		temp = temp->next;
	}
	while (parts)
	{
		ft_printf("parts %i - %i\n", parts->smallest, parts->biggest);
		search_push_rotate(&b, head, parts->smallest, parts->biggest);
		temp = *head;
		ft_printf("A stack:\n");
		while (temp)
		{
			ft_printf("[%i]\n", temp->data);
			temp = temp->next;
		}
		b_temp = b;
		ft_printf("B stack:\n");
		while (b_temp)
		{
			ft_printf("[%i]\n", b_temp->data);
			b_temp = b_temp->next;
		}
		parts = parts->next;
	}
	rotate_until_sorted(&b);
	while (b)
		push(head, &b, 'a');
	clear_parts(&parts);
	exit_success(head, &b);
}
