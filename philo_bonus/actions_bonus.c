/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:01:14 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 15:35:22 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_take_fork(t_philosophers *philo)
{
	sem_wait(philo->info->forks);
	//philo_display_action(philo, "has taken a fork") DEFINE
}

void	philo_eating(t_philosophers *philo)
{
	philo->last_eat = get_time_in_ms();
	//philo_display_actio(philo, "is eating"); DEFINE
	usleep(philo->info->eat_time * 1000);
}

void	philo_put_down_forks(t_philosophers *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	philo->eat_count++;
	if (philo->eat_count == philo->info->nbr_to_eat)
		exit(EXIT_SUCCESS);
}

void	philo_sleep_and_think(t_philosophers *philo)
{
	//philo_display_actio(philo, "is sleeping");; DEFINE
	usleep(philo->info->sleep_time * 1000);
	//philo_display_actio(philo, "is thinking");; DEFINE
}
