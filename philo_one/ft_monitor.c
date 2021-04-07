#include "philo_one.h"

static void	ft_eat_odd_phils(void)
{
	int	i;

	i = 1;
	while (i < g_data.num_phils)
	{
		pthread_mutex_lock(&g_fork_mutex[i]);
		if (i + 1 == g_data.num_phils)
			pthread_mutex_lock(&g_fork_mutex[0]);
		else
			pthread_mutex_lock(&g_fork_mutex[i + 1]);
		g_data.should_eat[i] = 1;
		i += 2;
	}
}

void	*ft_monitor(void *nill)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < g_data.num_phils)
		{
			pthread_mutex_lock(&g_fork_mutex[i]);
			if (i + 1 == g_data.num_phils)
				pthread_mutex_lock(&g_fork_mutex[0]);
			else
				pthread_mutex_lock(&g_fork_mutex[i + 1]);
			g_data.should_eat[i] = 1;
			i += 2;
		}
		ft_eat_odd_phils();
	}
	return (nill);
}
