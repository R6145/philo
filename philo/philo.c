/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:24:57 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:57 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc < 5 || argc > 6)
		return (printf("Wrong Number of Arguments\n"), 127);
	if (checker(argc, argv) != 1)
		return (127);
	if (init_protocol(&philo, argv, argc) != 0)
		return (127);
	init_protocol2(&philo);
	if (philo.i[0] == 1)
		return (one_philo(&philo), 0);
	if (program_start(&philo) != 0)
		return (1);
	free_mem(&philo);
	return (0);
}
