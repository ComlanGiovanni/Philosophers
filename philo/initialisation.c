/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:55:58 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 14:17:40 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
