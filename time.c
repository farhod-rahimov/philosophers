/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btammara <btammara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 09:36:35 by btammara          #+#    #+#             */
/*   Updated: 2021/04/01 10:30:06 by btammara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

// typedef struct	timeval
// {
// 	time_t		tv_sec;   /* seconds since Jan. 1, 1970 */
// 	suseconds_t	tv_usec;  /* and microseconds */
// }t_timeval;

// typedef struct	timezone
// {
// 	int	tz_minuteswest; /* of Greenwich */
// 	int	tz_dsttime;     /* type of dst correction to apply */
// }t_timezone;


int main(void)
{
	struct timeval	tv0, tv1;

	gettimeofday(&tv0, NULL);
	while (1)
	{
		gettimeofday(&tv1, NULL);
		// printf("%ld\n", tv1.tv_sec);
		// printf("%d\n", tv1.tv_usec - tv0.tv_usec);
		printf("%d\n", (int)((tv1.tv_sec * 1000 + tv1.tv_usec * 0.001) - (tv0.tv_sec * 1000 + tv0.tv_usec * 0.001)));
		// printf("%ld\n", ((tv1.tv_sec - tv0.tv_sec) * 1000) + tv1.tv_usec - tv0.tv_usec);
		usleep(1234567);
	}
}