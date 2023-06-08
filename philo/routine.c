/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/08 13:04:45 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *env_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) env_pointer;
	pthread_mutex_lock(&philo->env->write);
	//printf("env val: %d", philo->env->dead);
	pthread_mutex_unlock(&philo->env->write);
	while (philo->env->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->env->finished >= philo->env->n_philo)
			philo->env->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->env->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			messages(DIED, philo);
		if (philo->meals_eaten == philo->env->meals_to_eat)
		{
			pthread_mutex_lock(&philo->env->lock);
			philo->env->finished++;
			philo->eat_cont++;
			pthread_mutex_unlock(&philo->env->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->env->death_time + get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->env->dead == 0)
	{
		eat(philo);
		messages(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}



int	thread_init(t_env *env)
{
	int			i;
	pthread_t	t0;

	i = -1;
	env->time_born = ft_gettime();
	if (env->meals_to_eat > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &env->philos[0]))
			return (error(TH_ERR, env));
	}
	while (++i < env->n_philo)
	{
		if (pthread_create(&env->tid[i], NULL, &routine, &env->philos[i]))
			return (error(TH_ERR, env));
		ft_usleep(1);
	}
	i = -1;
	while (++i < env->n_philo)
	{
		if (pthread_join(env->tid[i], NULL))
			return (error(JOIN_ERR, env));
	}
	return (0);
}