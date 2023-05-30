/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:00:08 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/30 12:01:35 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_TIMESTAMP 
to get a timestamp without repeating the code over and over
*/

int	ft_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

unsigned long int	ft_timesince(struct timeval then, struct timeval now)
{
	unsigned long int	start;
	unsigned long int	end;

	start = (then.tv_sec * 1000) + (then.tv_usec / 1000);
	end = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (end - start);
}

void	ft_startaction(int duration)
{
	int	start;

	start = ft_timestamp();
	while ((ft_timestamp() - start) < duration)
		usleep(1);
}
