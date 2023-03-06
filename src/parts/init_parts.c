/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:12:55 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/03 15:20:14 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static int	find_part_biggest(int smallest, t_list **head, int count)
{
	count -= 1;
	while (count > 0)
	{
		smallest = find_next_smallest(*head, smallest);
		count--;
	}
	return (smallest);
}

static void	add_part(t_part **head, t_list **stack, int count, int last_biggest)
{
	int next_smallest;
	int next_biggest;

	next_smallest = find_next_smallest(*stack, last_biggest);
	next_biggest = find_part_biggest(next_smallest, stack, count);
	prtadd_to_parts(head, next_smallest, next_biggest, 0);
}

static t_part	*fill_parts(t_list **stack, int count, int part_count)
{
	t_part	*head;
	t_part	*current;
	int		i;

	prtadd_to_parts(&head, 0, 0, 1);
	current = head;
	current->smallest = find_smallest(*stack, 0);
	current->biggest = find_part_biggest(current->smallest, stack, count);
	i = 1;
	while (i < part_count && current)
	{
		add_part(&head, stack, count, current->biggest);
		current = current->next;
		i++;
	}
	return (head);
}

t_part	*init_parts(t_list **head, int part_count)
{
	int		count;

	count = (get_listsize(head)) / part_count;
	return (fill_parts(head, count, part_count));
}
