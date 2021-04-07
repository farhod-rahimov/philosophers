/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_in_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:37 by btammara          #+#    #+#             */
/*   Updated: 2021/04/07 13:51:1 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ft_work_in_thread(void *n)
{
	long long int current;
	
	g_data.start_starving[*(int *)n] = ft_get_time();
	while (1)
	{
		if (g_data.should_eat[*(int *)n] == 1 && !g_data.is_sleeping[*(int *)n] && !g_data.is_thinking[*(int *)n])
		{
			current = ft_get_time();
			pthread_mutex_lock(&g_print_mutex);
			ft_print(current - g_data.start_time, *(int *)n, " has taken a fork\n");
			ft_print(current - g_data.start_time, *(int *)n, " has taken a fork\n");
			pthread_mutex_unlock(&g_print_mutex);
			
			ft_eat_phil(*(int *)n, current);
		}
	}
	return (NULL);
}

void    ft_eat_phil(int n, long long int current)
{
	g_data.start_starving[n] = current;
	pthread_mutex_lock(&g_print_mutex);
	ft_print(current - g_data.start_time, n, " is eating\n");
	pthread_mutex_unlock(&g_print_mutex);
	ft_sleep(g_data.time_eat);
	pthread_mutex_unlock(&g_fork_mutex[n]);
	if (n + 1 == g_data.num_phils)
		pthread_mutex_unlock(&g_fork_mutex[0]);
	else
		pthread_mutex_unlock(&g_fork_mutex[n + 1]);
	if (--g_data.total_num_eat <= 0 && g_data.num_eat != -1)
	{
		pthread_mutex_lock(&g_print_mutex);
		exit(0);
	}
	g_data.should_eat[n] = 2;
	return (ft_sleep_phil(n, current + g_data.time_eat));
}

void    ft_sleep_phil(int n, long long int current)
{
	g_data.is_sleeping[n] = 1;
	pthread_mutex_lock(&g_print_mutex);
	ft_print(current - g_data.start_time, n, " is sleeping\n");
	pthread_mutex_unlock(&g_print_mutex);
	ft_sleep(g_data.time_sleep);
	g_data.is_sleeping[n] = 0;
	return (ft_think_phil(n, current + g_data.time_sleep));
}

void    ft_think_phil(int n, long long int current)
{
	g_data.is_thinking[n] = 1;
	pthread_mutex_lock(&g_print_mutex);
	ft_print(current - g_data.start_time, n, " is thinking\n");
	pthread_mutex_unlock(&g_print_mutex);
	g_data.is_thinking[n] = 0;
}

void	ft_sleep(long long int milliseconds)
{
	long long int start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time <= milliseconds)
		usleep(50);
}