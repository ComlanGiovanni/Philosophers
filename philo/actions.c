/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:43:27 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/06 15:44:49 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief 
 * 
 * we lock the left and right fork print the action currently doing
 * aka has take a fork 2 time, verify that there is not only one philo
 * before locking the second fork/ prin the action
 * we store the time because philo start eating inc the eat_count for
 * the last param we pause for the eating time store in parameter
 * we unlock the right fork then the left
 * we put the right first because if we have 2 philo for exemple
 * the second one will try to take the left fork (we are in a cirular table)
 * 
 * @param philo 
 * @param info 
 */
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

/**
 * @brief
 * 
 * we even lock/unlock a mutex while printing the message of the action
 * we do it if we did not finish to eat or if there is no philo dead
 * 
 * @param info 
 * @param id 
 * @param message 
 */
void	philo_display(t_information *info, int id, char *message)
{
	long long	now;

	now = get_time_in_ms();
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

/**
 * @brief 
 * 
 * we simply display the sleep and think message while waiting the time of the sleep
 * 
 * @param philo 
 * @param info 
 */
void	philo_sleep_and_think(t_philosophers *philo, t_information *info)
{
	philo_display(info, philo->id, COLOR_GREEN SLEEP NO_COLOR);
	pause_time(info, (long long)info->sleep_time);
	philo_display(info, philo->id, COLOR_BLUE THINK NO_COLOR);
}
