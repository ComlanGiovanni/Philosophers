/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:36:06 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/05 15:01:56 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	//printf("%lli\t%i\t%s\n", current_time(philo), (philo->id + 1), message);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0' && s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}
