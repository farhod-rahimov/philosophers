/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:28 by btammara          #+#    #+#             */
/*   Updated: 2021/04/07 15:00:28 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void    *ft_monitor(void *nill)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < g_data.num_phils)
		{
			sem_wait(g_fork_sem);
			sem_wait(g_fork_sem);
			g_data.should_eat[i] = 1;
			i++;
		}
	}
	return (nill);
}
