/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actionii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:32:31 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/28 14:58:11 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*overseer(void *data)
{
	t_philos	*philos;
	int			j;

	philos = (t_philos *)data;
	while (1)
	{
		j = 0;
		usleep(1000);
		while (j < philos->philo->i[0])
		{
			pthread_mutex_lock(&(philos->philo->philos[j].lock));
			pthread_mutex_lock(&philos->philo->writing);
			if (philos->philo->i[2] == 1)
				return (pthread_mutex_unlock(&philos->philo->philos[j].lock),
					pthread_mutex_unlock(&philos->philo->writing), (void *)0);
			pthread_mutex_unlock(&philos->philo->writing);
			pthread_mutex_lock(&philos->philo->locked);
			overseer2(philos, j);
			pthread_mutex_unlock(&philos->philo->locked);
			pthread_mutex_unlock(&(philos->philo->philos[j].lock));
			j++;
		}
	}
	return ((void *)0);
}

void	overseer2(t_philos *philos, int j)
{
	if (current_time() >= philos->philo->philos[j].time_death)
		print_m("died", &philos->philo->philos[j]);
	pthread_mutex_lock(&philos->philo->writing);
	if (philos->philo->i[3] == philos->philo->i[0])
		philos->philo->i[2] = 1;
	pthread_mutex_unlock(&philos->philo->writing);
}

void	*t_action(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	pthread_mutex_lock(&philos->philo->locked);
	philos->time_death = philos->philo->time[0] + current_time();
	pthread_mutex_unlock(&philos->philo->locked);
	if (philos->i[0] % 2 == 0)
		sleep_for(philos->philo->time[2], philos);
	while (1)
	{
		usleep(1000);
		t_action_am(philos);
		pthread_mutex_lock(&philos->philo->writing);
		if (philos->philo->i[2] != 0 || (philos->i[1] > philos->philo->i[1]
				&& philos->philo->i[1] != -1))
		{
			pthread_mutex_unlock(&philos->philo->writing);
			break ;
		}
		pthread_mutex_unlock(&philos->philo->writing);
		t_action_act(philos);
	}
	return ((void *)0);
}

void	t_action_act(t_philos *philos)
{
	if (!(philos->i[1] > philos->philo->i[1]) || philos->philo->i[1] == -1)
	{
		eating(philos);
		if (philos->i[1] == philos->philo->i[1])
		{
			return ;
		}
		pthread_mutex_lock(&philos->philo->locked2);
		print_m("is thinking", philos);
		pthread_mutex_unlock(&philos->philo->locked2);
	}
}

void	t_action_am(t_philos *philos)
{
	if (philos->i[1] == philos->philo->i[1])
	{
		pthread_mutex_lock(&philos->philo->locked);
		philos->philo->i[3]++;
		philos->i[1]++;
		pthread_mutex_unlock(&philos->philo->locked);
	}
}
