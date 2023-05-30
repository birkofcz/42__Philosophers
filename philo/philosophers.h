/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:36:04 by sbenes            #+#    #+#             */
/*   Updated: 2023/05/30 12:01:49 by sbenes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}	t_env;

typedef struct s_philosopher
{
	int				id;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_meals_opt;
	int				num_of_philos;
	int				*alive;
	int				start_sleep;
	int				*forks;
	int				meals;
	struct timeval	t_born;
	struct timeval	t_lastmeal;
	pthread_t		philosopher;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	*mx_out;
	pthread_t		thread;
}	t_philo;


/* init.c */
int					ft_arguments(int ac, char **av, t_env *env);
void				ft_cleaninit(t_env *env);
char				*ft_truephilo(void);

/* error.c */
int					ft_error(int errorcode, char *message);

/* utils.c - helper functions */
int					ft_atoi(const char *str);
void				ft_printenv(t_env *env);

/* utils_time.c - time measure utility functions*/
int					ft_timestamp(void);
unsigned long int	ft_timesince(struct timeval start, struct timeval now);
void				ft_startaction(int duration);

/* main.c*/
void				ft_init_philosopher(t_philo *philo, int id, t_env *env,
						pthread_mutex_t *mx_fork);
void				ft_philosborn(t_env *env, t_philo **philos,
						pthread_mutex_t **mx_fork);
/* actions.c */
void	ft_sleep(t_philo **philo);
void	ft_taken(t_philo **philo);
void	ft_take_forks(t_philo **philo);
void	ft_put_forks(t_philo **philo);
int	ft_eat(t_philo **philo);



/* routine.c */
void	alone(t_philo **philo);
void	odd_sleep(t_philo **philo);
int		is_alive(t_philo **philo);
void	*ft_routine(void *data);

#endif