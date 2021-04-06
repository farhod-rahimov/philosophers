/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_in_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:37 by btammara          #+#    #+#             */
/*   Updated: 2021/04/06 19:36:59 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*ft_work_in_thread(void *n)
{
	long long int current;
	
	data.start_starving[*(int *)n] = ft_get_time();
	while (data.num_eat_phil[*(int *)n])
	{
		if (!data.is_sleeping[*(int *)n] && !data.is_thinking[*(int *)n])
		{
			sem_wait(fork_sem);
			sem_wait(fork_sem);
			current = ft_get_time();
			sem_wait(print_sem);
			ft_print(current - data.start_time, *(int *)n, " has taken a fork\n");
			ft_print(current - data.start_time, *(int *)n, " has taken a fork\n");
			sem_post(print_sem);
			
			ft_eat_phil(*(int *)n, current);
		}
	}
	exit(0);
	return (NULL);
}

void    ft_eat_phil(int n, long long int current)
{
	current = ft_get_time();
	data.start_starving[n] = current;
	sem_wait(print_sem);
	ft_print(current - data.start_time, n, " is eating\n");
	sem_post(print_sem);
	// ft_sleep(data.time_eat);
	usleep(data.time_eat * 1000);
	sem_post(fork_sem);
	sem_post(fork_sem);
	if (--data.num_eat_phil[n] == 0)
		return ;
	return (ft_sleep_phil(n, current + data.time_eat));
}

void    ft_sleep_phil(int n, long long int current)
{
	current = ft_get_time();
	data.is_sleeping[n] = 1;
	sem_wait(print_sem);
	ft_print(current - data.start_time, n, " is sleeping\n");
	sem_post(print_sem);
	usleep(data.time_sleep * 1000);
	// ft_sleep(data.time_sleep);
	data.is_sleeping[n] = 0;
	return (ft_think_phil(n, current + data.time_sleep));
}

void    ft_think_phil(int n, long long int current)
{
	current = ft_get_time();
	data.is_thinking[n] = 1;
	sem_wait(print_sem);
	ft_print(current - data.start_time, n, " is thinking\n");
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