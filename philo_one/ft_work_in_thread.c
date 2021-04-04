/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_in_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:30:37 by btammara          #+#    #+#             */
/*   Updated: 2021/04/04 17:33:43 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ft_work_in_thread(void *n)
{
    printf("this is THREAD %d\n", *(int *)n);
    return (NULL);
}