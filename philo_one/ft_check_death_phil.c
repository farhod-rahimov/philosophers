/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death_phil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:59:33 by farhod            #+#    #+#             */
/*   Updated: 2021/04/07 13:52:52 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
            if (current - data.start_starving[i] >= data.time_die)
            {
                pthread_mutex_lock(&print_mutex);
                ft_print(current - data.start_time, i, " died\n");
                exit(1);
            }
            i++;
        }
    }
    return (nill);
}