/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:19:43 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/26 14:53:02 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* Prototype with philos reporting  */
/*
void *ft_routine(void *num)
{
    int philo_number = *(int *)num + 1;
    printf("Hello from philo %d\n", philo_number);
    sleep(2);
    printf("Bye from philo %d\n", philo_number);
	free(num);
    return NULL;
}

void ft_runtheshow(t_environment *env)
{
	pthread_t	*philos;
	int			i;

	philos = malloc(env->n_philo * sizeof(pthread_t));
    i = -1;
    while (++i < env->n_philo)
    {
        int *philo_number = malloc(sizeof(int)); // Allocate memory for each thread's argument
        *philo_number = i; // Store the thread number

        pthread_create(&philos[i], NULL, &ft_routine, philo_number);
    }

    i = -1;
    while (++i < env->n_philo)
	{
        pthread_join(philos[i], NULL);
	}
	free(philos);
}
*/


void	*ft_routine(void *arg)
{
	t_environment	*env;
	int				philo_num;

	env = (t_environment *)arg;
	philo_num = *(env->n_thread) + 1;
	printf("Hello from philo %d\n", philo_num);
	sleep(2);
	printf("Bye from philo %d\n", philo_num);
	return (NULL);
}


void	ft_runtheshow(t_environment *env)
{
	pthread_t		*philos;
	t_environment	*philos_env;
	int				i;

	philos = malloc(env->n_philo * sizeof(pthread_t));
	philos_env = malloc(env->n_philo * sizeof(t_environment));
	i = -1;
    while (++i < env->n_philo)
    {
        philos_env[i] = *env; // Copy the environment data to each thread's environment
        philos_env[i].n_thread = malloc(sizeof(int)); // Allocate memory for each thread's n_thread
        *(philos_env[i].n_thread) = i; // Assign the unique number to each thread
        pthread_create(&philos[i], NULL, &ft_routine, &philos_env[i]);
    }

    // Wait for the specified number of meals or indefinitely if n_meals_opt is 0
	i = -1;
    while (++i < env->n_philo)
    {
        pthread_join(philos[i], NULL);
        free(philos_env[i].n_thread); // Free the allocated memory for each thread's n_thread
    }

    free(philos);
    free(philos_env);
}


/* =================== Working version of philos eating... */

/* void grab_forks(t_environment *env, int philo_number)
{
    int left_fork = philo_number; // Fork on the left side of the philosopher
    int right_fork = (philo_number + 1) % env->n_philo; // Fork on the right side of the philosopher

    // Acquire the forks based on resource hierarchy
    if (left_fork < right_fork)
    {
        pthread_mutex_lock(&env->forks[left_fork]);
        pthread_mutex_lock(&env->forks[right_fork]);
    }
    else
    {
        pthread_mutex_lock(&env->forks[right_fork]);
        pthread_mutex_lock(&env->forks[left_fork]);
    }
}

void release_forks(t_environment *env, int philo_number)
{
    int left_fork = philo_number; // Fork on the left side of the philosopher
    int right_fork = (philo_number + 1) % env->n_philo; // Fork on the right side of the philosopher

    // Release the forks
    pthread_mutex_unlock(&env->forks[left_fork]);
    pthread_mutex_unlock(&env->forks[right_fork]);
}

void *ft_routine(void *arg)
{
    t_environment *env = (t_environment *)arg;
    int philo_number = *(env->n_thread) + 1; // Increment the thread number by 1
    int meals_eaten = 0;

    while (meals_eaten < env->n_meals_opt || env->n_meals_opt == 0)
    {
        printf("Philosopher %d is thinking\n", philo_number);
        usleep(env->time_sleep);

        printf("Philosopher %d is hungry\n", philo_number);
        grab_forks(env, *(env->n_thread));
        printf("Philosopher %d is eating\n", philo_number);
        usleep(env->time_eat);
        release_forks(env, *(env->n_thread));

        meals_eaten++;
    }

    return NULL;
}

void ft_runtheshow(t_environment *env)
{
    int n_philo = env->n_philo;

    pthread_t *philos = malloc(n_philo * sizeof(pthread_t));
    t_environment *philos_env = malloc(n_philo * sizeof(t_environment));

    int i;
    for (i = 0; i < n_philo; i++)
    {
        philos_env[i] = *env; // Copy the environment data to each thread's environment
        philos_env[i].n_thread = malloc(sizeof(int)); // Allocate memory for each thread's n_thread
        *(philos_env[i].n_thread) = i; // Assign the unique number to each thread
        pthread_create(&philos[i], NULL, &ft_routine, &philos_env[i]);
    }

    // Wait for the specified number of meals or indefinitely if n_meals_opt is 0
    for (i = 0; i < n_philo; i++)
    {
        pthread_join(philos[i], NULL);
        free(philos_env[i].n_thread); // Free the allocated memory for each thread's n_thread
    }

    free(philos);
    free(philos_env);
}
 */

