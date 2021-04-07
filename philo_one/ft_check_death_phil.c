#include "philo_one.h"

void	*ft_check_death_phil(void *nill)
{
	int				i;
	long long int	current;

	while (g_data.num_eat)
	{
		i = 0;
		current = ft_get_time();
		while (i < g_data.num_phils)
		{
			if (current - g_data.start_starving[i] >= g_data.time_die)
			{
				pthread_mutex_lock(&g_print_mutex);
				ft_print(current - g_data.start_time, i, " died\n");
				exit(1);
			}
			i++;
		}
	}
	return (nill);
}
