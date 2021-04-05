/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death_phil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:59:33 by farhod            #+#    #+#             */
/*   Updated: 2021/04/05 16:07:27 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    *ft_check_death_phil(void *num)
{
    int n;
    long long int current;

    n = *(int *)num;
    while (1)
    {
        current = ft_get_time();
        if (current - data.start_starving[n] >= data.time_die)
        {
            pthread_mutex_lock(&print_mutex);
            printf("%lld %d died\n", current - data.start_time, n + 1);
            exit(1);
        }
    }
    return (NULL);
}