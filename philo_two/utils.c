#include "philo_two.h"

void	ft_print(long long int current, int n, char *str)
{
	ft_putnbr_fd((int)current, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(n + 1, 1);
	ft_putstr_fd(str, 1);
}

long long int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long int)(time.tv_sec * 1000 + time.tv_usec * 0.001));
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_array_create(pthread_t **philosophers, int **n)
{
	int	i;

	*philosophers = (pthread_t *)malloc(sizeof(pthread_t) * g_data.num_phils);
	if (*philosophers == NULL)
		ft_error(MALLOC_ERR);
	*n = (int *)malloc(sizeof(int) * g_data.num_phils);
	if (*n == NULL)
		ft_error(MALLOC_ERR);
	i = 0;
	while (i < g_data.num_phils)
	{
		(*n)[i] = i;
		i++;
	}
}

void	ft_sleep(long long int milliseconds)
{
	long long int	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time <= milliseconds)
		usleep(50);
}
