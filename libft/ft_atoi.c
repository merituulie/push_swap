/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:34:28 by meskelin          #+#    #+#             */
/*   Updated: 2023/02/13 18:28:01 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../ft_printf/headers/ft_printf.h"

static int	is_overflow(int sign, long result)
{
	if ((sign == 1 && result > 2147483647)
		|| (sign == -1 && result > 2147483648))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		str_len;

	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	str_len = ft_strlen(str);
	if (str[0] == '\0' || (*str == '0' && str_len > 1))
		return (-1);
	result = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		result = result * 10 + *str - '0';
		if (is_overflow(sign, result))
			return (-1);
		str++;
	}
	return ((int)result * sign);
}
