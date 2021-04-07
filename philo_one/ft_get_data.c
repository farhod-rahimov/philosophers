/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:41:52 by farhod            #+#    #+#             */
/*   Updated: 2021/04/07 15:00:28 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_get_data(char **argv)
{
	if ((g_data.num_phils = ft_atoi(argv[1])) < 1)
		ft_error(PHIL_ERR);
	if ((g_data.time_die = ft_atoi(argv[2])) < 0)
		ft_error(TIME_ERR);
	if ((g_data.time_eat = ft_atoi(argv[3])) < 0)
		ft_error(TIME_ERR);
	if ((g_data.time_sleep = ft_atoi(argv[4])) < 0)
		ft_error(TIME_ERR);
	g_data.num_eat = -1;
	if (argv[5] && (g_data.num_eat = ft_atoi(argv[5])) < 0)
		ft_error(EAT_ERR);
	g_data.total_num_eat = g_data.num_eat * g_data.num_phils;

	if ((g_data.start_starving = (long long int *)malloc(sizeof(long long int) * g_data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);

	if ((g_data.should_eat = (int *)malloc(sizeof(int) * g_data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)g_data.should_eat, g_data.num_phils * sizeof(int));
	
	if ((g_data.is_sleeping = (int *)malloc(sizeof(int) * g_data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)g_data.is_sleeping, g_data.num_phils * sizeof(int));
	
	if ((g_data.is_thinking = (int *)malloc(sizeof(int) * g_data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)g_data.is_thinking, g_data.num_phils * sizeof(int));
}