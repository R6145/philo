/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:16:40 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/17 15:38:08 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkempty(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < argc)
	{
		flag = 0;
		if (argv[i][0] == ' ')
		{
			while (argv[i][j] != '\0')
			{
				if ((argv[i][j] >= 48 && argv[i][j] <= 57))
					flag = (1);
				j++;
			}
			if (flag == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkspace(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "", 10) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	checknumeric(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkint(int argc, char **argv)
{
	int		i;
	long	*temp;

	i = 1;
	temp = malloc(sizeof(long) * (argc + 1));
	if (!temp)
		return (0);
	while (i < argc)
	{
		temp[i] = ft_atoi(argv[i]);
		if (temp[i] >= 0 && ft_strlen(argv[i]) > 13)
			return (free(temp), 0);
		i++;
	}
	return (free(temp), 1);
}

int	checker(int argc, char **argv)
{
	if (checkempty(argc, argv) == 0)
		return (printf("Error: empty argument\n"), 127);
	else if (checkspace(argc, argv) == 0)
		return (printf("Error: empty argument\n"), 127);
	else if (checknumeric(argc, argv) == 0)
		return (printf("Error: number not accepted\n"), 127);
	else if (checkint(argc, argv) == 0)
		return (printf("Error: number not accepted\n"), 127);
	return (1);
}
