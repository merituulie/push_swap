/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_from_bottom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:17:42 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/27 13:59:24 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*search_from_bottom(t_list **a_stack, int smallest,
			int biggest, int max_count)
{
	t_list	*current;
	int		index;

	current = *a_stack;
	index = max_count - 1;
	while (current->next)
		current = current->next;
	while (current->prev && index >= ((max_count - 1) / 2))
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
