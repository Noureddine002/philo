/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:27:07 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/13 18:56:07 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	set_count(t_data *pihlo_data)
{
	pihlo_data->must_eat_count_reached = 1;
	printf("must eat count has been reached !! \n");
}

void	clear(t_data *philo_data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo_data->nb_philos)
	{
		pthread_detach(philo[i].id_philo);
		pthread_mutex_destroy(&(philo_data->forks[i]));
	}
	pthread_mutex_destroy(&(philo_data->message));
	pthread_mutex_destroy(&(philo_data->meal));
}

void	check_philo_state(t_data *philo_data, t_philo *philo, int i, int count)
{
	while (!(philo_data->must_eat_count_reached))
	{
		i = -1;
		while (++i < philo_data->nb_philos
			&& !(philo_data->philo_is_dead))
		{
			if (time_diff(philo[i].last_time_ate, get_time())
				>= philo_data->time_to_die && philo[i].finish_eating != 1)
			{
				display_message(philo_data, i, "is dead");
				philo_data->philo_is_dead = 1;
			}
		}
		if (philo_data->philo_is_dead)
			return ;
		i = -1;
		count = 0;
		while (++i < philo_data->nb_philos
			&& (philo_data->must_eat_count) != -1)
			if (philo[i].num_eat >= philo_data->must_eat_count)
				count++;
		if (count == philo_data->nb_philos)
			set_count(philo_data);
	}
}

void	*start_philos(void *void_philo)
{
	t_philo	*philo;
	t_data	*philo_data;

	philo = (t_philo *)void_philo;
	philo_data = philo->philo_data;
	if (philo->num_philo % 2)
		usleep(1000);
	while (!(philo_data->philo_is_dead))
	{
		launch_eating_process(philo);
		if (philo_data->must_eat_count != -1
			&& philo->num_eat >= philo_data->must_eat_count)
		{
			philo->finish_eating = 1;
			break ;
		}
		if (philo_data->must_eat_count_reached)
			break ;
		display_message(philo_data, philo->num_philo, "is sleeping");
		time_calcul(philo_data->time_to_sleep, philo_data);
		display_message(philo_data, philo->num_philo, "is thinking");
		usleep(50);
	}
	return (NULL);
}

int	launch_philos(t_data *philo_data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = philo_data->philo;
	philo_data->time_start = get_time();
	while (i < philo_data->nb_philos)
	{
		if (pthread_create(&(philo[i].id_philo),
				NULL, start_philos, &(philo[i])) != 0)
			return (0);
		philo[i].last_time_ate = get_time();
		i++;
	}
	check_philo_state(philo_data, philo_data->philo, 0, 0);
	clear(philo_data, philo);
	return (1);
}
