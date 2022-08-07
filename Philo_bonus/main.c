/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:27:50 by aqadil            #+#    #+#             */
/*   Updated: 2022/05/13 18:24:11 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

int	main(int ac, char **av)
{
	t_data	philo_data;

	if (ac < 5 || ac > 6)
		return (ft_error("invalid argument number !!\n", 0));
	if (!arg_validation(av))
		return (ft_error("invalid argument type !!\n", 0));
	if (!ft_initialize(&philo_data, av))
		return (ft_error("something went wrong while initializing !!\n", 0));
	if (!lauch_philo(&philo_data))
		return (ft_error("something went wrong !! \n", 0));
	return (0);
}
