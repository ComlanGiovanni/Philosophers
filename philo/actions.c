/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:43:27 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 14:25:22 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat_with_two_fork(t_philosophers *philo, t_information *info)
{
	pthread_mutex_lock(&(info->forks[philo->left]));
	philo_display(info, philo->id, COLOR_RED TAKE_FORK NO_COLOR);
	if (info->nbr_philo != 1)
	{
		pthread_mutex_lock(&(info->forks[philo->right]));
		philo_display(info, philo->id, COLOR_RED TAKE_FORK NO_COLOR);
		philo_display(info, philo->id, COLOR_YELLOW EAT NO_COLOR);
		philo->last_eat = get_time_in_ms();
		philo->eat_count = philo->eat_count + 1;
		pause_time(info, (long long)info->eat_time);
		pthread_mutex_unlock(&(info->forks[philo->right]));
	}
	pthread_mutex_unlock(&(info->forks[philo->left]));
}

void	philo_display(t_information *info, int id, char *message)	//name
{
	long long	now;

	now = get_time_in_ms();
	/*
	// not that important ?
	if (now == -1)
		print_error_msg(ERROR_TIME ?);
		// malloc no free leak fct with info philo to free
	*/
	pthread_mutex_lock(&(info->lock));
	if (!(info->finish))
	{
		printf("%s", COLOR_ORANGE);
		printf("%lld ", (now - info->creation_time));
		printf("%s", NO_COLOR);
		printf("%s", COLOR_LIGHT_CYAN);
		printf("%d ", id + 1);
		printf("%s", NO_COLOR);
		printf("%s\n", message);
	}
	pthread_mutex_unlock(&(info->lock));
}

void	philo_sleep_and_think(t_philosophers *philo, t_information *info)
{
	philo_display(info, philo->id, COLOR_GREEN SLEEP NO_COLOR);
	pause_time(info, (long long)info->sleep_time);
	philo_display(info, philo->id, COLOR_BLUE THINK NO_COLOR);
}
