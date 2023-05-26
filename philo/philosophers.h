/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:36:04 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/26 13:56:59 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* You have to write a program for the mandatory part and another one for the bonus part
(if you decide to do the bonus part). They both have to comply with the following rules:
• Global variables are forbidden!
• Your(s) program(s) should take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]

◦ number_of_philosophers: The number of philosophers and also the number
of forks.
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
• Each philosopher has a number ranging from 1 to number_of_philosophers.
• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.
 */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

/* Struct with argument values - setting the environment */

typedef struct s_environment
{
	int		n_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		n_meals_opt;
	int		n_forks;
	int		*n_thread;
	pthread_mutex_t	*forks;
}	t_environment;


typedef struct s_table
{
	pthread_mutex_t	forks[201];
}	t_table;

/* init.c */
int		ft_arguments(int ac, char **av, t_environment *env);
void	ft_cleaninit(t_environment *env);
char	*ft_truephilo(void);


/* error.c */
int		ft_error(int errorcode, char *message);

/* helper_f.c - helper functions */
int		ft_atoi(const char *str);
void	ft_printenv(t_environment *env);

/* show.c */
void	ft_runtheshow(t_environment *env);
void	*ft_routine(void *num);



#endif