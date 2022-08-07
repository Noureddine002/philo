/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:27:21 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/13 18:39:43 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_error(char *str, int retu)
{
	if (str)
		write(2, str, ft_strlen(str));
	return (retu);
}

int	arg_validation(char **av)
{
	if (!check_is_digit(av))
		return (0);
	return (1);
}

long long int	get_time(void)
{
	struct timeval	current_time;
	long long int	result;

	gettimeofday(&current_time, NULL);
	result = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (result);
}
