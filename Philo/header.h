/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:54:22 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/13 19:00:39 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				num_philo;
	int				num_eat;
	int				finish_eating;
	int				right_fork;
	int				left_fork;
	size_t			last_time_ate;
	pthread_t		id_philo;
	struct s_data	*philo_data;
}	t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				must_eat_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_is_dead;
	size_t			time_start;
	int				must_eat_count_reached;
	pthread_mutex_t	meal;
	pthread_mutex_t	message;
	pthread_mutex_t	forks[200];
	t_philo			philo[200];
}	t_data;

int				ft_error(char *str, int retu);
int				check_is_digit(char **av);
int				arg_validation(char **av);
int				ft_atoi(const char *str);
int				ft_initialize(t_data *philo_data, int ac, char **av);
int				launch_philos(t_data *philo_data);
long long int	get_time(void);
void			display_message(t_data *philo_data, int num_philo, char *str);
void			time_calcul(long long int time, t_data *philo_data);
void			launch_eating_process(t_philo *philo);
long long int	time_diff(long long int old, long long int new);

#endif