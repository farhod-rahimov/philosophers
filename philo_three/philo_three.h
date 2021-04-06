/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:07:17 by btammara          #+#    #+#             */
/*   Updated: 2021/04/06 11:35:27 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include "../liba/libft.h"

# define ARG_ERR "Error. The number of arguments should be 4 or 5\n"
# define PHIL_ERR "Error. The number of philosophers should be greater than 1\n"
# define TIME_ERR "Error. Time cannot be negative\n"
# define EAT_ERR "Error. The number of times each philosopher must eat cannot be negative\n"
# define MALLOC_ERR "Error. Cannot allocate memmory\n"
# define SEM_ERR "Error. Cannot create semaphore\n"

typedef struct timeval	tv;

// time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
// suseconds_t  tv_usec;

typedef struct s_struct
{
	long long int	start_time;
	
	long long int	*start_starving;
	int				num_phils;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	
	int				*num_eat_phil;
    int				*should_eat;
	int				*is_sleeping;
	int				*is_thinking;
}	t_data;

typedef struct s_thread
{
	pthread_t philosopher;
	// pthread_t monitor;
	pthread_t check_death;
} t_thread;

sem_t	*fork_sem;
sem_t	*print_sem;
t_data	data;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

void	ft_error(char *str);

long long int	ft_get_time(void);
void			ft_get_data(char **argv);

void			*ft_work_phil(void *n);
void    		ft_eat_phil(int n, long long int current);
void    		ft_sleep_phil(int n, long long int current);
void    		ft_think_phil(int n, long long int current);
void			ft_print(long long int current, int n, char *str);

void			*ft_monitor(void *nil);
void    		*ft_check_death_phil(void *n);
void			ft_sleep(long long int milliseconds);
// 4 410 200 200
// 4 410 200 200 7
// 4 410 200 200 10
// 4 410 200 200 10
// 4 410 200 200 12
// 4 410 200 200 15

// 2 60 60 60
// 10 410 200 200