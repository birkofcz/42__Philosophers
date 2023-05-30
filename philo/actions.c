/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:18:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/30 12:09:05 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_philo **philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock((*philo)->mx_out);
	if ((*philo)->alive[0])
		printf("%-8lu %-3d  \033[30m\033[45mis sleeping\033[0m\n",
			ft_timesince((*philo)->t_born, now), (*philo)->id + 1);
	pthread_mutex_unlock((*philo)->mx_out);
	ft_startaction((*philo)->start_sleep);
	gettimeofday(&now, NULL);
	pthread_mutex_lock((*philo)->mx_out);
	if ((*philo)->alive[0])
		printf("%-8lu %-3d  \033[30m\033[46mis thinking\033[0m\n",
			ft_timesince((*philo)->t_born, now), (*philo)->id + 1);
	pthread_mutex_unlock((*philo)->mx_out);
}

void	ft_taken(t_philo **philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock((*philo)->mx_out);
	if ((*philo)->alive[0])
		printf("%-8lu %-3d \033[0;33m took a fork\033[0m\n",
			ft_timesince((*philo)->t_born, now), (*philo)->id + 1);
	pthread_mutex_unlock((*philo)->mx_out);
}

void	ft_take_forks(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->mutex_fork[(*philo)->id]);
	(*philo)->forks[(*philo)->id] = 0;
	ft_taken(philo);
	if ((*philo)->id == (*philo)->num_of_philos - 1)
	{
		pthread_mutex_lock(&(*philo)->mutex_fork[0]);
		(*philo)->forks[0] = 0;
		ft_taken(philo);
	}
	else
	{
		pthread_mutex_lock(&(*philo)->mutex_fork[(*philo)->id + 1]);
		(*philo)->forks[(*philo)->id + 1] = 0;
		ft_taken(philo);
	}
}

void	ft_put_forks(t_philo **philo)
{
	pthread_mutex_unlock(&(*philo)->mutex_fork[(*philo)->id]);
	(*philo)->forks[(*philo)->id] = 1;
	if ((*philo)->id == (*philo)->num_of_philos - 1)
	{
		pthread_mutex_unlock(&(*philo)->mutex_fork[0]);
		(*philo)->forks[0] = 1;
	}
	else
	{
		pthread_mutex_unlock(&(*philo)->mutex_fork[(*philo)->id + 1]);
		(*philo)->forks[(*philo)->id + 1] = 1;
	}
}

int	ft_eat(t_philo **philo)
{
	struct timeval	now;

	ft_take_forks(philo);
	if (!is_alive(philo))
		return (ft_put_forks(philo), 0);
	gettimeofday(&(*philo)->t_lastmeal, NULL);
	gettimeofday(&now, NULL);
	pthread_mutex_lock((*philo)->mx_out);
	if ((*philo)->alive[0])
		printf("%-8lu %-3d  \033[30m\033[42mis eating his spaghetti code\033[0m\n",
			ft_timesince((*philo)->t_born, now), (*philo)->id + 1);
	pthread_mutex_unlock((*philo)->mx_out);
	ft_startaction((*philo)->time_eat);
	ft_put_forks(philo);
	(*philo)->meals++;
	return (1);
}