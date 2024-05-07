/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:10:27 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/07 11:58:44 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	messages(char *str, t_philos *philos)
{
	pthread_mutex_lock(&philos->philo->writing);
	if (ft_strcmp("died", str) == 0 && philos->philo->i[2] == 0)
	{
		printf("%lu ", get_time() - philos->philo->time[3]);
		printf("%d %s\n", philos->i[0], str);
		philos->philo->i[2] = 1;
	}
	if (!philos->philo->i[2])
		printf("%lu %d %s\n", get_time() - philos->philo->time[3], philos->i[0],
			str);
	pthread_mutex_unlock(&philos->philo->writing);
}


void	take_forks(t_philos *philos)
{
	pthread_mutex_lock(philos->right_fork);
	messages("has taken a fork", philos);
	pthread_mutex_lock(philos->left_fork);
	messages("has taken a fork", philos);
}

void	drop_forks(t_philos *philos)
{
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
	messages("is sleeping", philos);
	ft_usleep(philos->philo->time[2]);
}

void	eat(t_philos *philos)
{
	take_forks(philo);
	// pthread_mutex_lock(&philo->lock);
	// philo->eating = 1;
	// philo->time_to_die = get_time() + philo->data->death_time;
	// messages(EATING, philo);
	// philo->eat_cont++;
	// ft_usleep(philo->data->eat_time);
	// philo->eating = 0;
	// pthread_mutex_unlock(&philo->lock);
	drop_forks(philos);
}