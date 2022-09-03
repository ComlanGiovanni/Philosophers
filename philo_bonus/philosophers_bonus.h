/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:54:45 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/03 15:36:44 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

// check and add all fct in front in philo .h too
# include <string.h>
# include <stdio.h>
# include <signal.h>

/*Color*/

# define COLOR_BLACK			"\033[0;30m"
# define COLOR_RED				"\033[0;31m"
# define COLOR_GREEN			"\033[0;32m"
# define COLOR_ORANGE			"\033[0;33m"
# define COLOR_BLUE				"\033[0;34m"
# define COLOR_PURPLE			"\033[0;35m"
# define COLOR_CYAN				"\033[0;36m"
# define COLOR_LIGHT_GRAY		"\033[0;37m"
# define COLOR_DARK_GRAY		"\033[1;30m"
# define COLOR_LIGHT_RED		"\033[1;31m"
# define COLOR_LIGHT_GREEN		"\033[1;32m"
# define COLOR_YELLOW			"\033[1;33m"
# define COLOR_LIGHT_BLUE		"\033[1;34m"
# define COLOR_LIGHT_PURPLE		"\033[1;35m"
# define COLOR_LIGHT_CYAN		"\033[1;36m"
# define COLOR_WHITE			"\033[1;37m"
# define NO_COLOR				"\033[0m"

/*Define message etc*/

# define ERROR_MSG			"Error ->"
# define USAGE				"Usage :"
# define PROGRAM_NAME		"./philo"
# define ARGC_NBR_PHILO		"[number_of_philosophers]"
# define ARGC_DIE_TIME		"[time_to_die]"
# define ARGC_EAT_TIME		"[time_to_eat]"
# define ARGC_SLEEP_TIME	"[time_to_sleep]"
# define ARGC_TIMES_EAT		"(number_of_times_each_philosopher_must_eat)"
# define ERROR_NBR_INF_0	"should be > 0"

//delete
# define ERROR_MUTEX_LOCK	"pthread_mutex_init (info->lock) fail !"
# define ERROR_MALLOC_FORK	"malloc pthread_mutex_t *forks fail !"
# define ERROR_MUTEX_FORK	"pthread_mutex_init (info->fork) fail !"
# define ERROR_MALLOC_PHILO	"malloc philosophers fail !"
# define ERROR_START_PHILO	"pthread_create Philosophers fail !"

# define ERROR_NEGATIVE_ARG	"Negative number found in argument !"
# define TAKE_FORK			"has taken a fork"
# define EAT				"is eating"
# define SLEEP				"is sleeping"
# define THINK				"is thinking"
# define DIE				"died"

// true false enum for loop if etc # include <sys/types.h>
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_philosophers
{
	int					id;
	int					die; // bool
	struct s_info		*info;
	int					eat_count;
	long long			last_eat;
}					t_philosophers;

typedef struct s_info
{
	int				*id;
	sem_t			*forks;
	int				die_time;
	int				eat_time;
	int				nbr_philo;
	int				sleep_time;
	int				nbr_to_eat;
	long long		creation_time;
}				t_information;

//	action_bonus.c
void	philo_take_fork(t_philosophers *philo);
void	philo_eating(t_philosophers *philo);
void	philo_put_down_forks(t_philosophers *philo);
void	philo_sleep_and_think(t_philosophers *philo);

//	initialisation_bonus.c
void	init_info_with_arg(t_information *info, int argc, char **argv);

//	threads_bonus.c


//	utilities_bonus.c
int	ft_atoi(char *str)
void	*ft_calloc(size_t nmemb, size_t size);

//	help.c
void		print_error_msg(char *message);
void		print_usage(void);

#endif
