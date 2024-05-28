/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:10:27 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/28 14:58:36 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_m(char *str, t_philos *philos)
{
	u_int64_t	time_diff;

	time_diff = current_time() - philos->philo->time[3];
	pthread_mutex_lock(&philos->philo->writing);
	if (ft_strncmp("died", str, 5) == 0 && philos->philo->i[2] == 0)
	{
		printf("%lu ", (unsigned long)time_diff);
		printf("%d %s\n", philos->i[0], str);
		philos->philo->i[2] = 1;
	}
	if (!philos->philo->i[2])
		printf("%lu %d %s\n", (unsigned long)time_diff, philos->i[0], str);
	pthread_mutex_unlock(&philos->philo->writing);
}

void	lock_f(t_philos *philos)
{
	if (philos->right_fork < philos->left_fork)
	{
		pthread_mutex_lock(philos->right_fork);
		pthread_mutex_lock(philos->left_fork);
	}
	else
	{
		pthread_mutex_lock(philos->left_fork);
		pthread_mutex_lock(philos->right_fork);
	}
	pthread_mutex_lock(&philos->philo->locked2);
	print_m("has taken a fork", philos);
	print_m("has taken a fork", philos);
	pthread_mutex_unlock(&philos->philo->locked2);
}

void	unlock_f(t_philos *philos)
{
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
	if (philos->i[1] == philos->philo->i[1])
	{
		return ;
	}
	pthread_mutex_lock(&philos->philo->locked2);
	print_m("is sleeping", philos);
	pthread_mutex_unlock(&philos->philo->locked2);
	sleep_for(philos->philo->time[2], philos);
}

void	eating(t_philos *philos)
{
	lock_f(philos);
	pthread_mutex_lock(&philos->lock);
	philos->time_death = current_time() + philos->philo->time[0];
	pthread_mutex_lock(&philos->philo->locked2);
	print_m("is eating", philos);
	pthread_mutex_unlock(&philos->philo->locked2);
	philos->i[1]++;
	pthread_mutex_unlock(&philos->lock);
	sleep_for(philos->philo->time[1], philos);
	unlock_f(philos);
}
