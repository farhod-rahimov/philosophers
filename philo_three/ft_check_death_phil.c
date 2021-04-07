/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death_phil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:59:33 by farhod            #+#    #+#             */
/*   Updated: 2021/04/07 14:20:11 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void    *ft_check_death_phil(void *n)
{
    long long int current;

    while (1)
    {
        current = ft_get_time();
        if (current - data.start_starving >= data.time_die)
        {
            sem_wait(print_sem);
            ft_print(current - data.start_time, *(int *)n, " died");
            kill(0, 2);
        }
    }
    return (NULL);
}