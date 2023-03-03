/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_kinda_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:49:10 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/03 15:25:17 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/headers/ft_printf.h"

static t_list	*search_from_bottom(t_list **a_stack, int smallest,
					int biggest, int max_count)
{
	t_list *current;
	int		index;

	current = *a_stack;
	index = max_count - 1;
	while (current->next)
		current = current->next;
	while (current->prev && index >= (max_count / 2))
	{
		if (current->data >= smallest
			&& current->data <= biggest)
			break ;
		current->index = -1;
		current = current->prev;
		index--;
	}
	if (current->data < smallest
		|| current->data > biggest
		|| current->index != -1)
		return (NULL);
	current->index = index;
	return (current);
}

static t_list	*search_from_top(t_list **a_stack, int smallest, int biggest, int max_count)
{
	t_list	*current;
	int		index;

	current = *a_stack;
	index = 0;
	while (current->next && index < (max_count / 2))
	{
		if (current->data >= smallest
			&& current->data <= biggest)
			break ;
		current->index = -1;
		current = current->next;
		index++;
	}
	if (current->data < smallest
		|| current->data > biggest)
			return (NULL);
	current->index = index;
	return (current);
}

static void	search_push(t_list **b_stack, t_list **a_stack,
				int smallest, int biggest)
{
	t_list	*first_hold;
	t_list	*second_hold;
	int		rotate_second;
	int		max_count;

	first_hold = NULL;
	second_hold = NULL;
	rotate_second = 1;
	while (1)
	{
		max_count = get_listsize(a_stack);
		if (max_count == 0)
			break;
		//ft_printf("a stack size: %i\n", max_count);
		if (max_count == 1)
		{
			//ft_printf("only %i left, no rotation, just push\n", (*a_stack)->data);
			push(b_stack, a_stack, 'b');
			break ;
		}
		else
			rotate_second = max_count / 2;
		first_hold = search_from_top(a_stack, smallest, biggest, max_count);
		second_hold = search_from_bottom(a_stack, smallest, biggest, max_count);
		if (!first_hold && !second_hold)
		{
			//ft_printf("no values left between %i - %i\n", smallest, biggest);
			break ;
		}
		if (second_hold)
			rotate_second = max_count - second_hold->index;
		if ((first_hold && first_hold->index == 0)
			|| (second_hold && second_hold->index == 0))
		{
			push(b_stack, a_stack, 'b');
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
			continue ;
		}
		if (first_hold && first_hold->index < (max_count / 2) && first_hold->index < rotate_second)
		{
			//ft_printf("rotating forward %i times to get the value %i on top\n", first_hold->index, first_hold->data);
			rotate_multiple(a_stack, 'a', first_hold->index, rotate);
		}
		else if (second_hold && second_hold->index >= (max_count / 2))
		{
			//ft_printf("rotating backwards %i times to get the value %i on top\n", rotate_second, second_hold->data);
			rotate_multiple(a_stack, 'a', rotate_second, rev_rotate);
		}
		if (first_hold)
			first_hold->index = -1;
		if (second_hold)
			second_hold->index = -1;
		push(b_stack, a_stack, 'b');
	}
}

void	sort_kinda_long(t_list **head, int max_count)
{
	t_part	*parts;
	t_part	*parts_temp;
	t_list	*b;

	parts = NULL;
	b = NULL;
	ft_printf("%i\n", max_count);
	parts = init_parts(head, 5);
	parts_temp = parts;
	ft_printf("parting\n");
	while (parts_temp)
	{
		ft_printf("parts %i - %i\n", parts_temp->smallest, parts_temp->biggest);
		parts_temp = parts_temp->next;
	}
	while (parts)
	{
		search_push(&b, head, parts->smallest, parts->biggest);
		parts = parts->next;
	}
}
