/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:27:04 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/13 18:40:26 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;
	char	*s;

	i = 0;
	res = 0;
	sign = 1;
	s = (char *)str;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\r' || s[i] == '\f')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = (-1);
		i++;
	}
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res * sign);
}

int	check_is_digit(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (av[i])
	{
		j = -1;
		k = 0;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
		i++;
	}
	return (1);
}

void	display_message(t_data *philo_data, int num_philo, char *str)
{
	pthread_mutex_lock(&(philo_data->message));
	if (!(philo_data->philo_is_dead))
	{
		printf("%lli", get_time() - philo_data->time_start);
		printf(" %d ", num_philo + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(philo_data->message));
	if (philo_data->philo_is_dead)
		pthread_mutex_lock(&(philo_data->message));
}

void	time_calcul(long long int time, t_data *philo_data)
{
	long long	i;

	i = get_time();
	while (!(philo_data->philo_is_dead))
	{
		if (time_diff(i, get_time()) >= time)
			break ;
		usleep(50);
	}
}

long long int	time_diff(long long int old, long long int new)
{
	long long int	result;

	result = new - old;
	return (result);
}
