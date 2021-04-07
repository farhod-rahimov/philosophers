#include "philo_two.h"

void	*ft_monitor(void *nill)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < g_data.num_phils)
		{
			sem_wait(g_fork_sem);
			sem_wait(g_fork_sem);
			g_data.should_eat[i] = 1;
			i++;
		}
	}
	return (nill);
}
