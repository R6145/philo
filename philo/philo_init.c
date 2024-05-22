/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:34:32 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/22 15:56:18 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_protocol(t_philo *philo, char **argv, int argc)
{
	philo->i[0] = (int)ft_atoi(argv[1]);
	philo->time[0] = (u_int64_t)ft_atoi(argv[2]);
	philo->time[1] = (u_int64_t)ft_atoi(argv[3]);
	philo->time[2] = (u_int64_t)ft_atoi(argv[4]);
	if (argc == 6)
		philo->i[1] = (int)ft_atoi(argv[5]);
	else
		philo->i[1] = -1;
	if (philo->i[0] > 201 || philo->i[0] < 1 || philo->i[1] == 0
		|| philo->time[0] == 0 || philo->time[1] == 0 || philo->time[2] == 0)
		return (printf("Argument not accepted\n"), 127);
	philo->i[2] = 0;
	philo->i[3] = 0;
	philo->thr_id = malloc(sizeof(pthread_t) * philo->i[0]);
	if (philo->thr_id == NULL)
		return (printf("Malloc Error\n"), 127);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->i[0]);
	if (philo->forks == NULL)
		return (printf("Malloc Error\n"), 127);
	philo->philos = malloc(sizeof(t_philo) * philo->i[0]);
	if (philo->philos == NULL)
		return (printf("Malloc Error\n"), 127);
	pthread_mutex_init(&philo->writing, NULL);
	pthread_mutex_init(&philo->locked, NULL);
	return (0);
}

void	init_protocol2(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->i[0])
		pthread_mutex_init(&philo->forks[i++], NULL);
	i = 0;
	while (i < philo->i[0])
	{
		philo->philos[i].left_fork = &philo->forks[i];
		philo->philos[i].right_fork = &philo->forks[i - 1];
		i++;
	}
	philo->philos[0].right_fork = &philo->forks[philo->i[0] - 1];
	i = 0;
	while (i < philo->i[0])
	{
		philo->philos[i].philo = philo;
		philo->philos[i].i[0] = i + 1;
		philo->philos[i].i[1] = 0;
		philo->philos[i].i[2] = 0;
		philo->philos[i].i[3] = 0;
		philo->philos[i].time_death = philo->time[0];
		pthread_mutex_init(&philo->philos[i].lock, NULL);
		i++;
	}
}

int	program_start(t_philo *philo)
{
	int			i;
	pthread_t	over;

	philo->time[3] = current_time();
	pthread_mutex_lock(&philo->locked);
	if (pthread_create(&over, NULL, &overseer, &philo->philos[0]))
		return (printf("overseer creation failed"), free_mem(philo), 127);
	pthread_mutex_unlock(&philo->locked);
	i = 0;
	program_start_ext(philo, i);
	i = 0;
	while (philo->i[0] > i)
	{
		if (pthread_join(philo->thr_id[i], NULL))
			return (printf("freeing error"), free_mem(philo), 127);
		i++;
	}
	if (pthread_join(over, NULL))
		return (printf("freeing error"), free_mem(philo), 127);
	return (0);
}

int	program_start_ext(t_philo *philo, int i)
{
	while (philo->i[0] > i)
	{
		pthread_mutex_lock(&philo->locked);
		if (pthread_create(&philo->thr_id[i], NULL, &t_action,
				&philo->philos[i]))
			return (printf("thread %d mem failed", i), free_mem(philo), 127);
		pthread_mutex_unlock(&philo->locked);
		sleep_for(1, NULL);
		i++;
	}
	return (0);
}
