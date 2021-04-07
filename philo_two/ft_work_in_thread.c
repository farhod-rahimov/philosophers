#include "philo_two.h"

void	*ft_work_in_thread(void *n)
{
	long long int	current;

	g_data.start_starving[*(int *)n] = ft_get_time();
	while (1)
	{
		if (g_data.should_eat[*(int *)n] == 1 && !g_data.is_sleeping[*(int *)n] && \
			!g_data.is_thinking[*(int *)n])
		{
			current = ft_get_time();
			sem_wait(g_print_sem);
			ft_print(current - g_data.start_time, *(int *)n, \
						" has taken a fork\n");
			ft_print(current - g_data.start_time, *(int *)n, \
						" has taken a fork\n");
			sem_post(g_print_sem);
			ft_eat_phil(*(int *)n, current);
		}
	}
	return (NULL);
}

void	ft_eat_phil(int n, long long int current)
{
	g_data.start_starving[n] = current;
	sem_wait(g_print_sem);
	ft_print(current - g_data.start_time, n, " is eating\n");
	sem_post(g_print_sem);
	ft_sleep(g_data.time_eat);
	sem_post(g_fork_sem);
	sem_post(g_fork_sem);
	if (--g_data.total_num_eat <= 0 && g_data.num_eat != -1)
	{
		sem_wait(g_print_sem);
		exit(0);
	}
	g_data.should_eat[n] = 2;
	return (ft_sleep_phil(n, current + g_data.time_eat));
}

void	ft_sleep_phil(int n, long long int current)
{
	g_data.is_sleeping[n] = 1;
	sem_wait(g_print_sem);
	ft_print(current - g_data.start_time, n, " is sleeping\n");
	sem_post(g_print_sem);
	ft_sleep(g_data.time_sleep);
	g_data.is_sleeping[n] = 0;
	return (ft_think_phil(n, current + g_data.time_sleep));
}

void	ft_think_phil(int n, long long int current)
{
	g_data.is_thinking[n] = 1;
	sem_wait(g_print_sem);
	ft_print(current - g_data.start_time, n, " is thinking\n");
	sem_post(g_print_sem);
	g_data.is_thinking[n] = 0;
}
