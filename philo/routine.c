/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/30 12:04:15 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	alone(t_philo **philo)
{
	ft_startaction((*philo)->time_die);
	printf("%-8d %-4s %-5s\n", (*philo)->time_die, "1",
		"\033[1;31mhas died\033[0m");
	free((*philo)->mutex_fork);
	free((*philo)->mx_out);
	free((*philo)->alive);
	free((*philo)->forks);
	free(*philo);
	exit(0);
}

void	odd_sleep(t_philo **philo)
{
	struct timeval	now;

	if ((*philo)->id % 2 == 0 && (*philo)->start_sleep)
	{
		gettimeofday(&now, NULL);
		pthread_mutex_lock((*philo)->mx_out);
		if ((*philo)->alive[0])
			printf("%-8lu %-3d  \033[30m\033[45mis sleeping\033[0m\n",
				ft_timesince((*philo)->t_born, now), (*philo)->id + 1);
		pthread_mutex_unlock((*philo)->mx_out);
		ft_startaction((*philo)->time_sleep);
		(*philo)->start_sleep = 0;
		gettimeofday(&now, NULL);
		pthread_mutex_lock((*philo)->mx_out);
		if ((*philo)->alive[0])
			printf("%-8lu %-3d  \033[30m\033[46mis thinking\033[0m\n",
				ft_timesince((*philo)->t_born, now), (*philo)->id + 1);
		pthread_mutex_unlock((*philo)->mx_out);
	}
}

int	is_alive(t_philo **philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (!(*philo)->alive[0])
		return (0);
	if (ft_timesince((*philo)->t_lastmeal, now) > (unsigned)(*philo)->time_die)
	{
		pthread_mutex_lock((*philo)->mx_out);
		if ((*philo)->alive[0])
		{
			(*philo)->alive[0] = 0;
			printf("%-8lu %-3d  \033[1;31mhas died\033[0m\n",
				ft_timesince((*philo)->t_born, now), (*philo)->id + 1);
		}
		pthread_mutex_unlock((*philo)->mx_out);
		return (0);
	}
	return (1);
}

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	gettimeofday(&(*philo).t_lastmeal, NULL);
	while (philo->alive[0])
	{
		odd_sleep(&philo);
		if (!ft_eat(&philo))
			return (NULL);
		if (philo->meals == philo->n_meals_opt)
			return (NULL);
		ft_sleep(&philo);
	}
	return (NULL);
}
