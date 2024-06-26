/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:25:08 by fmaqdasi          #+#    #+#             */
/*   Updated: 2024/05/22 16:05:31 by fmaqdasi         ###   ########.fr       */
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

// i = philo_id , eat_amount , death, eating

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

// i = philo_amount , meals_num , death , done
// time	= time_death , time_eat , time_sleep , time_start

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
void				sleep_for(useconds_t time, t_philos *philos);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				free_mem(t_philo *philo);
size_t				ft_strlen(const char *ch);
// checker
int					checker(int argc, char **argv);
int					checkempty(int argc, char **argv);
int					checkspace(int argc, char **argv);
int					checknumeric(int argc, char **argv);
int					checkint(int argc, char **argv);
// init
int					init_protocol(t_philo *philo, char **argv, int argc);
void				init_protocol2(t_philo *philo);
int					program_start(t_philo *philo);
int					program_start_ext(t_philo *philo, int i);
// action
void				print_m(char *str, t_philos *philos);
void				lock_f(t_philos *philos);
void				unlock_f(t_philos *philos);
void				eating(t_philos *philos);
void				*overseer(void *data);
void				*t_checker(void *data);
void				*t_action(void *data);
void				t_action_ext(t_philos *philos);
// special
void				*t_one(void *data);
int					one_philo(t_philo *philo);

#endif