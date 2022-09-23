/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:11:51 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/13 18:22:38 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	put_message(t_data *philo_data, int id, char *message)
{
	sem_wait(philo_data->message);
	if (!(philo_data->philo_died))
	{
		printf("%lli ms | ", get_time() - philo_data->time_start);
		printf("id : (%d) ", id + 1);
		printf("| %s\n", message);
	}
	sem_post(philo_data->message);
}

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

	i = 1;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
		i++;
	}
	return (1);
}

void	time_calcul(long long int time, t_data *philo_data)
{
	long long	i;

	i = get_time();
	while (!(philo_data->philo_died))
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
