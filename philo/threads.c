/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:27:05 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/06 16:01:10 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief 
 * 
 * Here we start a threads for each philo with phread_create
 * &(philo[index].thread is the pointer where we store the id of the thread
 *  NULL because we do not need to modify the default attribut of the new thread
 * at his creation,,, philo_routine his the routine call 
 * at the start of the execution, define message and exit code if fail
 * we pass a pointer of a struct (the current philo)
 * that gonna be pass a the routine
 * of the thread (void *data)
 * 
 * then we check if there is no dead or if the program is finish
 * 
 * for each philosopher we check bloc the execution wating
 * for the previous thread to finish we pass the thread of the philo and
 * NULL because we dont stock a value of the routine of the thread
 * 
 * the we free all the thread
 * 
 * @param philo 
 * @param info 
 */
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

/**
 * @brief
 * 
 * so for the even philo we wait longer that the odd philo like that
 * we prevent temporal shift and some itrap
 * then we loop until is not finish and call all the action
 * we inc the finished_eat only if every philo eat
 * 
 * @param data 
 * @return void* 
 */
void	*philo_routine(void *data)
{
	t_information			*info;
	t_philosophers			*philo;

	philo = data;
	info = philo->info;
	if (philo->id % 2)
		usleep(1000);
	else
		usleep(500);
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
	return ((void *)0);
}

/**
 * @brief 
 * 
 * so while we did not finish the execution of the program
 * we set finish at 1 if every body eat && if the nbr_to_eat is not 0
 * then for each philo we check if the current time minus the last time 
 * the philo eat is > at the time to die otherwise we break and see finish to 1
 * 
 * @param philo 
 * @param info 
 */
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

/**
 * @brief 
 * 
 * we destroy every mutex
 * we free the philo and all the forks
 * 
 * @param philo 
 * @param info 
 */
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
