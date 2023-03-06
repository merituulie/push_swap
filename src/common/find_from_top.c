/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_from_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:16:52 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/06 14:16:52 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*search_from_top(t_list **a_stack, int smallest, int biggest, int max_count)
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
