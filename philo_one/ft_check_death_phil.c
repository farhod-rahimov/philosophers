/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death_phil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:59:33 by farhod            #+#    #+#             */
/*   Updated: 2021/04/05 17:16:58 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    *ft_check_death_phil(void *nill)
{
    int i;
    long long int current;

    while (1)
    {
        i = 0;
        current = ft_get_time();
        while (i < data.num_phils)
        {
            if (current - data.start_starving[i] >= data.time_die)
            {
                pthread_mutex_lock(&print_mutex);
                printf("%lld %d died\n", current - data.start_time, i + 1);
                exit(1);
            }
            i++;
        }
    }
    return (nill);
}