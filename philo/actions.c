/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:18:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/12 10:51:23 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	messages(char *str, t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->env->write);
	time = ft_gettime() - philo->env->time_born;
	if (ft_strcmp("died", str) == 0 && philo->env->dead == 0)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->env->dead = 1;
	}
	if (!philo->env->dead)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->env->write);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	messages("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	messages("has taken a fork", philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	messages("is sleeping", philo);
	ft_usleep(philo->env->time_sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = ft_gettime() + philo->env->time_die;
	messages("is eating", philo);
	philo->meals_eaten++;
	ft_usleep(philo->env->time_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}