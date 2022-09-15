/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:39:54 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/09/15 16:28:36 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

int	ft_initialize_mutex(t_data *philo_data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(philo_data->message), NULL);
	pthread_mutex_init(&(philo_data->meal), NULL);
	while (i < philo_data->nb_philos)
		pthread_mutex_init(&philo_data->forks[i++], NULL);
	return (1);
}

void	ft_initialize_philo(t_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo_data->nb_philos)
	{
		philo_data->philo[i].num_philo = i;
		philo_data->philo[i].num_eat = 0;
		philo_data->philo[i].left_fork = i;
		philo_data->philo[i].right_fork = (i + 1) % philo_data->nb_philos;
		philo_data->philo[i].last_time_ate = 0;
		philo_data->philo->finish_eating = 0;
		philo_data->philo[i].philo_data = philo_data;
		i++;
	}
}

int	ft_initialize(t_data *philo_data, int ac, char **av)
{
	philo_data->nb_philos = ft_atoi(av[1]);
	philo_data->time_to_die = ft_atoi(av[2]);
	philo_data->time_to_eat = ft_atoi(av[3]);
	philo_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		philo_data->must_eat_count = ft_atoi(av[5]);
		if (philo_data->must_eat_count < 1)
			return (0);
	}
	else
		philo_data->must_eat_count = -1;
	philo_data->must_eat_count_reached = 0;
	philo_data->philo_is_dead = 0;
	if (philo_data->nb_philos < 1 || philo_data->time_to_die < 0
		|| philo_data->time_to_eat < 0 || philo_data->time_to_sleep < 0 || philo_data->nb_philos > 200)
		return (0);
	if (!ft_initialize_mutex(philo_data))
		return (0);
	ft_initialize_philo(philo_data);
	return (1);
}
