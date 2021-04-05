/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:28 by btammara          #+#    #+#             */
/*   Updated: 2021/04/05 19:28:18 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    *ft_monitor(void *nill)
{
	int i;

	while (data.num_eat)
	{
		i = 0;
		// printf("another inf %d\n", data.num_eat);
		while (i < data.num_phils)
		{
			pthread_mutex_lock(&fork_mutex[i]);
			if (i + 1 == data.num_phils)
				pthread_mutex_lock(&fork_mutex[0]);
			else
				pthread_mutex_lock(&fork_mutex[i + 1]);
			data.should_eat[i] = 1;
			i += 2;
		}
		i = 1;
		while (i < data.num_phils)
		{
			pthread_mutex_lock(&fork_mutex[i]);
			if (i + 1 == data.num_phils)
				pthread_mutex_lock(&fork_mutex[0]);
			else
				pthread_mutex_lock(&fork_mutex[i + 1]);
			data.should_eat[i] = 1;
			i += 2;
		}
		data.num_eat--;
	}
	return (nill);
}
