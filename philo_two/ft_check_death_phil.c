/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death_phil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:59:33 by farhod            #+#    #+#             */
/*   Updated: 2021/04/06 11:28:13 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void    *ft_check_death_phil(void *nill)
{
    int i;
    long long int current;

    while (data.num_eat)
    {
        i = 0;
        current = ft_get_time();
        while (i < data.num_phils)
        {
            if (current - data.start_starving[i] >= data.time_die && data.num_eat_phil[i])
            {
                sem_wait(print_sem);
                // pthread_mutex_lock(&print_mutex);
                ft_print(current - data.start_time, i, " died\n");
                exit(1);
            }
            i++;
        }
    }
    return (nill);
}