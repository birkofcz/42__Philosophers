/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:00:08 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/29 13:06:17 by sbenes           ###   ########.fr       */
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

void	ft_starttime(int duration)
{
	int	start;

	start = ft_timestamp();
	while ((ft_timestamp() - start) < duration)
		usleep(1);
}
