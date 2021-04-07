#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdlib.h>

# define ARG_ERR "Error. The number of arguments should be 4 or 5\n"
# define PHIL_ERR "Error. The number of philosophers should be greater than 1\n"
# define TIME_ERR "Error. Time cannot be negative\n"
# define EAT_ERR "Error. The number of times each philosopher must eat \
cannot be negative\n"
# define MALLOC_ERR "Error. Cannot allocate memmory\n"
# define SEM_ERR "Error. Cannot create semaphore\n"

typedef struct s_struct
{
	long long int	start_time;

	long long int	start_starving;
	int				num_phils;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;

	int				*is_sleeping;
	int				*is_thinking;
}	t_data;

typedef struct s_thread
{
	pthread_t		philosopher;
	pthread_t		check_death;
}	t_thread;

sem_t	*g_fork_sem;
sem_t	*g_print_sem;
t_data	g_data;

/******************MINI_LIBFT******************/
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);

/*******************UTILS.C********************/
void			ft_print(long long int current, int n, char *str);
long long int	ft_get_time(void);
void			ft_error(char *str);
void			ft_array_create(int **n);
void			ft_sleep(long long int milliseconds);

/********************MAIN.C********************/
void			ft_mutex_init(void);
void			ft_threads_create(t_thread *threads);

/****************FT_GET_DATA.C*****************/
void			ft_get_data(char **argv);

/****************FT_WORK_PHIL.C****************/
void			*ft_work_phil(void *n);
void			ft_eat_phil(int n, long long int current);
void			ft_sleep_phil(int n, long long int current);
void			ft_think_phil(int n, long long int current);

/***************FT_CHECK_DEATH.C***************/
void			*ft_check_death_phil(void *n);

#endif