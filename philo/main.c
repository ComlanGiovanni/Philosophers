/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:55:55 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/06 16:04:38 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief 
 * 
 * 					\_(ʘ_ʘ)_/
 * 
 * We initialize a struct for the information of the game
 * and the information of the philosophers
 * if there we dont have 5 or 6 argument we simply print
 * the usage of the progam, we set the memory of info at 0
 * 
 * then we collect the info put int the command line
 * 
 * // die 				./philo 1 800 200 200
 * // no die			./philo 5 800 200 200
 * // only eat 7 times 	./philo 5 800 200 200 7
 * // no die 			./philo 4 410 200 200
 * // one die 			./philo 4 310 200 100
 * 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv )
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
