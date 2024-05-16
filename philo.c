/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:24:57 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/17 00:07:06 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// cc philo.c philo_util.c philo_init.c philo_action.c philo_actionii.c philo_checker.c philo_util2.c
// ./a.out 3 100 100 100 4

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (127);
	if (checker(argc,argv) != 1)
		return (127);
	if (init_protocol(&philo, argv, argc) != 0)
		return (127);
	init_protocol2(&philo);
	if (philo.i[0] == 1)
		return (one_philo(&philo), exit(0), 0);
	if (program_start(&philo) != 0)
		return (1);
	free_mem(&philo);
	return (0);
}
