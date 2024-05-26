/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:33:21 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/26 17:00:36 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (printf("time error\n"), 0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void	sleep_for(useconds_t time, t_philos *philos)
{
	u_int64_t	start;

	start = current_time();
	if (philos == NULL)
	{
		while ((current_time() - start) < time)
			usleep(time / 10);
	}
	else
	{
		while ((current_time() - start) < time)
		{
			pthread_mutex_lock(&philos->philo->writing);
			if (philos->philo->i[2] == 0)
			{
				pthread_mutex_unlock(&philos->philo->writing);
				usleep(time / 10);
			}
			else
				break ;
		}
		pthread_mutex_unlock(&philos->philo->writing);
	}
}

long	ft_atoi(const char *str)
{
	long	sign;
	int		i;
	long	tot;

	i = 0;
	sign = 1;
	tot = 0;
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		tot = tot * 10 + str[i] - '0';
		i++;
	}
	return (tot * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n - i > 1 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

void	free_mem(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo == NULL)
		return ;
	while (philo->i[0] > i)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		pthread_mutex_destroy(&philo->philos[i].lock);
		i++;
	}
	pthread_mutex_destroy(&philo->writing);
	pthread_mutex_destroy(&philo->locked);
	free(philo->thr_id);
	free(philo->forks);
	free(philo->philos);
}
