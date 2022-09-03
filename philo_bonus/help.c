/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:36:06 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 15:36:21 by gcomlan          ###   ########.fr       */
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
