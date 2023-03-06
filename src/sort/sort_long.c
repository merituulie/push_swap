/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:49:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/03 15:25:17 by meskelin         ###   ########.fr       */
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
	if (max_count == 0)
		return (1);
	if (max_count == 1)
	{
		rotate_b(b_stack, (*a_stack)->data);
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

	max_count = lstsize(a_stack);
	a_rotate = rotate_a(a_stack, first_hold, second_hold);
	b_rotate = rotate_b(b_stack, (*a_stack)->data);
	rotate_both(a_stack, b_stack, a_rotate, b_rotate);
	free(a_rotate);
	free(b_rotate);
}

static void	search_push_rotate(t_list **b_stack, t_list **a_stack,
				int smallest, int biggest)
{
	t_list	*first_hold;
	t_list	*second_hold;
	int		max_count;

	first_hold = NULL;
	second_hold = NULL;
	while (1)
	{
		max_count = get_listsize(a_stack);
		if (just_break(max_count, a_stack, b_stack))
			break ;
		reinit_indexes(first_hold, second_hold);
		first_hold = search_from_top(a_stack, smallest, biggest, max_count);
		second_hold = search_from_bottom(a_stack, smallest, biggest, max_count);
		if (!first_hold && !second_hold)
			break ;
		rotate_stacks(a_stack, b_stack, first_hold, second_hold);
		push(b_stack, a_stack, 'b');
	}
}

void	sort_long(t_list **head, int part_count)
{
	t_part	*parts;
	t_part	*parts_temp;
	t_list	*b;

	parts = NULL;
	b = NULL;
	parts = init_parts(head, part_count);
	parts_temp = parts;
	ft_printf("parting\n");
	while (parts_temp)
	{
		ft_printf("parts %i - %i\n", parts_temp->smallest, parts_temp->biggest);
		parts_temp = parts_temp->next;
	}
	while (parts)
	{
		search_push_rotate(&b, head, parts->smallest, parts->biggest);
		parts = parts->next;
	}
	rotate_until_revsorted(&b);
	while (b)
		push(a_stack, &b, 'a');
	clear_parts(parts);
	exit_success(a_stack, b_stack, NULL);
}
