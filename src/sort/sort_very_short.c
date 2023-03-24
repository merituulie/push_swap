/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_very_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:21:57 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 14:19:46 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_very_short(t_list **head)
{
	t_list	*temp;

	temp = *head;
	if (temp->data > temp->next->data)
		swap(head, 'a');
	temp = NULL;
	clearall_throw(head, NULL, NULL, 0);
}
