/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:55:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 15:39:49 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	result;

	index = 0;
	sign = 1;
	result = 0;
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index++;
	if (str[index] == '-')
		print_error_msg(ERROR_NEGATIVE_ARG);
	else if (str[index] == '+')
		index++;
	while (str[index] != '\0' && (str[index] >= '0' && str[index] <= '9'))
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	return (result * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0' && s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}

long long	get_time_in_ms(void)
{
	struct timeval	current_time;

	//check
	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

/*
long long	current_time(t_philosophers *philo)
{
	long long	time;

	time = get_time_in_ms() - philo->info->creation_time;
	return (time);
}
*/

void	pause_time(t_information *info, long long wait_time)
{
	long long	now;
	long long	start;

	start = get_time_in_ms();
	while (!(info->finish))
	{
		now = get_time_in_ms();
		if ((now - start) >= wait_time)
			break ;
		usleep(10); // check
	}
}
