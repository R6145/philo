/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actionii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:32:31 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/22 17:51:31 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*overseer(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&philos->lock);
		pthread_mutex_lock(&philos->philo->writing);
		if (philos->philo->i[2] != 0)
		{
			pthread_mutex_unlock(&philos->philo->writing);
			pthread_mutex_unlock(&philos->lock);
			break ;
		}
		if (philos->philo->i[3] == philos->philo->i[0])
			philos->philo->i[2] = 1;
		pthread_mutex_unlock(&philos->philo->writing);
		pthread_mutex_unlock(&philos->lock);
	}
	return ((void *)0);
}

void	*t_checker(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	while (1)
	{
		pthread_mutex_lock(&philos->lock);
		pthread_mutex_lock(&philos->philo->writing);
		if (philos->philo->i[2] == 1)
			return (pthread_mutex_unlock(&philos->lock),
				pthread_mutex_unlock(&philos->philo->writing), (void *)0);
		pthread_mutex_unlock(&philos->philo->writing);
		if (current_time() >= philos->time_death)
			print_m("died", philos);
		if (philos->i[1] == philos->philo->i[1])
		{
			pthread_mutex_lock(&philos->philo->locked);
			philos->philo->i[3]++;
			philos->i[1]++;
			pthread_mutex_unlock(&philos->philo->locked);
		}
		pthread_mutex_unlock(&philos->lock);
	}
	return ((void *)0);
}

void	*t_action(void *data)
{
	t_philos	*philos;

	philos = (t_philos *)data;
	philos->time_death = philos->philo->time[0] + current_time();
	pthread_mutex_lock(&philos->philo->locked);
	if (pthread_create(&philos->thr, NULL, &t_checker, (void *)philos))
		return ((void *)1);
	pthread_mutex_unlock(&philos->philo->locked);
	while (1)
	{
		pthread_mutex_lock(&philos->philo->writing);
		if (philos->philo->i[2] != 0)
		{
			pthread_mutex_unlock(&philos->philo->writing);
			break ;
		}
		pthread_mutex_unlock(&philos->philo->writing);
		if (!(philos->i[1] > philos->philo->i[1]) || philos->philo->i[1] == -1)
			t_action_ext(philos);
	}
	if (pthread_join(philos->thr, NULL))
		return ((void *)127);
	return ((void *)0);
}

void	t_action_ext(t_philos *philos)
{
	eating(philos);
	print_m("is thinking", philos);
}
