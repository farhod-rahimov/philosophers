#include "philo_one.h"

int	main(int argc, char **argv)
{
	t_thread	threads;

	if (argc < 5 || argc > 6)
		ft_error(ARG_ERR);
	ft_get_data(argv);
	ft_mutex_init();
	ft_threads_create(&threads);
	return (0);
}

void	ft_mutex_init(void)
{
	int	i;

	i = 0;
	g_fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			g_data.num_phils);
	if (g_fork_mutex == NULL)
		ft_error(MALLOC_ERR);
	i = 0;
	while (i < g_data.num_phils)
		pthread_mutex_init(&g_fork_mutex[i++], NULL);
	pthread_mutex_init(&g_print_mutex, NULL);
}

void	ft_threads_create(t_thread *threads)
{
	int	*n;
	int	i;

	ft_array_create(&threads->philosophers, &n);
	g_data.start_time = ft_get_time();
	pthread_create(&threads->monitor, NULL, ft_monitor, NULL);
	i = 0;
	while (i < g_data.num_phils)
	{
		pthread_create(&threads->philosophers[i], NULL, \
				ft_work_in_thread, (void *)&(n[i]));
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
