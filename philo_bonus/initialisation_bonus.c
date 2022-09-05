/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:17:20 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/05 14:35:27 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	init_info_with_arg(t_information *info, int argc, char **argv)
{
	info->nbr_philo = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (info->nbr_philo <= 0)
		print_error_msg(ARGC_NBR_PHILO);
	if (argc == 6)
		info->nbr_to_eat = ft_atoi(argv[5]);
	else
		info->nbr_to_eat = -1;
	if (info->nbr_to_eat == 0)
		print_error_msg(ARGC_TIMES_EAT);
	info->id = ft_calloc(info->nbr_philo, sizeof(int));
	if (!info->id)
		print_error_msg(ERROR_CALLOC_ID);
}

void	init_semaphore(t_information *info)
{
	// sem
	info->forks = sem_open("/my_sem", O_CREAT | O_EXCL, 0644,
			info->nbr_philo);
	if (info->forks == SEM_FAILED || sem_unlink("/my_sem"))
		print_error_msg(ERROR_SEMAPHORE);
	//return (EXIT_SUCCESS);
}

/*
0 --> no access to file
6 --> read/write permisson for the user
4 --> read only for the group and others
*/
