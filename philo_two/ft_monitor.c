/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:28 by btammara          #+#    #+#             */
/*   Updated: 2021/04/06 11:34:08 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void    *ft_monitor(void *nill)
{
	int i;

	while (data.num_eat)
	{
		i = 0;
		while (i < data.num_phils)
		{
			sem_wait(fork_sem);
			sem_wait(fork_sem);
			data.should_eat[i] = 1;
			i++;
		}
		data.num_eat--;
	}
	return (nill);
}

long long int ft_get_time(void)
{
	tv	time;

	gettimeofday(&time, NULL);
	return ((long long int)(time.tv_sec * 1000 + time.tv_usec * 0.001));
}