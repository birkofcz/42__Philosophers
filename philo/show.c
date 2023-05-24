/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:19:43 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/24 14:42:11 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_forks_up(int philo_number, t_environment *env, pthread_mutex_t *forks) {
    int left_fork = philo_number;
    int right_fork = (philo_number + 1) % env->n_philo;

    if (left_fork > right_fork) {
        pthread_mutex_lock(forks[left_fork]);
        pthread_mutex_lock(forks[right_fork]);
    } else {
        pthread_mutex_lock(forks[right_fork]);
        pthread_mutex_lock(forks[left_fork]);
    }
}

void eat(int philosopher_number) {
    printf("Philosopher %d is eating.\n", philosopher_number);
    sleep(EAT_TIME);
}

void put_down_forks(int philosopher_number) {
    int left_fork = philosopher_number;
    int right_fork = (philosopher_number + 1) % NUM_PHILOSOPHERS;
    if (left_fork > right_fork) {
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
    } else {
        pthread_mutex_unlock(&forks[right_fork]);
        pthread_mutex_unlock(&forks[left_fork]);
    }
}








void	*ft_routine(void *num)
{
	int philo_number;

	philo_number = num;

	
}



void	ft_runtheshow(t_environment *env)
{
	pthread_t		philo[300];
	pthread_mutex_t	forks[300];
	int i;

	i = -1;
	while (++i < env->n_philo)
		pthread_create(&philo[i], NULL, ft_routine, (void *)i);
	i = -1;
	while (++i < env->n_forks)
		pthread_mutex_init(&forks[i], NULL);
}
