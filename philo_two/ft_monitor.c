/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:28 by btammara          #+#    #+#             */
/*   Updated: 2021/04/07 14:28:29 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void    *ft_monitor(void *nill)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < data.num_phils)
		{
			sem_wait(fork_sem);
			sem_wait(fork_sem);
			data.should_eat[i] = 1;
			i++;
		}
	}
	return (nill);
}
