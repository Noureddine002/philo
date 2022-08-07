/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:29:47 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/14 11:19:34 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	launch_eating_process(t_philo *philo)
{
	t_data	*philo_data;

	philo_data = philo->philo_data;
	pthread_mutex_lock(&(philo_data->forks[philo->left_fork]));
	display_message(philo_data, philo->num_philo, "has taken a fork");
	pthread_mutex_lock(&(philo_data->forks[philo->right_fork]));
	display_message(philo_data, philo->num_philo, "has taken a fork");
	pthread_mutex_lock(&(philo_data->meal));
	display_message(philo_data, philo->num_philo, "is eating");
	philo->last_time_ate = get_time();
	pthread_mutex_unlock(&(philo_data->meal));
	time_calcul(philo_data->time_to_eat, philo_data);
	(philo->num_eat)++;
	pthread_mutex_unlock(&(philo_data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo_data->forks[philo->right_fork]));
}
