/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:06:26 by btammara          #+#    #+#             */
/*   Updated: 2021/04/05 20:02:40 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int main(int argc, char **argv)
{
	pthread_t	*philosophers;
	pthread_t	check_death;
	pthread_t	monitor;
	// pthread_t	monitor_odd;
	int			i;
	int			*n;

	if (argc < 5 || argc > 6)
		ft_error(ARG_ERR);

	/***FT_GET_DATA***/
	ft_get_data(argv);


	/***MUTEX_INIT***/
	pthread_mutex_init(&print_mutex, NULL);
	if ((fork_mutex = (m_t *)malloc(sizeof(m_t) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	i = 0;
	while (i < data.num_phils)
		pthread_mutex_init(&fork_mutex[i++], NULL);

	/***PTHREAD_CREATE***/
	if ((philosophers = (pthread_t *)malloc(sizeof(pthread_t) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	if ((n = (int *)malloc(sizeof(int) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	i = 0;
	while (i < data.num_phils)
	{
		n[i] = i;
		i++;
	}
	data.start_time = ft_get_time();
	pthread_create(&monitor, NULL, ft_monitor, NULL);
	i = 0;
	while (i < data.num_phils)
	{
		pthread_create(&philosophers[i], NULL, ft_work_in_thread, (void *)&(n[i]));
		i++;
	}
	usleep(data.time_eat / 2);
	pthread_create(&check_death, NULL, ft_check_death_phil, NULL);
	/***PTHREAD_JOIN***/
	// pthread_join(monitor, NULL);
	// pthread_join(check_death, NULL);
	i = 0;
	while (i < data.num_phils)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}

	// /***MUTEX_DESTROY***/
	// pthread_mutex_destroy(&print_mutex);
	// i = 0;
	// while (i < data.num_phils)
	// 	pthread_mutex_destroy(&fork_mutex[i]);
	printf("hahaha %lld\n", ft_get_time() - data.start_time);
	
	/***FREE***/
	// free(philosophers);
	// free(n);
	// free(fork_mutex);
	// free(data.start_starving);
	// free(data.should_eat);
	// free(data.is_sleeping);
	// free(data.is_thinking);
	return (0);
}

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

long long int ft_get_time(void)
{
	tv	time;

	gettimeofday(&time, NULL);
	return ((long long int)(time.tv_sec * 1000 + time.tv_usec * 0.001));
}