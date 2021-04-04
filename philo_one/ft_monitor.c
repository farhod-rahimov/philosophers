/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:28 by btammara          #+#    #+#             */
/*   Updated: 2021/04/04 18:06:12 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    ft_monitor_even(void *nill)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < data.num_phils)
		{
			if (i + 1 == data.num_phils)
			{
				if (data.should_eat[0] == 2)
					data.should_eat[i] = 1;
			}
			else if (data.should_eat[i] == 2 || data.should_eat[i] == 0)
				data.should_eat[i] = 1;
			i += 2;
		}	
	}	
	return (nill);
}

void    *ft_monitor_odd(void *nill)
{
	return (nill);
}