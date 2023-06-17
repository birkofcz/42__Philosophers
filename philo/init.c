/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:03:17 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 14:00:06 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
FT_INIT_ARRAYS - initializes arrays in the environment structure,
for threads, forks and philosopher structures.
 */
int	ft_init_arrays(t_env *env)
{
	env->threads = malloc(sizeof(pthread_t) * env->n_philo);
	if (!env->threads)
		return (ft_error(1, "Error allocating array memory"));
	env->forks = malloc(sizeof(pthread_mutex_t) * env->n_philo);
	if (!env->forks)
		return (ft_error(1, "Error allocating array memory"));
	env->philos = malloc(sizeof(t_philo) * env->n_philo);
	if (!env->philos)
		return (ft_error(1, "Error allocating array memory"));
	return (0);
}

/* 
FT_INIT_FORKS - initializes forks as a shared resource for philosophers.
For the first philosopher(env->philos[0]), it assigns the first 
fork (env->forks[0]) as the left fork and the last fork 
(env->forks[env->n_philo - 1]) as the right fork. This is because 
the philosophers are sitting at a circular table, so the first 
philosopher is next to the last one. Then assigns the rest - left fork
is at the same index as philosopher, right fork is at the next one.
 */
int	ft_init_forks(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->n_philo)
		pthread_mutex_init(&env->forks[i], NULL);
	i = 0;
	env->philos[0].l_fork = &env->forks[0];
	env->philos[0].r_fork = &env->forks[env->n_philo - 1];
	i = 1;
	while (i < env->n_philo)
	{
		env->philos[i].l_fork = &env->forks[i];
		env->philos[i].r_fork = &env->forks[i - 1];
		i++;
	}
	return (0);
}

/* 
FT_INIT_PHILOS - initializes each philo with unique ID and basic
information from environment.
 */
void	ft_init_philos(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_philo)
	{
		env->philos[i].env = env;
		env->philos[i].id = i + 1;
		env->philos[i].time_to_die = env->time_die;
		env->philos[i].meals_eaten = 0;
		env->philos[i].eating = 0;
		pthread_mutex_init(&env->philos[i].lock, NULL);
		i++;
	}
}

/* 
FT_INIT - initialize crossroad for initializing arrays and philos.
 */
int	ft_init(t_env *env)
{
	if (ft_init_arrays(env))
		return (1);
	if (ft_init_forks(env))
		return (1);
	ft_init_philos(env);
	return (0);
}
