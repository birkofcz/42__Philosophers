/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:03:17 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/12 09:50:48 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* void	*ft_routine(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	printf("Hello from philo %d\n", philos->id);
	sleep(1);
	printf("Bye from philo %d\n", philos->id);
	return (NULL);
}

void	ft_initphilos(t_env *env)
{
	int		id;

	id = 0;
	env->philos = malloc(env->n_philo * sizeof(t_philo));
	if (!env->philos)
	{
		ft_error(1, "Failed to allocate memory");
		return ;
	}
	while (id++ < env->n_philo)
	{
		env->philos[id].id = id;
		pthread_create(&env->philos[id].t1, NULL, &ft_routine,
			&env->philos[id]);
	}
	while (id-- != 0)
		pthread_join(env->philos[id].t1, NULL);
	free(env->philos);
} */

int	ft_init_arrays(t_env *env)
{
	env->tid = malloc(sizeof(pthread_t) * env->n_philo);
	if (!env->tid)
		return (ft_error(1, "Error allocating array memory"));
	env->forks = malloc(sizeof(pthread_mutex_t) * env->n_philo);
	if (!env->forks)
		return (ft_error(1, "Error allocating array memory"));
	env->philos = malloc(sizeof(t_philo) * env->n_philo);
	if (!env->philos)
		return (ft_error(1, "Error allocating array memory"));
	return (0);
}

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
		env->philos[i].status = 0;
		pthread_mutex_init(&env->philos[i].lock, NULL);
		i++;
	}
}

int	ft_init(t_env *env)
{
	if (ft_init_arrays(env))
		return (1);
	if (ft_init_forks(env))
		return (1);
	ft_init_philos(env);
	return (0);
}
