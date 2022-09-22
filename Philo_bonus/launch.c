/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:02:27 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/09/15 16:47:14 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	clear(t_data *philo_data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < philo_data->number_of_philo)
	{
		waitpid(-1, &j, 0);
		if (j != 0)
		{
			i = -1;
			while (++i < philo_data->number_of_philo)
				kill(philo_data->philo[i].process_id, SIGKILL);
			break ;
		}
	}	
	sem_close(philo_data->forks);
	sem_close(philo_data->message);
	sem_close(philo_data->meal);
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/meal");
}

void	*monitor_philos(void *arg_philo)
{
	t_philo	*philo;
	t_data	*philo_data;

	philo = (t_philo *)arg_philo;
	philo_data = philo->philo_data;
	while (1)
	{
		if (philo->philo_done_eating == 1)
			break ;
		if (time_diff(philo->last_philo_meal, get_time())
			> philo_data->time_to_die)
		{
			sem_wait(philo_data->meal);
			put_message(philo_data, philo->philo_id, "died");
			philo_data->philo_died = 1;
			sem_post(philo_data->meal);
			sem_wait(philo_data->message);
			exit(1);
		}
	}
	return (NULL);
}

void	start_philo(t_philo *philo)
{
	t_data	*philo_data;

	philo_data = philo->philo_data;
	philo->last_philo_meal = get_time();
	pthread_create(&(philo->philo_thread), NULL, monitor_philos, philo);
	while (!(philo_data->philo_died) && !(philo->philo_done_eating))
	{
		launch_eating_process(philo);
		if (philo_data->number_of_eat != -1 && philo->philo_ate
			>= philo_data->number_of_eat)
		{
			philo->philo_done_eating = 1;
			break ;
		}
		put_message(philo_data, philo->philo_id, "is sleeping");
		time_calcul(philo_data->time_to_sleep, philo_data);
		put_message(philo_data, philo->philo_id, "is thinking");
		usleep(50);
	}
	pthread_join(philo->philo_thread, NULL);
	if (philo_data->philo_died)
		exit(1);
	exit(0);
}

int	lauch_philo(t_data *philo_data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = philo_data->philo;
	philo_data->time_start = get_time();
	while (++i < philo_data->number_of_philo)
	{
		philo[i].process_id = fork();
		if (philo[i].process_id < 0)
			return (0);
		if (philo[i].process_id == 0)
			start_philo(&philo[i]);
		usleep(50);
	}
	clear(philo_data);
	return (1);
}
