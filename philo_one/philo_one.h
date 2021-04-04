/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:07:17 by btammara          #+#    #+#             */
/*   Updated: 2021/04/04 17:32:26 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../liba/libft.h"

# define ARG_ERR "Error. The number of arguments should be 4 or 5\n"
# define PHIL_ERR "Error. The number of philosophers should be greater than 1\n"
# define TIME_ERR "Error. Time cannot be negative\n"
# define EAT_ERR "Error. The number of times each philosopher must eat cannot be negative\n"
# define MALLOC_ERR "Error. Cannot allocate memmory\n"

typedef struct timeval	tv;
typedef pthread_mutex_t	m_t;

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
	
    int				*should_eat;
}	t_data;

m_t		*fork_mutex;
m_t		print_mutex;
t_data	data;

void	ft_get_data(char **argv);
void	*ft_monitor(void *nil);
void	*ft_work_in_thread(void *n);

// 4 410 200 200
// 4 410 200 200 7
// 4 410 200 200 10
// 4 410 200 200 10
// 4 410 200 200 12
// 4 410 200 200 15

// 2 60 60 60
// 10 410 200 200