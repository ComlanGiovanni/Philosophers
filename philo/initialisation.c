/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:55:58 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/06 14:36:07 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief 
 * 
 * we recieve all the info of the main argc, argv with the info struct to put
 * all the argument in it, the creation time is store with the fonction
 * get_time_in_ms because we need it to display the time for each state
 * (take fork eat sleep die), nbr_philo die_time eat_time sleep_time are check
 * with a tiny modify ft_atoi we check if there no 0 int nbr_phio or nbr_to_eat
 * because we need to have at least 1 philosophers to launch the program
 * and we need to eat at least one time to start all the program mecanic
 * 
 * @param info 
 * @param argc 
 * @param argv 
 */
void	init_info_with_arg(t_information *info, int argc, char **argv)
{
	info->creation_time = get_time_in_ms();
	info->nbr_philo = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (info->nbr_philo <= 0)
		print_error_msg(ARGC_NBR_PHILO);
	if (argc == 6)
	{
		info->nbr_to_eat = ft_atoi(argv[5]);
		if (info->nbr_to_eat == 0)
			print_error_msg(ARGC_TIMES_EAT);
	}
}

/**
 * @brief 
 * 
 * Here we init a mutex for every for so we loop by the nbr_of_philo
 * because in the game rule every philosospher bring 
 * only one fork for the diner
 * 
 * we check if every mutex int and and malloc did not fail, if not, 
 * we exit the progam with a exit failure code and a define error msghy
 * 
 * @param info 
 */
void	init_mutex_forks(t_information *info)
{
	int	index;

	index = 0;
	if (pthread_mutex_init(&(info->lock), NULL))
		print_error_msg(ERROR_MUTEX_LOCK);
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->nbr_philo);
	if (!(info->forks))
		print_error_msg(ERROR_MALLOC_FORK);
	while (index < info->nbr_philo)
	{
		if (pthread_mutex_init(&(info->forks[index]), NULL))
			print_error_msg(ERROR_MUTEX_FORK);
		index++;
	}
}

/**
 * @brief
 * 
 * Here we init all the info needed for each philosopher
 * if the malloc fail we print a proper error message define in .h
 * 
 * for each philosopher we set and id a left and right fork a eat_count 
 * for the last param (number_of_times_each_philosopher_must_eat)
 * and the time stamp of the least time he eat for thr display
 * 
 * 			   so the fork of the philo 0 is index(0)
 * 	 * 1 * 	  but the right on is the fork for the last philo
 *  0     2	 so index(3)			((index + 1) % info->nbr_philo)
 *   * 3 *	
 * 			example for 5 philo
 * 				 index = 1  so fork left it 1 and right one is (1 + 1 % 5) = 2
 * 
 * @param philo 
 * @param info 
 */
void	init_philo_info(t_philosophers **philo, t_information *info)
{
	int	index;

	index = 0;
	*philo = (t_philosophers *)malloc(sizeof(t_philosophers) * info->nbr_philo);
	if (!(philo))
		print_error_msg(ERROR_MALLOC_PHILO);
	while (index < info->nbr_philo)
	{
		(*philo)[index].id = index;
		(*philo)[index].info = info;
		(*philo)[index].left = index;
		(*philo)[index].eat_count = 0;
		(*philo)[index].last_eat = get_time_in_ms();
		(*philo)[index].right = ((index + 1) % info->nbr_philo);
		index++;
	}
}
