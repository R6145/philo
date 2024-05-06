/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:25:08 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/06 11:25:32 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// int				philo_id;
// int				eat_amount;
// int				death;
// int				eating;

typedef struct s_philos
{
	struct s_philo	*philo;
	int				i[4];
	u_int64_t		time_death;
	pthread_t		thr;
	pthread_mutex_t	lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philos;

// int				philo_amount;
// int				meals_num;
// int				death;
// int				done;
// t_philo			*philos;
// pthread_t		*thr_id;
// u_int64_t		time_death;
// u_int64_t		time_eat;
// u_int64_t		time_sleep;
// u_int64_t		time_start;

typedef struct s_philo
{
	t_philos		*philos;
	int				i[4];
	u_int64_t		time[4];
	pthread_t		*thr_id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	locked;
	pthread_mutex_t	writing;
}					t_philo;

// utill
long				ft_atoi(const char *str);
u_int64_t			current_time(void);
// init
int					init_protocol(t_philo *philo, char **argv, int argc);
void				init_protocol2(t_philo *philo);

#endif