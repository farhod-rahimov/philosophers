/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:28:34 by farhod            #+#    #+#             */
/*   Updated: 2021/04/07 14:15:30 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    ft_print(long long int current, int n, char *str)
{
    ft_putnbr_fd((int)current, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(n + 1, 1);
    ft_putstr_fd(str, 1);
}

long long int ft_get_time(void)
{
	tv	time;

	gettimeofday(&time, NULL);
	return ((long long int)(time.tv_sec * 1000 + time.tv_usec * 0.001));
}