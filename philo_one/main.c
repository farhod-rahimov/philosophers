/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:06:26 by btammara          #+#    #+#             */
/*   Updated: 2021/04/04 17:32:52 by btammara         ###   ########.fr       */
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
	pthread_t	servant;
	int			i;
	int			*n;

	if (argc < 5 || argc > 6)
		ft_error(ARG_ERR);

	/***FT_GET_DATA***/
	ft_get_data(argv);

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
	pthread_create(&servant, NULL, ft_monitor, NULL);
	i = 0;
	while (i < data.num_phils)
	{
		pthread_create(&philosophers[i], NULL, ft_work_in_thread, (void *)&(n[i]));
		i++;
	}

	/***PTHREAD_JOIN***/
	pthread_join(servant, NULL);
	i = 0;
	while (i < data.num_phils)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}

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