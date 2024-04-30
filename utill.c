/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:17:20 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/04/30 11:17:58 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	over(const char *str, int sign)
{
	long	tot;
	long	tmp;
	int		i;

	i = 0;
	tot = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tot;
		tot = tot * 10 + str[i] - '0';
		if (tmp > tot)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (tot * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		str++;
	}
	while (str[i] == '0')
		i++;
	return (over(str + i, sign));
}
