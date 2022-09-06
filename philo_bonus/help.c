/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:36:06 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/06 16:27:17 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/**
 * @brief 
 * 
 * We print any given error message define in philosopher.h or not and exit
 * with EXIT_FAILLURE code, we check with ft_strcmp for a specific error message
 * to display with some color for better display, check the define int the .h
 * for the formating logic error the problem then error msg
 * 
 * @param message 
 */
void	print_error_msg(char *message)
{
	printf("❌ %s ", ERROR_MSG);
	if (!ft_strcmp(message, ARGC_NBR_PHILO))
	{
		printf("%s", COLOR_LIGHT_CYAN);
		printf("%s", ARGC_NBR_PHILO);
		printf("%s", COLOR_RED);
		printf(" %s\n", ERROR_NBR_INF_0);
	}
	else if (!ft_strcmp(message, ARGC_TIMES_EAT))
	{
		printf("%s", COLOR_LIGHT_CYAN);
		printf("%s", ARGC_TIMES_EAT);
		printf("%s", COLOR_RED);
		printf(" %s\n", ERROR_NBR_INF_0);
	}
	else
	{
		printf("%s", COLOR_RED);
		printf("%s\n", message);
	}
	exit(EXIT_FAILURE);
}

/**
 * @brief 
 * 
 * we simply print with some color the usage of the program
 * 
 */
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

void	philo_display_action(t_philosophers *philo, char *message)
{
	if (!philo->die)
	{
		printf("%s", COLOR_ORANGE);
		printf("%lli ", current_time(philo));
		printf("%s", NO_COLOR);
		printf("%s", COLOR_LIGHT_CYAN);
		printf("%d ", (philo->id + 1));
		printf("%s", NO_COLOR);
		printf("%s\n", message);
	}
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
