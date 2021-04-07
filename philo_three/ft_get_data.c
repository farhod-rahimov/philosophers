#include "philo_three.h"

static	void	part_2(void)
{
	g_data.is_sleeping = (int *)malloc(sizeof(int) * g_data.num_phils);
	if (g_data.is_sleeping == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)g_data.is_sleeping, g_data.num_phils * sizeof(int));
	g_data.is_thinking = (int *)malloc(sizeof(int) * g_data.num_phils);
	if (g_data.is_thinking == NULL)
		ft_error(MALLOC_ERR);
	ft_bzero((void *)g_data.is_thinking, g_data.num_phils * sizeof(int));
}

void	ft_get_data(char **argv)
{
	int	flag;

	flag = 0;
	g_data.num_phils = ft_atoi(argv[1]);
	g_data.time_die = ft_atoi(argv[2]);
	g_data.time_eat = ft_atoi(argv[3]);
	g_data.time_sleep = ft_atoi(argv[4]);
	g_data.num_eat = -1;
	if (argv[5])
	{
		g_data.num_eat = ft_atoi(argv[5]);
		flag = 1;
	}
	if (g_data.num_phils < 1)
		ft_error(PHIL_ERR);
	else if (g_data.time_die < 0 || g_data.time_eat < 0 || \
			g_data.time_sleep < 0)
		ft_error(TIME_ERR);
	else if (flag && g_data.num_eat < 0)
		ft_error(EAT_ERR);
	part_2();
}
