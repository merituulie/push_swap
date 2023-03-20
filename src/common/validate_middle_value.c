/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_middle_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:47:44 by meskelin          #+#    #+#             */
/*   Updated: 2023/03/20 22:47:44 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_bs(t_list *previous, t_list *next, int biggest, int smallest)
{
	if ((previous->data == biggest && next->data == smallest)
		|| (next->data == biggest && previous->data == smallest))
		return (1);
	return (0);
}

int	is_middle(int to_be_pushed, t_list *previous, t_list *next)
{
	if ((to_be_pushed < previous->data && to_be_pushed > next->data)
		|| (to_be_pushed > previous->data && to_be_pushed < next->data))
		return (1);
	return (0);
}
