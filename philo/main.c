/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:55:55 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 14:30:34 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_information		info;
	t_philosophers		*philo;

	if (argc != 5 && argc != 6)
		print_usage();
	memset(&info, 0, sizeof(t_information));
	init_info_with_arg(&info, argc, argv);
	init_mutex_forks(&info);
	init_philo_info(&philo, &info);
	start_philo_threads(philo, &info);
	return (EXIT_SUCCESS);
}
