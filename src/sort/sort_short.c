/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:42:11 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/24 14:31:10 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../ft_printf/includes/ft_printf.h"

static void	sort_smaller_element_first(t_list **head)
{
	t_list	*temp;

	temp = *head;
	if (temp->next->data < temp->next->next->data)
		return ;
	else if (temp->data > temp->next->next->data
		&& temp->data < temp->next->data)
		rev_rotate(head, 'a');
	else if (temp->next->data > temp->next->next->data)
	{
		rev_rotate(head, 'a');
		swap(head, 'a');
	}
	else
		exit_failure(head, NULL, NULL);
}

static void	sort_bigger_element_first(t_list **head)
{
	t_list	*temp;

	temp = *head;
	if (temp->data > temp->next->next->data
		&& temp->next->data > temp->next->next->data)
	{
		swap(head, 'a');
		rev_rotate(head, 'a');
	}
	else if (temp->data > temp->next->next->data
		&& temp->next->data < temp->next->next->data)
		rotate(head, 'a');
	else if (temp->next->next->data > temp->data)
		swap(head, 'a');
	else
		exit_failure(head, NULL, NULL);
}

void	sort_short(t_list **head, int from_another)
{
	t_list	*temp;

	temp = *head;
	if (temp->data > temp->next->data)
		sort_bigger_element_first(head);
	else if (temp->data < temp->next->data)
		sort_smaller_element_first(head);
	if (!from_another)
		clearall_throw(head, NULL, NULL, 0);
}
