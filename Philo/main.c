/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:53:43 by ntanjaou          #+#    #+#             */
/*   Updated: 2022/05/13 18:41:37 by ntanjaou         ###   ########.fr       */
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
	if (!ft_initialize(&philo_data, ac, av))
		return (ft_error("something went wrong while initializing !!\n", 0));
	if (!launch_philos(&philo_data))
		return (ft_error("something went wrong !! \n", 0));
	return (0);
}
