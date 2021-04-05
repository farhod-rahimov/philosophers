/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhod <farhod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:28:34 by farhod            #+#    #+#             */
/*   Updated: 2021/04/05 17:42:10 by farhod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    ft_print(long long int current, int n, char *str)
{
    (void)current;
    (void)n;
    (void)str;
    ft_putnbr_fd((int)current, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(n + 1, 1);
    ft_putstr_fd(str, 1);
}