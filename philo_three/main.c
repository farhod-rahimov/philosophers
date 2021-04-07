#include "philo_three.h"

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
	int			status;
	pid_t		pid;

	ft_array_create(&n);
	i = 0;
	g_data.start_time = ft_get_time();
	while (i < g_data.num_phils)
	{
		pid = fork();
		if (pid == 0)
		{
			pthread_create(&threads->check_death, NULL, \
				ft_check_death_phil, (void *)&n[i]);
			ft_work_phil((void *)&n[i]);
			pthread_join(threads->check_death, NULL);
			exit(0);
		}
		i++;
	}
	waitpid(pid, &status, 0);
}
