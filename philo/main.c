/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:26 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 13:59:11 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/* 
FT_EXIT - clean exit function, freeing stuff.
 */
void	ft_exit(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->n_philo)
	{
		pthread_mutex_destroy(&env->forks[i]);
		pthread_mutex_destroy(&env->philos[i].lock);
	}
	pthread_mutex_destroy(&env->write);
	pthread_mutex_destroy(&env->lock);
	if (env->threads)
		free(env->threads);
	if (env->forks)
		free(env->forks);
	if (env->philos)
		free(env->philos);
}

/* 
FT_ONEPHILO - process for one philosopher
 */
int	ft_onephilo(t_env *env)
{
	env->simulation_start = ft_gettime();
	if (pthread_create(&env->threads[0], NULL, &ft_routine, &env->philos[0]))
		return (ft_error(1, "Error creating thread"));
	pthread_detach(env->threads[0]);
	while (env->dead == 0)
		ft_usleep(0);
	ft_exit(env);
	return (0);
}

/* 
Starting point - does the basic argument error check, initializes and runs 
the show.
 */
int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 5 || ac > 6)
		return (ft_error(1, ft_truephilo()));
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200 || ft_atoi(av[2]) < 0
		|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (ft_error(1, ft_truephilo()));
	if (ft_arguments(ac, av, &env) != 0)
		return (1);
	if (ft_init(&env) != 0)
		return (1);
	if (env.n_philo == 1)
		return (ft_onephilo(&env));
	if (ft_thread_init(&env))
		return (1);
	ft_exit(&env);
	return (0);
}
