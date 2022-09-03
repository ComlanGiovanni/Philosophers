/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:12:11 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 15:21:43 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
		//print_error_msg(ERROR_NEGATIVE_ARG);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb && (nmemb * size / nmemb) != size)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero((char *)dest, nmemb * size);
	return ((char *)dest);
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
long long	get_time_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
*/

long long	current_time(t_philosophers *philo)
{
	long long	time;

	time = get_time_in_ms() - philo->info->creation_time;
	return (time);
}

void	philo_display_actio(t_philosophers *philo, char *message)
{
	if (!philo->die)
		printf("%lli\t%i\t%s\n", current_time(philo), philo->id + 1, message);
}

/*
void	philo_display(t_information *info, int id, char *message)	//name
{
	long long	now;

	now = get_time_in_ms();
	/*
	// not that important ?
	if (now == -1)
		print_error_msg(ERROR_TIME ?);
		// malloc no free leak fct with info philo to free
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

*/
