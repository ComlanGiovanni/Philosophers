/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:27:05 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 15:18:08 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philo_threads(t_philosophers *philo, t_information *info)
{
	int	index;

	index = 0;
	while (index < info->nbr_philo)
	{
		philo[index].last_eat = get_time_in_ms();
		if (pthread_create(&(philo[index].thread),
				NULL, philo_routine, &(philo[index])))
			print_error_msg(ERROR_START_PHILO);
		index++;
	}
	check_dead_or_finish(philo, info);
	index = 0;
	while (index < info->nbr_philo)
		pthread_join(philo[index++].thread, NULL);
	free_all_thread(philo, info);
}

void	*philo_routine(void *data)
{
	t_information			*info;
	t_philosophers			*philo;

	philo = data;
	info = philo->info;
/*
	if ((philo->id % 2) != 0)
		usleep(2);
	else
		usleep(4);
*/
	if (philo->id % 2)
		usleep(1000); // same
	else
		usleep(500); // same
	while (!info->finish)
	{
		philo_eat_with_two_fork(philo, info);
		if (info->nbr_to_eat == philo->eat_count)
		{
			info->finished_eat++;
			break ;
		}
		philo_sleep_and_think(philo, info);
	}
	return ((void *)0); // NULL
}

void	check_dead_or_finish(t_philosophers *philo, t_information *info)
{
	int			index;
	long long	current_time;

	while (!info->finish)
	{
		if ((info->nbr_to_eat != 0) && (info->nbr_philo == info->finished_eat))
		{
			info->finish = 1;
			break ;
		}
		index = 0;
		while (index < info->nbr_philo)
		{
			current_time = get_time_in_ms();
			if ((current_time - philo[index].last_eat) >= info->die_time)
			{
				philo_display(info, index, COLOR_PURPLE DIE NO_COLOR);
				info->finish = 1;
				break ;
			}
			index++;
		}
	}
}

void	free_all_thread(t_philosophers *philo, t_information *info)
{
	int	index;

	index = 0;
	while (index < info->nbr_philo)
		pthread_mutex_destroy(&(info->forks[index++]));
	free(philo);
	free(info->forks);
	pthread_mutex_destroy(&(info->lock));
}
