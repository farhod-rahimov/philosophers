/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:06:26 by btammara          #+#    #+#             */
/*   Updated: 2021/04/04 18:04:17 by btammara         ###   ########.fr       */
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
	pthread_t	monitor_even;
	pthread_t	monitor_odd;
	int			i;
	int			*n;

	if (argc < 5 || argc > 6)
		ft_error(ARG_ERR);

	/***FT_GET_DATA***/
	ft_get_data(argv);


	/***MUTEX_INIT***/
	pthread_mutex_init(&print_mutex, NULL);

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
	pthread_create(&monitor_even, NULL, ft_monitor_even, NULL);
	pthread_create(&monitor_odd, NULL, ft_monitor_odd, NULL);
	i = 0;
	while (i < data.num_phils)
	{
		pthread_create(&philosophers[i], NULL, ft_work_in_thread, (void *)&(n[i]));
		i++;
	}

	/***PTHREAD_JOIN***/
	pthread_join(monitor_even, NULL);
	pthread_join(monitor_odd, NULL);
	i = 0;
	while (i < data.num_phils)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}

	/***MUTEX_DESTROY***/
	pthread_mutex_destroy(&print_mutex);
	
	/***FREE***/
	free(philosophers);
	free(n);
	free(data.start_starving);
	free(data.should_eat);
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
}

long long int ft_get_time(void)
{
	tv	time;

	gettimeofday(&time, NULL);
	return ((long long int)(time.tv_sec * 1000 + time.tv_usec * 0.001));
}