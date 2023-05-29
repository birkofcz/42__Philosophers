/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:26 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/29 14:12:24 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philoborn(t_env *env, t_philo **philos,
						pthread_mutex_t **mx_fork)
{
	int				*forks;
	int				i;
	int				*alive;
	pthread_mutex_t	*mx_out;
	
	/* Here I can do init of all philos at once - base od phelbrants code, which is more structured */
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


}

int	main(int ac, char **av)
{
	t_env			env;
	t_philo			*philos;
	pthread_mutex_t	*mx_fork;

	if (ac < 5 || ac > 6)
		return (ft_error(1, ft_truephilo()));
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0)
		return (ft_error(1, ft_truephilo()));
	if (ft_arguments(ac, av, &env) != 0)
		return (1);
	ft_philoborn(&env, &philos, &mx_fork)

	return (0);
}
