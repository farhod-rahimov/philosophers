/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death_phil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:59:33 by farhod            #+#    #+#             */
/*   Updated: 2021/04/06 14:09:54 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void    *ft_check_death_phil(void *n)
{
    int i;
    long long int current;

    i = *(int *)n;
    while (data.num_eat)
    {
        current = ft_get_time();
        if (current - data.start_starving[i] >= data.time_die && data.num_eat_phil[i])
        {
            sem_wait(print_sem);
            ft_print(current - data.start_time, i, " died\n");
            exit(1);
        }
    }
    return (NULL);
}