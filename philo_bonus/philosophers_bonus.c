/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:17:25 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/05 14:56:17 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	start_philo(t_information *info)
{
	int				id;
	int				idx;
	t_philosophers	*philo;

	idx = 0;
	philo = ft_calloc(info->nbr_philo, sizeof(t_philosophers));
	if (!philo)
		print_error_msg(ERROR_CALLOC_PHILO);
	info->creation_time = get_time_in_ms();
	while (idx < info->nbr_philo)
	{
		init_philo_info(philo + idx, info);
		id = fork();
		if (id == 0)
		{
			philo[idx].id = idx;
			philo_actions(philo + idx);
		}
		else
			info->id[idx] = id;
		idx++;
		usleep(100);
	}
	free(philo);
}

void	init_philo_info(t_philosophers *philo, t_information *info)
{
	philo->info = info;
	philo->eat_count = 0;
	philo->last_eat = info->creation_time;
	philo->die = FALSE; // make a type def ball TRUE FALSE
}

void	philo_actions(t_philosophers *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_dead, philo);
	while ("The prophecy is true")
	{
		philo_take_fork(philo);
		philo_take_fork(philo);
		philo_eating(philo);
		philo_put_down_forks(philo);
		philo_sleep_and_think(philo);
	}
	pthread_join(thread, NULL);
}

void	*check_dead(void *data)
{
	t_philosophers	*philo;

	philo = data;
	while ("The prophecy is true")
	{
		if ((philo->last_eat + philo->info->die_time) < get_time_in_ms())
		{
			philo_display_action(philo, DIE);
			exit(EXIT_FAILURE);
		}
		usleep(1000);
	}
	return ((void *)0);
}

void	free_all(t_information *info)
{
	int	idx;
	int	status;

	idx = 0; //
	while (idx++ < info->nbr_philo) //
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			idx = 0;
			while (idx < info->nbr_philo)
				kill(info->id[idx++], 15);
			break ;
		}
	}
	sem_close(info->forks);
	free(info->id);
	free(info);
}
