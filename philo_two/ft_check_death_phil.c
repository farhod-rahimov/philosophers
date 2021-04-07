#include "philo_two.h"

void	*ft_check_death_phil(void *nill)
{
	int				i;
	long long int	current;

	while (1)
	{
		i = 0;
		current = ft_get_time();
		while (i < g_data.num_phils)
		{
			if (current - g_data.start_starving[i] >= g_data.time_die)
			{
				sem_wait(g_print_sem);
				ft_print(current - g_data.start_time, i, " died\n");
				exit(1);
			}
			i++;
		}
	}
	return (nill);
}
