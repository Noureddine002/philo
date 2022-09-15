/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:01:10 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/09/15 15:01:18 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

int	initialize_semaphore(t_data *philo_data)
{
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/meal");
	philo_data->forks = sem_open("/forks", O_CREAT, S_IRWXU,
			philo_data->number_of_philo);
	philo_data->message = sem_open("/message", O_CREAT, S_IRWXU, 1);
	philo_data->meal = sem_open("/meal", O_CREAT, S_IRWXU, 1);
	if (philo_data->forks <= 0 || philo_data->message <= 0
		|| philo_data->meal <= 0)
		return (0);
	return (1);
}

void	initialize_philo(t_data *philo_data)
{
	int	i;

	i = 0;
	while (i < philo_data->number_of_philo)
	{
		philo_data->philo[i].philo_id = i;
		philo_data->philo[i].philo_ate = 0;
		philo_data->philo[i].last_philo_meal = 0;
		philo_data->philo[i].philo_done_eating = 0;
		philo_data->philo[i].philo_data = philo_data;
		i++;
	}
}

int	ft_initialize(t_data *philo_data, char **argv)
{
	philo_data->number_of_philo = ft_atoi(argv[1]);
	philo_data->time_to_die = ft_atoi(argv[2]);
	philo_data->time_to_eat = ft_atoi(argv[3]);
	philo_data->time_to_sleep = ft_atoi(argv[4]);
	philo_data->philo_died = 0;
	if (argv[5])
	{
		philo_data->number_of_eat = ft_atoi(argv[5]);
		if (philo_data->number_of_eat < 1)
			return (0);
	}
	else
		philo_data->number_of_eat = -1;
	if (philo_data->number_of_philo < 1
		|| philo_data->time_to_die < 60 || philo_data->time_to_eat < 60
		|| philo_data->time_to_sleep < 60)
		return (0);
	if (!initialize_semaphore(philo_data))
		return (0);
	initialize_philo((philo_data));
	return (1);
}
