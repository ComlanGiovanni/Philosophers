/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:12:11 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/05 15:01:43 by gcomlan          ###   ########.fr       */
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

void	ft_bzero(void *s, size_t n)
{
	size_t			idx;
	char			*str;

	if (!s)
		return ;
	idx = 0;
	str = (char *)s;
	while (idx < n)
	{
		str[idx] = 0;
		idx++;
	}
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

	/* check
	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	*/
	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

long long	current_time(t_philosophers *philo)
{
	long long	time;

	time = (get_time_in_ms() - philo->info->creation_time);
	return (time);
}
