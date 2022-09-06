/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:55:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/06 15:10:20 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief 
 * 
 * The famous ft_atoi done again again and again in picsine exam in project
 * we dont explain that long we parse a string (str) and look for a -
 * if we found it we display an error message and quit
 * if we found a digit we store it an mutiply by the sign bruh its useless here
 * because we quit if there is negative sign ?? but its work so chill
 * 
 * @param str 
 * @return int 
 */
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

/**
 * @brief 
 * 
 * on of the famous ft fct its a simple comparator of string
 * if we found a differente char in s1 s2 we stop and return the define,
 * we use it to compare the message with a define error message to diplay
 * some message with color
 * 
 * @param s1 
 * @param s2 
 * @return int 
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0' && s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}

/**
 * @brief Get the time in ms object
 * 
 *  The struct timeval contain tv_sec (secondes) and tv_usec (microsecondes)
 * 	 give the time since 1 janv 197 in sec en microsec
 * 		The use of the timezone structure is obsolete; the tz argument 
 * 			should normally be specified as NULL. 
 * 
 * 	1s -> 1000 Millisecondes -> 1000 000 microsecondes
 * 	
 * @return long long 
 */
long long	get_time_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

/**
 * @brief 
 * 
 * we wait until the wait_time has pass
 * 
 * @param info 
 * @param wait_time 
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
		usleep(10);
	}
}
