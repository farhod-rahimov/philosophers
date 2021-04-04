/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_in_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:37 by btammara          #+#    #+#             */
/*   Updated: 2021/04/04 17:52:10 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ft_work_in_thread(void *n)
{
	tv	time;
	long long int current;
	
	data.start_starving[*(int *)n] = ft_get_time();
	while (1)
	{
		if (data.should_eat[*(int *)n])
		{
			current = ft_get_time();
			pthread_mutex_lock(&print_mutex);
			printf("%lld %d has taken a fork\n", current - data.start_time, n);
			printf("%lld %d has taken a fork\n", current - data.start_time, n);
			pthread_mutex_unlock(&print_mutex);
			
			ft_eat_phil(*(int *)n, current);
		}
	}
	return (NULL);
}

void    ft_eat_phil(int n, long long int current)
{
	pthread_mutex_lock(&print_mutex);
	printf("%lld %d is eating\n", current - data.start_time, n);
	pthread_mutex_unlock(&print_mutex);
	usleep(data.time_eat * 1000);
	
	return (ft_sleep_phil(n, current + data.time_eat));
}

void    ft_sleep_phil(int n, long long int current)
{
	pthread_mutex_lock(&print_mutex);
	printf("%lld %d is sleeping\n", current - data.start_time, n);
	pthread_mutex_unlock(&print_mutex);
	usleep(data.time_sleep * 1000);
	
	return (ft_sleep_phil(n, current + data.time_sleep));
}

void    ft_think_phil(int n, long long int current)
{
	pthread_mutex_lock(&print_mutex);
	printf("%lld %d is thinking\n", current - data.start_time, n);
	pthread_mutex_unlock(&print_mutex);
}