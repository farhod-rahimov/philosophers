/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_in_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:37 by btammara          #+#    #+#             */
/*   Updated: 2021/04/06 11:32:37 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*ft_work_in_thread(void *n)
{
	long long int current;
	
	data.start_starving[*(int *)n] = ft_get_time();
	while (data.num_eat_phil[*(int *)n])
	{
		if (data.should_eat[*(int *)n] == 1 && !data.is_sleeping[*(int *)n] && !data.is_thinking[*(int *)n])
		{
			current = ft_get_time();
			sem_wait(print_sem);
			// pthread_mutex_lock(&print_mutex);
			ft_print(current - data.start_time, *(int *)n, " has taken a fork\n");
			ft_print(current - data.start_time, *(int *)n, " has taken a fork\n");
			// pthread_mutex_unlock(&print_mutex);
			sem_post(print_sem);
			
			ft_eat_phil(*(int *)n, current);
		}
	}
	return (NULL);
}

void    ft_eat_phil(int n, long long int current)
{
	data.start_starving[n] = current;
	sem_wait(print_sem);
	// pthread_mutex_lock(&print_mutex);
	ft_print(current - data.start_time, n, " is eating\n");
	// pthread_mutex_unlock(&print_mutex);
	sem_post(print_sem);
	ft_sleep(data.time_eat);
	sem_post(fork_sem);
	sem_post(fork_sem);
	// pthread_mutex_unlock(&fork_mutex[n]);
	// if (n + 1 == data.num_phils)
	// 	pthread_mutex_unlock(&fork_mutex[0]);
	// else
	// 	pthread_mutex_unlock(&fork_mutex[n + 1]);
	if (--data.num_eat_phil[n] == 0)
		return ;
	data.should_eat[n] = 2;
	return (ft_sleep_phil(n, current + data.time_eat));
}

void    ft_sleep_phil(int n, long long int current)
{
	data.is_sleeping[n] = 1;
	sem_wait(print_sem);
	// pthread_mutex_lock(&print_mutex);
	ft_print(current - data.start_time, n, " is sleeping\n");
	// pthread_mutex_unlock(&print_mutex);
	sem_post(print_sem);
	ft_sleep(data.time_sleep);
	data.is_sleeping[n] = 0;
	return (ft_think_phil(n, current + data.time_sleep));
}

void    ft_think_phil(int n, long long int current)
{
	data.is_thinking[n] = 1;
	sem_wait(print_sem);
	// pthread_mutex_lock(&print_mutex);
	ft_print(current - data.start_time, n, " is thinking\n");
	// pthread_mutex_unlock(&print_mutex);
	sem_post(print_sem);
	data.is_thinking[n] = 0;
}

void	ft_sleep(long long int milliseconds)
{
	long long int start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time <= milliseconds)
		;
}