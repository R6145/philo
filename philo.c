/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:24:57 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/11 16:13:41 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

//cc philo.c philo_util.c philo_init.c philo_action.c philo_actionii.c philo.h
// ./a.out 3 100 100 100 4



int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (127);
	// if (input_checker(argv))
	// 	return (127);
	if (init_protocol(&philo, argv, argc) != 0)
		return (127);
	init_protocol2(&philo);
	// if (init(&data, argv, argc))
	// 	return (1);
	// if (data.philo_num == 1)
	// 	return (case_one(&data));
	if (program_start(&philo) != 0)
		return (1);
	free_mem(&philo);
	return (0);
}
