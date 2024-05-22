/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:58:25 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/22 16:36:36 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *ch)
{
	int	i;

	i = 0;
	while (ch[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*t_one(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	philos->time_death = philos->philo->time[0] + current_time();
	pthread_mutex_lock(&philos->philo->locked);
	pthread_mutex_lock(philos->left_fork);
	printf("%lu %d %s\n", (unsigned long)0, philos->i[0], "has taken a fork");
	pthread_mutex_unlock(philos->left_fork);
	sleep_for(philos->philo->time[0], NULL);
	printf("%lu ", (unsigned long)philos->philo->time[0]);
	printf("%d %s\n", philos->i[0], "died");
	sleep_for(400, NULL);
	pthread_mutex_unlock(&philos->philo->locked);
	return ((void *)0);
}

int	one_philo(t_philo *philo)
{
	philo->time[3] = current_time();
	if (pthread_create(&philo->thr_id[0], NULL, &t_one, &philo->philos[0]))
		return (printf("thread %d mem failed", 0), free_mem(philo), 127);
	if (pthread_join(philo->thr_id[0], NULL))
		return (printf("freeing error"), free_mem(philo), 127);
	free_mem(philo);
	return (0);
}
