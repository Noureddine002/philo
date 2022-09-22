/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:51 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/09/15 15:00:56 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/time.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int				philo_id;
	int				philo_ate;
	int				philo_done_eating;
	long long int	last_philo_meal;
	pid_t			process_id;
	pthread_t		philo_thread;
	struct s_data	*philo_data;
}	t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	int				philo_died;
	int				all_ate;
	long long int	time_start;
	sem_t			*meal;
	sem_t			*forks;
	sem_t			*message;
	t_philo			philo[200];
}	t_data;

int				ft_initialize(t_data *philo_data, char **argv);
int				ft_atoi(const char *str);
long long int	get_time(void);
long long int	time_diff(long long int old, long long int new);
int				lauch_philo(t_data *philo_data);
void			start_philo(t_philo *philo);
void			*monitor_philos(void *arg_philo);
void			put_message(t_data *philo_data, int id, char *message);
void			time_calcul(long long int time, t_data *philo_data);
void			clear(t_data *philo_data);
int				ft_error(char *str, int retu);
int				arg_validation(char **av);
int				check_is_digit(char **av);
void			launch_eating_process(t_philo *philo);

#endif