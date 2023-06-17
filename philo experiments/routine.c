/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 11:52:28 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_monitor(void *env_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) env_pointer;
	while (philo->env->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->env->finished_eating >= philo->env->n_philo)
			philo->env->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*ft_supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->env->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (ft_gettime() >= philo->time_to_die && philo->eating == 0)
			ft_message(DIED, philo);
		if (philo->meals_eaten == philo->env->meals_to_eat)
		{
			pthread_mutex_lock(&philo->env->lock);
			philo->env->finished_eating++;
			philo->meals_eaten++;
			pthread_mutex_unlock(&philo->env->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*ft_routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->env->time_die + ft_gettime();
	if (pthread_create(&philo->t1, NULL, &ft_supervisor, (void *)philo))
		return ((void *)1);
	while (philo->env->dead == 0)
	{
		ft_eat(philo);
		ft_message(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	ft_thread_init(t_env *env)
{
	int			i;
	pthread_t	t0;

	i = -1;
	env->simulation_start = ft_gettime();
	if (env->meals_to_eat > 0)
	{
		if (pthread_create(&t0, NULL, &ft_monitor, &env->philos[0]))
			return (ft_error(1, "Error creating threads", env));
	}
	while (++i < env->n_philo)
	{
		if (pthread_create(&env->tid[i], NULL, &ft_routine, &env->philos[i]))
			return (ft_error(1, "Error creating threads", env));
		ft_usleep(1);
	}
	i = -1;
	while (++i < env->n_philo)
	{
		if (pthread_join(env->tid[i], NULL))
			return (ft_error(1, "Error joining threads", env));
	}
	return (0);
}
