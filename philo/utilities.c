/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:55:53 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 13:19:47 by gcomlan          ###   ########.fr       */
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

void	print_error_msg(char *message)
{
	printf("❌ %s ", ERROR_MSG);
	printf("%s", COLOR_RED);
	printf("%s\n", message);
	printf("%s", NO_COLOR);
	exit(EXIT_FAILURE);
}

long long	get_time_in_ms(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

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

void	print_usage(void)
{
	printf("📚  %s", USAGE);
	printf("%s", COLOR_BLUE);
	printf(" %s", PROGRAM_NAME);
	printf("%s", NO_COLOR);
	printf("%s", COLOR_LIGHT_CYAN);
	printf(" %s", ARGC_NBR_PHILO);
	printf("%s", NO_COLOR);
	printf("%s", COLOR_PURPLE);
	printf(" %s", ARGC_DIE_TIME);
	printf("%s", NO_COLOR);
	printf("%s", COLOR_YELLOW);
	printf(" %s", ARGC_EAT_TIME);
	printf("%s", NO_COLOR);
	printf("%s", COLOR_GREEN);
	printf(" %s", ARGC_SLEEP_TIME);
	printf("%s", NO_COLOR);
	printf("%s", COLOR_DARK_GRAY);
	printf(" %s\n", ARGC_TIMES_EAT);
	printf("%s", NO_COLOR);
	exit(EXIT_FAILURE);
}
