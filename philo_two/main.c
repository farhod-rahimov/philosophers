#include "philo_two.h"

int	main(int argc, char **argv)
{
	t_thread	threads;

	if (argc < 5 || argc > 6)
		ft_error(ARG_ERR);
	ft_get_data(argv);
	ft_semaphores_init();
	ft_threads_create(&threads);
	return (0);
}

void	ft_semaphores_init(void)
{
	sem_unlink("/g_print_sem");
	sem_unlink("/g_fork_sem");
	g_fork_sem = sem_open("/g_fork_sem", O_CREAT, 0666, g_data.num_phils);
	if (g_fork_sem == SEM_FAILED)
		ft_error(SEM_ERR);
	g_print_sem = sem_open("/g_print_sem", O_CREAT, 0666, 1);
	if (g_print_sem == SEM_FAILED)
		ft_error(SEM_ERR);
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
