/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:58:25 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/21 13:10:11 by fmaqdasi         ###   ########.fr       */
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

int	one_philo(t_philo *philo)
{
	philo->time[3] = current_time();
	printf("%lu %d %s\n", (unsigned long)0, philo->philos->i[0],
		"has taken a fork");
	sleep_for(100, NULL);
	printf("%lu ", (unsigned long)100);
	printf("%d %s\n", philo->philos->i[0], "died");
	sleep_for(400, NULL);
	pthread_detach(philo->thr_id[0]);
	free_mem(philo);
	return (0);
}
