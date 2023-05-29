/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:19:43 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/29 11:02:50 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* void	*ft_routine(void *arg)
{
	int	philo_num;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	philo_num = *(int *)arg + 1;
	printf("%ld Hello from philo %d\n", (long int)tv.tv_usec, philo_num);
	sleep(2);
	gettimeofday(&tv, NULL);
	printf("%ld Bye from philo %d\n", ((long int)tv.tv_usec * 1000) + (tv.tv_sec / 1000), philo_num);
	return (NULL);
} */

void *ft_routine(void *arg)
{
    int philo_num;
    struct timeval start_time, end_time;

    gettimeofday(&start_time, NULL);
    philo_num = *(int *)arg + 1;
    printf("Hello from philo %d\n", philo_num);
    usleep(200);
    gettimeofday(&end_time, NULL);

    long int start_ms = start_time.tv_sec * 1000000 + start_time.tv_usec;
    long int end_ms = end_time.tv_sec * 1000000 + end_time.tv_usec;
    long int runtime_ms = end_ms - start_ms;

    printf("Runtime of philo %d: %ld microseconds\n", philo_num, runtime_ms);

    return NULL;
}

/* void	ft_runtheshow(t_environment *env)
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
 */

/* FT_RUNTHESHOW - creates philosophers as threads, giving them unique number */
void	ft_runtheshow(t_environment *env)
{
	pthread_t	*philos;
	int			i;
	int			*philo_num;

	philos = malloc(env->n_philo * sizeof(pthread_t));
	i = -1;
	while (++i < env->n_philo)
	{
		philo_num = malloc(sizeof(int));
		*philo_num = i;
		pthread_create(&philos[i], NULL, &ft_routine, philo_num);
	}
	i = -1;
	while (++i < env->n_philo)
		pthread_join(philos[i], NULL);
	free(philos);
	free(philo_num);
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

