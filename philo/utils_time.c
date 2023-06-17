/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:00:08 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 13:37:10 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_GETTIME - retrieves current time in miliseconds.
 */
uint64_t	ft_gettime(void)
{
	uint64_t		time_ms;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000);
	return (time_ms);
}

/* 
FT_USLEEP - recoded usleep using uint64_t for more precission.
Same as usleep, it takes time in microseconds.
 */
int	ft_usleep(uint64_t time)
{
	uint64_t	start;

	start = ft_gettime();
	while ((ft_gettime() - start) < time)
		usleep(time / 10);
	return (0);
}
