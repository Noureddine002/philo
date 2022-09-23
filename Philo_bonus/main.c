/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:01:32 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/09/15 15:01:34 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

int	main(int ac, char **av)
{
	t_data	philo_data;

	if (ac < 5 || ac > 6)
		return (ft_error("invalid argument number !!\n", 0));
	if (!arg_validation(av))
		return (ft_error("invalid argument !!\n", 0));
	if (!ft_initialize(&philo_data, av))
		return (ft_error("something went wrong while initializing !!\n", 0));
	if (!lauch_philo(&philo_data))
		return (ft_error("something went wrong !! \n", 0));
	return (0);
}
