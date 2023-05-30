/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:26 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/30 12:04:34 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/* 
void	ft_philoborn(t_env *env, t_philo **philos,
						pthread_mutex_t **mx_fork)
{
	int				*forks;
	int				i;
	int				*alive;
	pthread_mutex_t	*mx_out;
	
	while (++i < env->n_philo)
	*philos = malloc((env->n_philo * sizeof(t_philo))
			+ env->n_philo * sizeof(int));
	*mx_fork = malloc(env->n_philo * sizeof(pthread_mutex_t));
	(*philos)[0].mutex_fork = *mx_fork;
	(*philos)[0].num_of_philos = env->n_philo;
	(*philos)[0].time_die = env->time_die;
	(*philos)[0].time_eat = env->time_eat;
	(*philos)[0].time_sleep = env->time_sleep;
	(*philos)[0].n_meals_opt = env->n_meals_opt;
	gettimeofday(&(*philos)[0].t_born, NULL);

	forks = malloc(env->n_philo * sizeof(int));
	alive = malloc(1 * sizeof(int));
	alive[0] = 1;
	i = 0;
	(*philos)[0].forks = forks;
	//(*platos)[0].snacks = 0;
	(*philos)[0].alive = alive;
	(*philos)[0].start_sleep = 1;
	mx_out = malloc(1 * sizeof(pthread_mutex_t));
	(*philos)[0].mx_out = mx_out;
	while (++i < (*philos)[0].num_of_philos)
	{
		init_others_others(platos, i);
		(*platos)[i].alive = alive;
		(*platos)[i].init_sleep = 1;
		(*platos)[i].snacks = 0;
		(*platos)[i].forks = forks;
		(*platos)[i].mx_vidle = *mx_vidle;
		(*platos)[i].mx_out = mx_out;
		gettimeofday(&(*platos)[i].t_created, NULL);
	}

} */

void	ft_init_philosopher(t_philo *philo, int id, t_env *env,
			pthread_mutex_t *mx_fork)
{
	philo->id = id;
	philo->time_die = env->time_die;
	philo->time_eat = env->time_eat;
	philo->time_sleep = env->time_sleep;
	philo->n_meals_opt = env->n_meals_opt;
	philo->num_of_philos = env->n_philo;
	philo->alive = malloc(sizeof(int));
	*(philo->alive) = 1;
	philo->start_sleep = 1;
	philo->forks = malloc(env->n_philo * sizeof(int));
	philo->mutex_fork = mx_fork;
	philo->meals = 0;
	gettimeofday(&(philo->t_born), NULL);
	gettimeofday(&(philo->t_lastmeal), NULL);
	pthread_mutex_init(philo->mutex_fork, NULL);
}

void	ft_philosborn(t_env *env, t_philo **philos,
		pthread_mutex_t **mx_fork)
{
	int				i;
	pthread_mutex_t	*mx_out;

	mx_out = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mx_out, NULL);
	*philos = malloc(env->n_philo * sizeof(t_philo));
	*mx_fork = malloc(env->n_philo * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < env->n_philo)
	{
		ft_init_philosopher(&((*philos)[i]), i, env, &((*mx_fork)[i]));
		(*philos)[i].mx_out = mx_out;
	}
}

int	main(int ac, char **av)
{
	t_env			env;
	t_philo			*philos;
	pthread_mutex_t	*mx_fork;
	int				i;

	if (ac < 5 || ac > 6)
		return (ft_error(1, ft_truephilo()));
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0)
		return (ft_error(1, ft_truephilo()));
	if (ft_arguments(ac, av, &env) != 0)
		return (1);
	ft_philosborn(&env, &philos, &mx_fork);
	i = -1;
	while (++i < env.n_philo)
	{
		philos[i].id = i;
		philos[i].forks[i] = 1;
		pthread_mutex_init(&mx_fork[i], NULL);
		pthread_create(&philos[i].thread, NULL, &ft_routine, &philos[i]);
	}
	i = -1;
	while (++i < env.n_philo)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&mx_fork[i]);
	}
	return (free(mx_fork), free(philos->forks),
		pthread_mutex_destroy(philos->mx_out),
		free(philos->alive), free(philos->mx_out), free(philos), 0);
}
