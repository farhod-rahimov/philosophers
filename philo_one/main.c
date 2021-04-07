/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:06:26 by btammara          #+#    #+#             */
/*   Updated: 2021/04/07 15:43:18 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
void	ft_mutex_init(void);
void	ft_threads_create(t_thread *threads);
void	ft_array_create(pthread_t **philosophers, int **n);

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int main(int argc, char **argv)
{
	t_thread threads;

	if (argc < 5 || argc > 6)
		ft_error(ARG_ERR);
	ft_get_data(argv);
	ft_mutex_init();
	ft_threads_create(&threads);	
	return (0);
}

void	ft_mutex_init(void)
{
	int i;

	i = 0;
	if ((g_fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * g_data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	i = 0;
	while (i < g_data.num_phils)
		pthread_mutex_init(&g_fork_mutex[i++], NULL);
	pthread_mutex_init(&g_print_mutex, NULL);
}

void	ft_threads_create(t_thread *threads)
{
	int			*n;
	int			i;
	
	ft_array_create(&threads->philosophers, &n);
	g_data.start_time = ft_get_time();
	pthread_create(&threads->monitor, NULL, ft_monitor, NULL);
	i = 0;
	while (i < g_data.num_phils)
	{
		pthread_create(&threads->philosophers[i], NULL, ft_work_in_thread, (void *)&(n[i]));
		i++;
	}
	usleep(g_data.time_eat / 2);
	pthread_create(&threads->check_death, NULL, ft_check_death_phil, NULL);
	i = 0;
	while (i < g_data.num_phils)
	{
		pthread_join(threads->philosophers[i], NULL);
		i++;
	}
}

void	ft_array_create(pthread_t **philosophers, int **n)
{
	int i;
	
	if ((*philosophers = (pthread_t *)malloc(sizeof(pthread_t) * g_data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	if ((*n = (int *)malloc(sizeof(int) * g_data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	i = 0;
	while (i < g_data.num_phils)
	{
		(*n)[i] = i;
		i++;
	}
}