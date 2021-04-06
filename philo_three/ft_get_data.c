/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:41:52 by farhod            #+#    #+#             */
/*   Updated: 2021/04/06 11:45:59 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_get_data(char **argv)
{
	if ((data.num_phils = ft_atoi(argv[1])) < 1)
		ft_error(PHIL_ERR);
	if ((data.time_die = ft_atoi(argv[2])) < 0)
		ft_error(TIME_ERR);
	if ((data.time_eat = ft_atoi(argv[3])) < 0)
		ft_error(TIME_ERR);
	if ((data.time_sleep = ft_atoi(argv[4])) < 0)
		ft_error(TIME_ERR);
	data.num_eat = -1;
	if (argv[5] && (data.num_eat = ft_atoi(argv[5])) < 0)
		ft_error(EAT_ERR);

	if ((data.start_starving = (long long int *)malloc(sizeof(long long int) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);

	if ((data.should_eat = (int *)malloc(sizeof(int) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)data.should_eat, data.num_phils * sizeof(int));
	
	if ((data.is_sleeping = (int *)malloc(sizeof(int) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)data.is_sleeping, data.num_phils * sizeof(int));
	
	if ((data.is_thinking = (int *)malloc(sizeof(int) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)data.is_thinking, data.num_phils * sizeof(int));
	
	if ((data.num_eat_phil = (int *)malloc(sizeof(int) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	int i;
	i = 0;
	while (i < data.num_phils)
		data.num_eat_phil[i++] = data.num_eat;
}