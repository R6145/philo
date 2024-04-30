/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:24:57 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/04/30 11:36:54 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}


// int	alloc(t_data *data)
// {
// 	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
// 	if (!data->tid)
// 		return (error(ALLOC_ERR_1, data));
// 	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
// 	if (!data->forks)
// 		return (error(ALLOC_ERR_2, data));
// 	data->philos = malloc(sizeof(t_philo) * data->philo_num);
// 	if (!data->philos)
// 		return (error(ALLOC_ERR_3, data));
// 	return (0);
// }

// int	init_forks(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->philo_num)
// 		pthread_mutex_init(&data->forks[i], NULL);
// 	i = 0;
// 	data->philos[0].l_fork = &data->forks[0];
// 	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
// 	i = 1;
// 	while (i < data->philo_num)
// 	{
// 		data->philos[i].l_fork = &data->forks[i];
// 		data->philos[i].r_fork = &data->forks[i - 1];
// 		i++;
// 	}
// 	return (0);
// }

// void	init_philos(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->philo_num)
// 	{
// 		data->philos[i].data = data;
// 		data->philos[i].id = i + 1;
// 		data->philos[i].time_to_die = data->death_time;
// 		data->philos[i].eat_cont = 0;
// 		data->philos[i].eating = 0;
// 		data->philos[i].status = 0;
// 		pthread_mutex_init(&data->philos[i].lock, NULL);
// 		i++;
// 	}
// }

// int	init_data(t_data *data, char **argv, int argc)
// {
// 	data->philo_num = (int) ft_atoi(argv[1]);
// 	data->death_time = (u_int64_t) ft_atoi(argv[2]);
// 	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
// 	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
// 	if (argc == 6)
// 		data->meals_nb = (int) ft_atoi(argv[5]);
// 	else
// 		data->meals_nb = -1;
// 	if (data->philo_num <= 0 || data->philo_num > 200)
// 		return (error(ERR_IN_2, NULL));
// 	data->dead = 0;
// 	data->finished = 0;
// 	pthread_mutex_init(&data->write, NULL);
// 	pthread_mutex_init(&data->lock, NULL);
// 	return (0);
// }

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
