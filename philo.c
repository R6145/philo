/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:24:57 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/06 11:34:53 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	init(t_data *data, char **argv, int argc)
// {
// 	if (init_data(data, argv, argc))
// 		return (1);
// 	if (alloc(data))
// 		return (1);
// 	if (init_forks(data))
// 		return (1);
// 	init_philos(data);
// 	return (0);
// }

// int	case_one(t_data *data)
// {
// 	data->start_time = get_time();
// 	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
// 		return (error(TH_ERR, data));
// 	pthread_detach(data->tid[0]);
// 	while (data->dead == 0)
// 		ft_usleep(0);
// 	ft_exit(data);
// 	return (0);
// }

// void	clear_data(t_data	*data)
// {
// 	if (data->tid)
// 		free(data->tid);
// 	if (data->forks)
// 		free(data->forks);
// 	if (data->philos)
// 		free(data->philos);
// }

// void	ft_exit(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->philo_num)
// 	{
// 		pthread_mutex_destroy(&data->forks[i]);
// 		pthread_mutex_destroy(&data->philos[i].lock);
// 	}
// 	pthread_mutex_destroy(&data->write);
// 	pthread_mutex_destroy(&data->lock);
// 	clear_data(data);
// }

int	main(void)
{
	printf("%llu\n", current_time());
}
