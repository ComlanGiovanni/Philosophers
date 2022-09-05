/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:54:41 by gcomlan           #+#    #+#             */
/*   Updated: 2022/09/05 14:15:09 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_information	*info;

	if (argc != 5 && argc != 6)
		print_usage();
	info = ft_calloc(1, sizeof(*info));
	if (!info)
		print_error_msg(ERROR_CALLOC_INFO);
	init_info_with_arg(info, argc, argv);
	init_semaphore(info);
	start_philo(info);
	free_all(info);
	return (EXIT_SUCCESS);
}
