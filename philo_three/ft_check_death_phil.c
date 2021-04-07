#include "philo_three.h"

void	*ft_check_death_phil(void *n)
{
	long long int	current;

	while (1)
	{
		current = ft_get_time();
		if (current - g_data.start_starving >= g_data.time_die)
		{
			sem_wait(g_print_sem);
			ft_print(current - g_data.start_time, *(int *)n, " died\n");
			kill(0, SIGKILL);
		}
	}
	return (NULL);
}
