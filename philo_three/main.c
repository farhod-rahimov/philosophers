/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:06:26 by btammara          #+#    #+#             */
/*   Updated: 2021/04/06 19:41:08 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
void	ft_semaphore_init(void);
void	ft_process_create(t_thread *threads);
void	ft_array_create(int **n);

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int main(int argc, char **argv)
{
	t_thread threads;

	if (argc < 5 || argc > 6)
		ft_error(ARG_ERR);
	ft_get_data(argv);
	ft_semaphore_init();
	ft_process_create(&threads);	
	return (0);
}

void	ft_semaphore_init(void)
{
	sem_unlink("print_sem");
	sem_unlink("fork_sem");
	if ((fork_sem = sem_open("fork_sem", O_CREAT, 0666, data.num_phils)) == SEM_FAILED)
		ft_error(SEM_ERR);
	if ((print_sem = sem_open("print_sem", O_CREAT, 0666, 1)) == SEM_FAILED)
		ft_error(SEM_ERR);
}

void	ft_process_create(t_thread *threads)
{
	(void)threads;
	int			*n;
	int			i;
	pid_t		pid;
	int			status;
	
	ft_array_create(&n);
	i = 0;
	// pthread_create(&threads->monitor, NULL, ft_monitor, NULL);
	data.start_time = ft_get_time();
	while (i < data.num_phils)
	{
		if ((pid = fork()) == 0)
		{
			ft_work_in_thread((void *)&n[i]);
			usleep(data.time_eat / 2);
			pthread_create(&threads->check_death, NULL, ft_check_death_phil, (void *)&n[i]);
			pthread_join(threads->check_death, NULL);
			exit(0);
		}
		// usleep(150);
		i++;
	}
	waitpid(pid, &status, 0);
}

void	ft_array_create(int **n)
{
	int i;
	
	if ((*n = (int *)malloc(sizeof(int) * data.num_phils)) == NULL)
		ft_error(MALLOC_ERR);
	i = 0;
	while (i < data.num_phils)
	{
		(*n)[i] = i;
		i++;
	}
}