/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:18:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 13:34:41 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_MESSAGE - writes various messages to the screen, protecting the action 
with write mutex. Adding strings to the timestamp.
 */
void	ft_message(char *str, t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->env->write);
	time = ft_gettime() - philo->env->simulation_start;
	if (ft_strncmp(DIED, str, ft_strlen(DIED)) == 0 && philo->env->dead == 0)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->env->dead = 1;
	}
	if (!philo->env->dead)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->env->write);
}

/* 
FT_FORKS_UP - picking up the forks - protected by mutex as shared resource.
 */
void	ft_forks_up(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_message(FORK, philo);
	pthread_mutex_lock(philo->l_fork);
	ft_message(FORK, philo);
}

/* 
FT_FORKS_UP - putting down the forks, unlocking them, going to sleep after
a good meal.
 */
void	ft_forks_down(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ft_message(SLEEPING, philo);
	ft_usleep(philo->env->time_sleep);
}

/* 
FT_EAT - basic routine for every philo. Trying to put the forks up, 
when succesfull, updating time to die, annnoucing eating, incrementing meals 
eaten, usleep for time_eat, putting down the forks.
 */
void	ft_eat(t_philo *philo)
{
	ft_forks_up(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = ft_gettime() + philo->env->time_die;
	ft_message(EATING, philo);
	philo->meals_eaten++;
	ft_usleep(philo->env->time_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	ft_forks_down(philo);
}
