/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:29:01 by sbenes            #+#    #+#             */
/*   Updated: 2023/06/17 14:02:55 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/* 
FT_WAITER - The waiter is initialized to the whole environment in case 
there is a number of meals each philosopher must eat (optional param).
Waiter checks how many philos have finished eating, protecting with mutex.
 */
void	*ft_waiter(void *env_pointer)
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

/* 
FT_SUPERVISOR - created for every philo.
Check if the philosopher has eaten before the time_death limit. 
If philosophers starves to death, the function reports it. Also taking care 
about meals eaten counter. Protecting the incrementations and actions
with mutexes.
 */
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

/* 
FT_ROUTINE - basic routine for every philosopher. Initilizes time to die.
Creates the supervisor. Until there is a dead flag on, philosophers follows 
the routine, eating, sleeping, thinking.
 */
void	*ft_routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->env->time_die + ft_gettime();
	if (pthread_create(&philo->supervisor, NULL, &ft_supervisor, (void *)philo))
		return ((void *)1);
	while (philo->env->dead == 0)
	{
		ft_eat(philo);
		ft_message(THINKING, philo);
	}
	if (pthread_join(philo->supervisor, NULL))
		return ((void *)1);
	return ((void *)0);
}

/* 
FT_THREAD_INIT - initializes the philosophers and waiter threads.
Waits for join.
 */
int	ft_thread_init(t_env *env)
{
	int			i;
	pthread_t	t0;

	i = -1;
	env->simulation_start = ft_gettime();
	if (env->meals_to_eat > 0)
	{
		if (pthread_create(&t0, NULL, &ft_waiter, &env->philos[0]))
			return (ft_error(1, "Error creating threads"));
	}
	while (++i < env->n_philo)
	{
		if (pthread_create(&env->threads[i], NULL, &ft_routine,
				&env->philos[i]))
			return (ft_error(1, "Error creating threads"));
		ft_usleep(1);
	}
	i = -1;
	while (++i < env->n_philo)
	{
		if (pthread_join(env->threads[i], NULL))
			return (ft_error(1, "Error joining threads"));
	}
	return (0);
}
