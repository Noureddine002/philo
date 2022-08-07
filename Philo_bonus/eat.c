/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:10:02 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/13 18:24:49 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	launch_eating_process(t_philo *philo)
{
	t_data	*philo_data;

	philo_data = philo->philo_data;
	sem_wait(philo_data->forks);
	put_message(philo_data, philo->philo_id, "has taken a fork");
	sem_wait(philo_data->forks);
	put_message(philo_data, philo->philo_id, "has taken a fork");
	sem_wait(philo_data->meal);
	put_message(philo_data, philo->philo_id, "is eating");
	philo->last_philo_meal = get_time();
	sem_post(philo_data->meal);
	time_calcul(philo_data->time_to_eat, philo_data);
	(philo->philo_ate)++;
	sem_post(philo_data->forks);
	sem_post(philo_data->forks);
}
